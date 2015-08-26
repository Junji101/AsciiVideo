

#ifndef __IMAGEPROCESSOR_H
#define __IMAGEPROCESSOR_H

#define fileNum 14

class ImageProcessor
{
	int fileData[fileNum];

	void charData(int* cBox);
	char compare(int Brightness);
	string imageFormat;
	CImg<unsigned char> currentImage;
public:
	void Initialize();
	void processPicture(string outputFile);

	void setImage(string inputFile);
	CImg<unsigned char> getImage();
	string getImageFormat();
	//void processFiles();	/* Possibly for later use */

};

extern ImageProcessor image;


#endif