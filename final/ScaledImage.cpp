#include "ScaledImage.h"
#include <cmath>

ScaledImage::ScaledImage() {}
ScaledImage::ScaledImage(Image *img) 
{
    type="";
    _w = img->get_w();
    _h = img->get_h();
    int ht = ceil(_h/2.0);
    int width = ceil(_w/2.0);
    set_arr();
    for (int i = 0; i < _h; ++i)
    {
        for (int j = 0; j < _w; ++j)
        {
            if (i < ht && j < width)
                _arr[i][j].set_color(img->color_at(2*i,2*j));
            else
                _arr[i][j].set_color(255,255,255);
        }
    }
}
ScaledImage::ScaledImage(Image *img, string s)
{
    _w = img->get_w();
    _h = img->get_h();
    type = s;
    int ht = ceil(_h/2.0);
    int width = ceil(_w/2.0);
    set_arr();
    if(s=="A")
    {
        for (int i = 0; i < _h; ++i)
        {
            for (int j = 0; j < _w; ++j)
            {
                if (i < ht && j >= width)
                    _arr[i][j].set_color(img->color_at(2*i,2*(_w-j)-1));
                else
                    _arr[i][j].set_color(255,255,255);
            }
        }   
    }    
    if(s=="B")
    {
        for (int i = 0; i < _h; ++i)
        {
            for (int j = 0; j < _w; ++j)
            {
                if (i >= ht && j < width)
                    _arr[i][j].set_color(img->color_at(2*(_h-i)-1,2*j));
                else
                    _arr[i][j].set_color(255,255,255);
            }
        }   
    }
    if(s=="AB")
    {
        for (int i = 0; i < _h; ++i)
        {
            for (int j = 0; j < _w; ++j)
            {
                if (i >= ht && j >= width)
                {
                    _arr[i][j].set_color(img->color_at(2*(_h-i)-1,2*(_w-j)-1));
                }
                else
                {
                    _arr[i][j].set_color(255,255,255);
                }
            }
        }   
    }
}