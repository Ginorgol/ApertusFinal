#ifndef DEBAYER
#define DEBAYER

#include "RawImage.hpp"

class Debayer
{
	unsigned int _height;
	unsigned int _width;

	uint8_t * _red;
	uint8_t * _green;
	uint8_t * _blue;

	uint8_t * _colorImage;

public:
	Debayer();

	explicit Debayer(RawImage &img);

	~Debayer();

	void DebayerUtil();
	void BilinearInterpolateGreen();
	void BilinearInterpolateRed();
	void BilinearInterpolateBlue();
	void DemosaicBorders(uint8_t *channel);
	void FillColorImage();
};

#endif