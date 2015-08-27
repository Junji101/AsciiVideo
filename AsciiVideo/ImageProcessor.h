

#ifndef __IMAGEPROCESSOR_H
#define __IMAGEPROCESSOR_H

#define fileNum 14

class ImageProcessor
{
	int fileData[fileNum];

	void charData(int* cBox);
	char compare(int Brightness);
	std::string imageFormat;
	std::string asciiFolder;
	cimg_library::CImg<unsigned char> currentImage;
public:
	void Initialize();
	void processPicture(std::string outputFile);

	void setImage(std::string inputFile);
	void setImage(cimg_library::CImg<unsigned char> inputImage);
	cimg_library::CImg<unsigned char> getImage();
	std::string getImageFormat();

};

extern ImageProcessor image;


#endif