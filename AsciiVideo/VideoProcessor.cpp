#include "VideoProcessor.h"




string VideoProcessor::fileName()
{
	cout << "Name of file: (With extension)" << endl;
	string s;
	cin.ignore();
	getline(cin,s,'\n');
	cout << "String recieved "<< s << endl;
}

void VideoProcessor::renderVideo()
{

	string str = "ffmpeg -i \"" + string(s) +"\" -r 1 -f image2 input/image-%3d.bmp";
	cout << str;
	int i = system (str.c_str());
}

void VideoProcessor::loadVideo()
{
	cout << "I regret to tell you this doesn't work...lol..  Nah but really I'm sorry" << endl;
	Video.load_video(fileName().c_str());
}

void VideoProcessor::updateDisplay(CImg<unsigned char> Image)
{
	Display.assign(Image);

}