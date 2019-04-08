#ifndef PPM_H
#define PPM_H

#include "RawImage.hpp"

class Ppm
{
	unsigned int _width;
	unsigned int _height;
	unsigned int _maxVal;

	uint8_t * _redChannel;
	uint8_t * _greenChannel1;
	uint8_t * _greenChannel2;
	uint8_t * _blueChannel;

	uint8_t * _colorImage;

public:
	Ppm();

	explicit Ppm(RawImage &img);

	~Ppm();

	void WriteImageUtil(const std::string imgBasePath);
	void WriteChannels(uint8_t * channel , const std::string filename);
	void WriteColorImage(const std::string filename);
};

#endif