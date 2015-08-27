#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <stdio.h>
//#include <stdlib.h> 
//#include <exception>
//#include <MsXml.h>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

#include "Game.h"
#include "ImageProcessor.h"
#include "VideoProcessor.h"

#define VIDEO_RENDER false

ImageProcessor image;
VideoProcessor video;
GameData game;



int main(int argv, char *args[])
{
	ImageProcessor* passImage = &image;
	VideoProcessor* passVideo = &video;
	game.Initialize();
	image.Initialize();
	video.startDisplay();
	//Ask User
	switch(game.GetInput())
	{
	case(0):
		goto VideoProcess;
		break;
	case(1):
		goto ImageProcess;
		break;
	case(2):
		goto VideoPlayback;
		break;
	}
VideoProcess:
	//Video gets processed
	if(VIDEO_RENDER)
	{
		video.renderVideo();
	} else
	{
		video.loadVideo();
		system("Pause");
	}

ImageProcess:
	//Images from video get processed
	if(VIDEO_RENDER)
	{
		game.ProcessFiles(passVideo,passImage);
	} else
	{
		game.ProcessImages(passVideo, passImage,video.getVideo());
	}

VideoPlayback:
	//Video from Ascii Art gets played
	game.DisplayFiles();
}
