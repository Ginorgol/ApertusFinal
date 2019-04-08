#ifndef RAWIMAGE_H
#define RAWIMAGE_H

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>	

class RawImage
{	
	std::ifstream _rawInput;
	unsigned int _height;
	unsigned int _width;
	unsigned int _bufferSize;

	uint8_t * _senselDump;
	uint8_t * _redChannel;
	uint8_t * _greenChannel1;
	uint8_t * _greenChannel2;
	uint8_t * _blueChannel;

	uint8_t * _colorImage;
	uint8_t * _colorImageRed;
	uint8_t * _colorImageGreen;
	uint8_t * _colorImageBlue;


public:
	RawImage();
	RawImage(const char * inputFileName, unsigned int width, unsigned int height);

	~RawImage();

	unsigned int GetHeight();
	unsigned int GetWidth();
	unsigned int GetBufferSize();

	uint8_t * GetSenselDump();
	uint8_t * GetRedChannel();
	uint8_t * GetBlueChannel();
	uint8_t * GetGreenChannel1();
	uint8_t * GetGreenChannel2();
	
	uint8_t * GetColorImage();
	uint8_t * GetColorImageRed();
	uint8_t * GetColorImageGreen();
	uint8_t * GetColorImageBlue();
};

#endif