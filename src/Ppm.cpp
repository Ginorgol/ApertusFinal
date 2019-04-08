#include "../header/Ppm.hpp"

Ppm::Ppm()
{
}

Ppm::Ppm(RawImage &img)
{
	_width = img.GetWidth();
	_height = img.GetHeight();
	_maxVal = 255;

	_redChannel = img.GetRedChannel();
	_greenChannel1 = img.GetGreenChannel1();
	_greenChannel2 = img.GetGreenChannel2();
	_blueChannel = img.GetBlueChannel();

	_colorImage = img.GetColorImage();
}

void Ppm::WriteImageUtil(const std::string imgBasePath)
{
	WriteChannels(_redChannel , imgBasePath + "redChannel.pgm");
	WriteChannels(_greenChannel1 , imgBasePath + "greenChannel1.pgm");
	WriteChannels(_greenChannel2 , imgBasePath + "greenChannel2.pgm");
	WriteChannels(_blueChannel , imgBasePath + "blueChannel.pgm");

	WriteColorImage(imgBasePath + "apertus.ppm");
}

void Ppm::WriteChannels(uint8_t * channel , const std::string filename)
{
	std::ofstream inp(filename, std::ios::out | std::ios::binary);
	if (inp.is_open())
	{
        inp << "P5" <<std::endl;
        inp << _width / 2;
        inp << " ";
        inp << _height / 2<< std::endl;
        inp << _maxVal << std::endl;

        unsigned fileSize = _width * _height * 3 / 4;
        inp.write(reinterpret_cast<char*>(channel), fileSize);

    }
    else
    {
    	std::cerr << "Error : Could'nt write file .. Exiting" << std::endl;
    	exit(1);
    }
}

void Ppm::WriteColorImage(const std::string filename)
{
	std::ofstream inp(filename, std::ios::out | std::ios::binary);
	if (inp.is_open())
	{
        inp << "P6" <<std::endl;
        inp << _width;
        inp << " ";
        inp << _height<< std::endl;
        inp << _maxVal << std::endl;

        unsigned fileSize = _width * _height * 3;
        inp.write(reinterpret_cast<char*>(_colorImage), fileSize);

    }
    else
    {
    	std::cerr << "Error : Could'nt write file .. Exiting" << std::endl;
    	exit(1);
    }
}
Ppm::~Ppm()
{
}