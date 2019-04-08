#include "../header/ProcessImage.hpp"

ProcessImage::ProcessImage()
{
}

ProcessImage::ProcessImage(RawImage &img)
{
	_height = img.GetHeight();
	_width = img.GetWidth();


	_redChannel = img.GetRedChannel();
	_greenChannel1 = img.GetGreenChannel1();
	_greenChannel2 = img.GetGreenChannel2();
	_blueChannel = img.GetBlueChannel();
	_senselDump = img.GetSenselDump();

	_colorImage = img.GetColorImage();
}

void ProcessImage::SeperateChannels()
{
	unsigned row, col;
	unsigned offest;
	unsigned bytecount = _width * _height * 3 / 2;

	for(unsigned int runPtr = 0 ;runPtr < bytecount ; runPtr += 3)
	{
		row = (runPtr * 2 / 3) / _width;
		col = (runPtr * 2 / 3) - (_width * row);

		if (row % 2 == 0)
		{
			row = row / 2;
			col = col / 2;
			offest = row * (_width / 2) + col;
			_redChannel[offest] = _senselDump[runPtr];
			_greenChannel1[offest] = (( _senselDump[runPtr + 1] & 0x0F) << 4 |
										_senselDump[runPtr + 2] >> 4);
		}
		else
		{
			row = row / 2;
			col = col / 2;
			offest = row * (_width / 2) + col;
			_greenChannel2[offest] = _senselDump[runPtr];
			_blueChannel[offest] = ((_senselDump[runPtr + 1] & 0x0F) << 4 |
									 _senselDump[runPtr + 2] >> 4);
		}
	}
}

void ProcessImage::DisplayChannelIntensityUtil()
{
	DisplayChannelIntensity(_redChannel, "Red Channel");
	DisplayChannelIntensity(_greenChannel1, "Green1 Channel");
	DisplayChannelIntensity(_greenChannel2, "Green2 Channel");
	DisplayChannelIntensity(_blueChannel, "Blue Channel");
}

void ProcessImage::DisplayChannelIntensity(uint8_t * channel, const char * channelName)
{
	std::cout << "Intensity values of the first 5 * 5  of " << channelName << std::endl;
	for(unsigned int row = 0 ; row < 5 ; ++row)
	{
		for(unsigned int col = 0 ; col < 5 ; ++col)
		{
			std::cout << int(channel[( _width / 2 ) * row + col]) << " ";
		}
		std::cout << std::endl;
	}
}
ProcessImage::~ProcessImage()
{
}