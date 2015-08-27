
#ifndef __VIDEOPROCESSOR_H
#define __VIDEOPROCESSOR_H

class VideoProcessor
{
	cimg_library::CImgDisplay Display;
	cimg_library::CImgList<unsigned char> Video;
	std::string fileName();
public:
	void startDisplay();
	void updateDisplay(cimg_library::CImg<unsigned char> Image);
	void shutdownDisplay();
	void renderVideo();
	void loadVideo();
	cimg_library::CImgList<unsigned char> getVideo();
	int getVideoFrames();

};

extern VideoProcessor video;

#endif