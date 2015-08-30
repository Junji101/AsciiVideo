#include <iostream>
#include <string>
//#include <opencv2\core.hpp>
//#include <opencv2\video.hpp>
#include "CImg.h"
#include "VideoProcessor.h"
using namespace std;
using namespace cimg_library;




string VideoProcessor::fileName()
{
	cout << "Name of file: (With extension)" << endl;
	string s;
	cin.ignore();
	getline(cin,s,'\n');
	cout << "String recieved "<< s << endl;
	return s;
}

void VideoProcessor::renderVideo()
{

	string str = "ffmpeg -i \"" + string(fileName()) +"\" -r 1 -f image2 input/%3d.bmp";
	cout << str;
	int i = system (str.c_str());
}

void VideoProcessor::loadVideo(int start, int end)
{
	cout << "This may have not loaded" << endl;
	Video.load_video(fileName().c_str(),start, end, 1);
	cout << "Video Size: " << Video.size() << endl;
}

cimg_library::CImgList<unsigned char> VideoProcessor::getVideo()
{
	return Video;
}

int VideoProcessor::getVideoFrames()
{
	return Video.width();
}

void VideoProcessor::startDisplay()
{
	Display.show();
}

void VideoProcessor::updateDisplay(CImg<unsigned char> Image)
{
	Display.display(Image);

}