#include "RawImage.hpp"

RawImage::RawImage() : 
	_height(3072),
	_width(4096),
	_senselDump(nullptr),
	_redChannel(nullptr), 
	_greenChannel1(nullptr),
	_greenChannel2(nullptr), 
	_blueChannel(nullptr), 
	_colorImage(nullptr),
	_colorImageRed(nullptr),
	_colorImageGreen(nullptr),
	_colorImageBlue(nullptr)
{
}

RawImage::RawImage(const char *inputFileName,unsigned int width, unsigned int height)
{
	_width = width;
	_height = height;
	_bufferSize = _width * _height * 3 / 2;

	_rawInput.open(inputFileName, std::ios::binary);
	if(!_rawInput)
	{
		std::cerr << "Error: Cannot open input file .... exiting " << std::endl;
		exit(1);
	}
	_senselDump = new uint8_t[_bufferSize];
	_rawInput.read(reinterpret_cast<char *>(_senselDump),_bufferSize);

	_redChannel = new uint8_t[_width * _height / 4];
	_greenChannel1 = new uint8_t[_width * _height / 4];
	_greenChannel2 = new uint8_t[_width * _height / 4];
	_blueChannel = new uint8_t[_width * _height / 4];

	_colorImage = new uint8_t[_width * _height * 3];
	_colorImageRed = new uint8_t[_width * _height];
	_colorImageGreen = new uint8_t[_width * _height];
	_colorImageBlue = new uint8_t[_width * _height];
}

unsigned int RawImage::GetHeight()
{
	return _height;
}

unsigned int RawImage::GetWidth()
{
	return _width;
}

unsigned int RawImage::GetBufferSize()
{
	return _bufferSize;
}

uint8_t * RawImage::GetRedChannel()
{
	return _redChannel;
}

uint8_t * RawImage::GetBlueChannel()
{
	return _blueChannel;
}

uint8_t * RawImage::GetGreenChannel1()
{
	return _greenChannel1;
}

uint8_t * RawImage::GetGreenChannel2()
{
	return _greenChannel2;
}

uint8_t * RawImage::GetSenselDump()
{
	return _senselDump;
}

uint8_t * RawImage::GetColorImage()
{
	return _colorImage;	
}

uint8_t * RawImage::GetColorImageRed()
{
	return _colorImageRed;
}
uint8_t * RawImage::GetColorImageGreen()
{
	return _colorImageGreen;
}
uint8_t * RawImage::GetColorImageBlue()
{
	return _colorImageBlue;
}

RawImage::~RawImage()
{
}