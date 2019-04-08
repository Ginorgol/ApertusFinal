#Apertus C++ Challenge (T872)

The task is to Process a Raw12 image format and convert it to a PPM image.(https://lab.apertus.org/T872)

##Build Instructions for Linux Environment
* Clone the repository using `git clone git@github.com:kiquance21/ApertusFinal.git`
* Move to the cloned directory `cd PATH_OF_DIR`
* Move to build the folder  `cd build`
* `cmake ..`
* `make`
* `./ApertusTask 4096 3072 ../test.raw12`


##References Used
* Understanding RAW12 (https://wiki.apertus.org/index.php/RAW12)
* C++ coding guidelines ((https://gist.github.com/lefticus/10191322)
* Cmake (https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake)
* Billinear Interpolation (https://github.com/TofuLynx/opencine/blob/777ee30e8cdf6d6a9ba9ee6b8152f3034e8c8dae/Source/OCcore/Image/BilinearDebayer.h)
