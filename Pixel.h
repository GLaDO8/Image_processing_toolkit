#ifndef __PIXEL_H_INCLUDED__
#define __PIXEL_H_INCLUDED__
#include <iostream>
#include "Color.h"
using namespace std;
class Pixel{
    private:
        int x, y;
        Color c;
        int brightness;
    public:
        Pixel();
        ~Pixel();
        Pixel(int xc, int yc, Color col);
        Pixel(const Pixel &px);
        void setcolor(Color newc);
        Color getcolor();
        void setbrightness(int bright);
        friend ostream& operator << (ostream& out, Pixel p);
};
#endif
