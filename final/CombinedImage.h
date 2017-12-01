#ifndef COMBINEDIMAGE_H_
#define COMBINEDIMAGE_H_
#include "Image.h"

using namespace std;

class CombinedImage : public Image
{
public:
    CombinedImage();
    CombinedImage(Image *i1, Image *i2, Image *i3, Image *i4);
};

#endif