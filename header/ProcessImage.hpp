#ifndef PROCESS_IMAGE_H
#define PROCESS_IMAGE_H

#include "RawImage.hpp"

class ProcessImage
{	
	unsigned int _height;
	unsigned int _width;
	unsigned int _channelPatchSize;

	uint8_t * _senselDump;
	uint8_t * _redChannel;
	uint8_t * _greenChannel1;
	uint8_t * _greenChannel2;
	uint8_t * _blueChannel;

	uint8_t * _colorImage;

public:
	ProcessImage();

	explicit ProcessImage(RawImage &img);

	~ProcessImage();

	void SeperateChannels();
	void DisplayIntensityProcess();
	void DisplayChannelIntensity(uint8_t * channel, const char * channelName);
};

#endif
