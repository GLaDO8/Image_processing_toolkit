#ifndef __IMAGE_H_INCLUDED__
#define __IMAGE_H_INCLUDED__
#include <iostream>
#include "Pixel.h"
using namespace std;
class Image{
    protected:
        int width, height;
        Pixel **pixarr;
    public:
        Image();
        ~Image();
        Image(int w, int h);
        void arrini();
        void setwidth(int w);
        void setheight(int h);
        int getwidth();
        int getheight();
        Pixel getpixarr(int i, int j);
        void setpixarr(int i, int j, Pixel p);
        void filter(Color c, float alpha);
};
#endif
