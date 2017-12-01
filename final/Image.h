#ifndef IMAGE_H
#define IMAGE_H
#include "Color.h"
#include "Pixel.h"

using namespace std;

class Image 
{
protected:
    int _w, _h;
    Pixel** _arr;
public:
    Image(int w, int h);
    Image();
    virtual ~Image();
    int get_w();     //change to get_w
    int get_h();    //change to get_h
    void set_pixel(int i,int j, int r, int g, int b);    //change to set_pixel
    Color color_at(int x, int y) const;
    void filter(const Color& c, float a);
    void set_arr();
    friend ostream& operator<<(ostream& os, const Image& im);
    friend istream& operator>>(istream& in, Image& im);    
};

#endif