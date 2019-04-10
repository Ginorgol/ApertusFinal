#include "Debayer.hpp"

Debayer::Debayer()
{
}
Debayer::Debayer(RawImage &img)
{
	_height = img.GetHeight();
	_width = img.GetWidth();
	_colorImage = img.GetColorImage();

	_red = img.GetColorImageRed();
	_green = img.GetColorImageGreen();
	_blue = img.GetColorImageBlue();

	uint8_t * redChannel = img.GetRedChannel();
	uint8_t * greenChannel1 = img.GetGreenChannel1();
	uint8_t * greenChannel2 = img.GetGreenChannel2();
	uint8_t * blueChannel = img.GetBlueChannel();

	unsigned int redOffset = 0;
	unsigned int greenOffset1 = 0;
	unsigned int greenOffset2 = 0;
	unsigned int blueOffset = 0;
	//Fill the channels with known value
	for (unsigned int row = 0 ; row < _height ; ++row)
	{
		for (unsigned int col = 0 ; col < _width ; ++col)
		{
			if(row % 2 == 0 && col % 2 == 0)
			{
				_red[_width * row + col] = redChannel[redOffset];
				++redOffset;
			}
			if(row % 2 == 0 && col % 2 != 0)
			{
				_green[_width * row + col] = greenChannel1[greenOffset1];
				++greenOffset1;
			}
			if(row % 2 != 0 && col % 2 == 0)
			{
				_green[_width * row + col] = greenChannel2[greenOffset2];
				++greenOffset2;
			}
			if(row % 2 != 0 && col % 2 != 0)
			{
				_blue[_width * row + col] = blueChannel[blueOffset];
				++blueOffset;
			}
		}
	}
 }

void Debayer::DebayerProcess()
{
	BilinearInterpolateRed();
	BilinearInterpolateGreen();
	BilinearInterpolateBlue();
	DemosaicBorders(_blue);
	DemosaicBorders(_green);
	DemosaicBorders(_red);
	FillColorImage();
}

void Debayer::BilinearInterpolateRed()
{
	for (unsigned int index = _width + 1 ;index < _width * _height ;index += 2)
	{
		_red[index] = ( _red[index - _width - 1] + _red[index - _width + 1] + _red[index + _width - 1] + _red[index + _width + 1] ) >> 2;
		_red[index + 1] = ( _red[index + _width + 1] + _red[index - _width + 1] ) >> 1;
        _red[index + _width] = ( _red[index + _width - 1] + _red[index + _width + 1] ) >> 1;
        
        if ((index + 3) % _width <= 1)
        {
            index += _width + 2;
        }
	}
}
void Debayer::BilinearInterpolateBlue()
{
	 for(unsigned int  index = (2 * _width) + 2 ; index < _width * _height; index += 2)
    {
        _blue[index] = ( _blue[index - _width - 1] + _blue[index - _width + 1] + _blue[index + _width - 1] + _blue[index + _width + 1] ) >> 2;
        _blue[index - 1] = ( _blue[index + _width - 1] + _blue[index - _width - 1] ) >> 1;
        _blue[index - _width] = ( _blue[index - _width - 1] + _blue[index - _width + 1] ) >> 1;

        if ((index + 3) % _width <= 1)
        {
            index += _width + 2;
        }
    }
}
void Debayer::BilinearInterpolateGreen()
{
    for(unsigned int index = _width + 1; index < _width * _height; index += 2)
    {
        _green[index] = ( _green[index - _width] + _green[index - 1] + _green[index + 1] + _green[index + _width] ) >> 2;

        if ((index + 3) % _width <= 1)
        {
            index += _width + 2;
        }
    }
    for(unsigned int index = (2 * _width) + 2 ; index < _width * _height; index += 2)
    {
        _green[index] = ( _green[index - _width] + _green[index - 1] + _green[index + 1] + _green[index + _width] ) >> 2;

        if ((index + 3) % _width <= 1)
        {
            index += _width + 2;
        }
    }
}

void Debayer::DemosaicBorders(uint8_t *channel)
{
    uint32_t size = (_width * _height) - _width;
    for(uint32_t index = 0; index < _width; index += 2)
    {
        channel[index] = channel[index + _width];
        channel[index + 1] = channel[index + _width + 1];
        channel[size + index] = channel[size + index - _width];
        channel[size + index + 1] = channel[size + index - _width + 1];
    }
    for(uint32_t index = 0; index < _height; index += 2)
    {
        channel[(index * _width)] = channel[(index * _width) + 1];
        channel[(index + 1) * _width] = channel[((index + 1) * _width) + 1];
        channel[((index + 1) * _width) - 1] = channel[((index + 1) * _width) - 2];
        channel[((index + 2) * _width) - 1] = channel[((index + 2) * _width) - 2];
    }
}

void Debayer::FillColorImage()
{	
	unsigned int colorImageSize = _width * _height * 3;
	for(unsigned int index = 0 ; index < colorImageSize ; index += 3 )
	{
		_colorImage[index] = _red[index / 3];
		_colorImage[index + 1] = _green[index / 3];
		_colorImage[index + 2] = _blue[index / 3];
	}
}
Debayer::~Debayer()
{
}