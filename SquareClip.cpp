#include <iostream>
#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"
#include "SquareClip.h"

using namespace std;

SquareClip::SquareClip() {}
SquareClip::SquareClip(Image *img, int a)
{
    side=a;
    _h = img->get_h();
    _w = img->get_w();
    set_arr();
    Color white;
    white.set_color(255,255,255);
    for (int i = 0; i < _h; ++i)
    {
        for (int j = 0; j < _w; ++j)
        {
            if(i<=_h/2+side/2 && i>=_h/2-side/2 && j<=_w/2+side/2 && j>=_w/2-side/2)
                _arr[i][j].set_color(img->color_at(i,j));
            else
                _arr[i][j].set_color(white);
        }
    }
}