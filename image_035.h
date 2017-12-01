#ifndef IMAGE2_H
#define IMAGE2_H

#include <iostream>
#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

class Image_035 : public Image {
protected:
    Pixel** r_arr;      //
    Pixel** r_arr2;     //
public:
    Image_035(int w, int h);
    Image_035();
    void set_arr_der();
    virtual ~Image_035();
    Pixel** get_r_arr();
    Pixel** get_r_arr2();
    void reflection_y();
    void min_blue();
    void generate_C();
    void gaussian_filter();
    friend std::ostream& operator<<(std::ostream& os, const Image& i);
    friend std::istream& operator>>(std::istream& in, Image& i);
};

#endif