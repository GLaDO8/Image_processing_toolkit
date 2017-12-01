#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include <iostream>
#include <algorithm>

using namespace std;

Image::Image(int w, int h):_w(w), _h(h) {
    set_arr();    
}
Image::Image(){}
Image::~Image() {if(!_arr)delete _arr;}

void Image::set_arr() {
    _arr = new Pixel*[_h];
    for(int i = 0; i < _h; i++) {
        _arr[i] = new Pixel[_w];
        for(int j = 0; j < _w; j++) {
            _arr[i][j].set_loc(i, j);
        }
    }
}

int Image::get_w() {return _w;}
int Image::get_h() {return _h;}

void Image::set_pixel(int i, int j,int r, int g, int b)
{
    _arr[i][j].set_color(r,g,b);
}

void Image::filter(const Color& c, float a) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j].apply_filter(c, a);
        }
    }
}
Color Image::color_at(int x, int y) const{
    return _arr[x][y].get_color();
}

istream& operator>>(istream& in, Image& im) {
    // in >> im._encoding;
    // if(im._encoding != "P3") {
    //     cout << "unsupported file encoding!" << endl;
    //     exit(1);
    // }
    in >> im._w >> im._h;// >> im.max_pixel;

    im.set_arr();
    Pixel p;
    for(int i = 0; i < im._h; i++) {
        for(int j = 0; j < im._w; j++) {
            in >> p;
            p.set_loc(j, i);
            im._arr[i][j] = p;
        }
    }
    return in;
}

ostream& operator<<(ostream& os, const Image& im) {
    // os << im._encoding << endl;
    os << im._w << " " << im._h << endl;

    // os << im.max_pixel << endl;

    for(unsigned i = 0; i < im._h; i++) 
    {
        for(unsigned j = 0; j < im._w; j++) 
        {
            os << im._arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}