#include <string>
#include <iostream>
#include <fstream>
#include "CImg.h"
#include "ImageProcessor.h"
using namespace std;
using namespace cimg_library;

#define HEIGHT  700
#define WIDTH  700
#define XBOX 5
#define YBOX 5
#define MAXBRIGHT 138975
//#define MAXCHARACTERS 26624
//#define MAXFRAMES 900
#define RESIZE false

//char imageFile[] = {"duck.bmp"};
//char outFile[] = {"example.txt"};
char fileNames[fileNum][20] = {"`.bmp","~.bmp","^.bmp","!.bmp","Colon.bmp",";.bmp","(.bmp","Asterisk.bmp","+.bmp","].bmp","$.bmp","O.bmp","#.bmp", "@.bmp"};
char letters[fileNum] = {'`','~','^','!',':',';','(','*','+',']','$','O','#','@'};
int cData[HEIGHT][WIDTH];

/**
 * Stores values of brightness in an array
 * @param int *cBox: pointer of where to store values
 * @return: The average brightness of Characters
 */
void ImageProcessor::charData(int *cBox){
	for (int k = 0; k < fileNum; k++){
		string cFile = asciiFolder + fileNames[k];
		CImg<unsigned char> image(cFile.c_str());
		int charBox[7][10];
		int testBox = 0;
		int filepix = 0;
		for (int x = 0; x < image.width(); x++)
		{		//creates a 2d array of character with pixels being 1 and no pixels being 0
			for(int y = 0; y < image.height(); y++)
			{
				if (image(x,y,0,1) < 250)
				{
					charBox[x][y] = 1;
					filepix++;
				}else
				{
					charBox[x][y] = 0;
				}

			}
			
		}
		//## Giving the value of cBox to compare with brightness later. ###
		cBox[k] = MAXBRIGHT - MAXBRIGHT*((float) filepix/25);
		cout << "Current file: " << fileNames[k] << " Pixels(file): "<< filepix << " With brightness: "<< cBox[k] << endl;
	}
}

/**
 * Tries to return closest match to a Char given Brightness
 * @param Brightness: The brightness given
 * @return char: A character representing the brightness
 */
char ImageProcessor::compare(int Brightness){
	for(int  k = 0; k < fileNum; k++)
	{
		if(fileData[k] <= Brightness)
		{
			return letters[k];
		}
	}
	return '.';
}


void ImageProcessor::Initialize()
{
	asciiFolder = "Ascii/";
	///// Load character Data ///////
	int* filePnt = &fileData[0];
	charData(filePnt);
	///// Format of images ////////
	imageFormat = ".bmp";
}

/**
 * @return imageFormat: returns type of images we are using
 */
string ImageProcessor::getImageFormat()
{
	return imageFormat;
}

void ImageProcessor::setImage(string inputFile)
{
	currentImage.load(inputFile.c_str());
}

void ImageProcessor::setImage(CImg<unsigned char> inputImage)
{
	currentImage = inputImage;
}

CImg<unsigned char> ImageProcessor::getImage()
{
	return currentImage;
}



/**
 * Processes an Image and makes it into an ascii file (txt file)
 * @param string outPutFile: What to name new file
 * @param CImg newImage: image to be used for processing
 */
void ImageProcessor::processPicture(string outputFile){
	ofstream myfile;
	myfile.open(outputFile);
	myfile.clear();
	CImg<unsigned char> image(currentImage);

	if (RESIZE)
	{
		while (image.height()*image.width()/(XBOX*YBOX) > HEIGHT*WIDTH)
		{
			image.resize_halfXY();
		}
	}

	cout << " New Height: " << image._height << " New Width: " << image._width << endl;
	int newWidth = image._width;
	int newHieght = image._height;

	cimg_forXY(image,x,y)
	{
		int Red =  image(x,y,0,0)*650;
		int Green = image(x,y,0,1)*510;
		int Blue = image(x,y,0,2)*475;
		int brightness = (Red+Green+Blue)/3;
		cData[x][y] = brightness;
	}


	for (int i = 0 ; i < newHieght-YBOX; i+=YBOX)
	{
		for (int j = 0; j < newWidth-XBOX;j+=XBOX)
		{
			int currentBox[XBOX][YBOX]; //Sets currentBox to the size of the XBOX and YBOX
			int sum = 0;
			for (int k = 0; k < XBOX; k++)
			{ //makes currentBox[][] = from current cData[][] section
				for (int m = 0; m < YBOX; m++)
				{
					if (cData[j+k][i+m] < 0)
					{
						currentBox[k][m] = 0;
					}
					currentBox[k][m] = cData[j+k][i+m];
					sum += currentBox[k][m];
				}
			}
			int avgbright = sum/(XBOX*YBOX) - 1;
			myfile << compare(avgbright);		
		}
		myfile << endl;
	}
	myfile.close();
}
