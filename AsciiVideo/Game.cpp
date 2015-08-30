#include <iostream>
#include <string>
#include "CImg.h"
#include "Game.h"
using namespace std;
FILE* file;

/**
 * Initialize certain variables
 */
void GameData::Initialize()
{
	endOfFiles = false;
	currentFile = 1;
	videoSize = 5;
	pyFile = "ascii-telnet-server.py";

}

/**
 * The name of currentFile
 * @param num: Number of file because they are numerically driven
 * @param format: Current format of files
 */
string GameData::inputFile(string num, string format)
{
	string temp = "input/" + num + format;
	return temp;
}

string GameData::outputFile(string num)
{
	string temp = "output/" + num + ".txt";
	return temp;
}
/**
 * Tranforms int to string
 * @param int i: An integer
 * @return string: Makes number into 000 format
 */
string GameData::formatInt(int i)
{
	if(i < 10){
		return "00" + to_string((_LONGLONG)i);
	}else if( i < 100){
		return "0" + to_string((_LONGLONG)i);
	} else	{
		return to_string((_LONGLONG)i);
	}

}

/**
 * Gets Input from User and Returns Value
 * @return ans: the state that the game should go in
 */
int GameData::GetInput()
{
	int ans;
	while((std::cout << "Render, Load, or Already processed? (0,1,2)" << std::endl) && (!(std::cin >> ans) || ans< 0 || ans > 3 ))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect Parameter" << " Try again:" << std::endl;
	}
	return ans;
}

void GameData::ProcessFiles(VideoProcessor *video, ImageProcessor *image)
{
	while(endOfFiles == false)
	{
		image->setImage(inputFile(formatInt(currentFile),image->getImageFormat()));
		video->updateDisplay(image->getImage());
		image->processPicture(outputFile(formatInt(currentFile)));
		
		if ((file = fopen(inputFile(formatInt(currentFile+1),image->getImageFormat()).c_str(),"r")) == NULL)
		{
			endOfFiles = true;
			break;
		}
		currentFile += 1;
	}
	return;
}

void GameData::ProcessImages(VideoProcessor *video, ImageProcessor *image)
{

	while (!endOfFiles)
	{
		video->loadVideo(currentFile, endFile);
		cimg_library::CImgList<unsigned char> imageList = video->getVideo();
		for (int i = 0; i < videoSize; i++)
		{
			if(imageList.at(i) == NULL)
			{
				endOfFiles = true;
				break;
			}
			image->setImage(imageList.at(i));
			video->updateDisplay(image->getImage());
			image->processPicture(outputFile(formatInt(currentFile)));

		}
		currentFile += videoSize;
	}
}

void GameData::DisplayFiles()
{
	string s = "py " + pyFile + " --standalone -f Output\\001.txt";
	system(s.c_str());
	system("Pause");
}
