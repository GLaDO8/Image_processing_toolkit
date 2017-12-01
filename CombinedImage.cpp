#include <iostream>
#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"
#include "CombinedImage.h"

using namespace std;

CombinedImage::CombinedImage() {}
CombinedImage::CombinedImage(Image *i1, Image *i2, Image *i3, Image *i4)
{
    _w = i1->get_w();
    _h = i1->get_h();
    Color white;
    white.set_color(255,255,255);
    set_arr();
    for (int i = 0; i < _h; ++i)
    {
        for (int j = 0; j < _w; ++j)
        {
            if(i1->color_at(i,j) == white)
                _arr[i][j].set_color(i2->color_at(i,j));
            else if (i2->color_at(i,j) == white)
                _arr[i][j].set_color(i1->color_at(i,j));
        }
    }
    for (int i = 0; i < _h; ++i)
    {
        for (int j = 0; j < _w; ++j)
        {
            if(i3->color_at(i,j) == white && color_at(i,j)==white)
                _arr[i][j].set_color(i4->color_at(i,j));
            else if (i4->color_at(i,j) == white && color_at(i,j)==white)
                _arr[i][j].set_color(i3->color_at(i,j));
        }
    }
}