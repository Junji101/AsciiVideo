
#ifndef __GAME_H
#define __GAME_H

class GameData
{
	string formatInt(int i);
	string inputFile(string num, string format);
	string outputFile(string num);
	bool endOfFiles;
	int currentFile;

public:
	int GetInput();
	void Initialize();
	void ProcessFiles(VideoProcessor *video, ImageProcessor *image);

};

extern GameData game;




#endif