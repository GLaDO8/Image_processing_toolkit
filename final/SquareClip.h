#ifndef SQUARECLIP_H_
#define SQUARECLIP_H_
#include "Image.h"

using namespace std;

class SquareClip : public Image
{
protected:
    int side;
public:
    SquareClip();
    SquareClip(Image* img, int a);
};

#endif