#ifndef SCALEDIMAGE_H_
#define SCALEDIMAGE_H_
#include "Image.h"

using namespace std;

class ScaledImage : public Image
{
protected:
    string type;
public:
    ScaledImage();
    ScaledImage(Image *ing);
    ScaledImage(Image *img, string s);
};

#endif