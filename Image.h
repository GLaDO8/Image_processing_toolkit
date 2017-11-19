#ifndef __IMAGE_H_INCLUDED__
#define __IMAGE_H_INCLUDED__
#include <iostream>
#include "Pixel.h"
using namespace std;
class Image{
    protected:
        int width, height;
        Pixel **pixarr;
        vector<int> histarr;
    public:
        Image();
        ~Image();
        Image(int w, int h);
        void arrini();
        void setwidth(int w);
        void setheight(int h);
        int getwidth();
        int getheight();
        void file_name_set(String name);
        String get_file_name();
        Pixel getpixarr(int i, int j);
        void setpixarr(int i, int j, Pixel p);
        void filter(Color c, float alpha);
        void make_histogram();
};
#endif
