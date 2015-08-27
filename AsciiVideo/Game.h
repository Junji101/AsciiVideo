
#ifndef __GAME_H
#define __GAME_H

#include "VideoProcessor.h"
#include "ImageProcessor.h"

class GameData
{
	std::string formatInt(int i);
	std::string inputFile(std::string num, std::string format);
	std::string outputFile(std::string num);
	std::string pyFile;
	bool endOfFiles;
	int currentFile;

public:
	int GetInput();
	void Initialize();
	void ProcessFiles(VideoProcessor *video, ImageProcessor *image);
	void ProcessImages(VideoProcessor *video, ImageProcessor *image,cimg_library::CImgList<unsigned char> imageList);
	void DisplayFiles();

};

extern GameData game;




#endif