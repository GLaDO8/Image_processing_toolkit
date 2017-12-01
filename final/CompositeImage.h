#ifndef COMPOSITEIMAGE_H_
#define COMPOSITEIMAGE_H_

#include "Image.h"
using namespace std;

class CompositeImage : public Image
{
protected:
    float alpha;
public:
    CompositeImage();
    CompositeImage(Image *i1, Image *i2, float a);     
};

#endif