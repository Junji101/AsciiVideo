
#ifndef __VIDEOPROCESSOR_H
#define __VIDEOPROCESSOR_H

class VideoProcessor
{
	CImgDisplay Display;
	CImgList<unsigned char> Video;
	string fileName();
public:
	void updateDisplay(CImg<unsigned char> Image);
	void renderVideo();
	void loadVideo();

};

extern VideoProcessor video;

#endif