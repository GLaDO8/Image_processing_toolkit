#include <bits/stdc++.h>
#include "CompositeImage.h"

CompositeImage::CompositeImage() {}
CompositeImage::CompositeImage(Image *A, Image *B, float a) 
{
    if(A->get_w()!=B->get_w() || A->get_h()!=B->get_h())
        cout<<"Non-compatible images."<<endl;
    else
    {
        _w = A->get_h();
        _h = A->get_h();
        alpha = a;
        set_arr();
        for(int i = 0; i<_h; i++)
        {
            for(int j = 0; j<_w; j++)
            {
                _arr[i][j].set_color((A->color_at(i,j)).scalar_product(1-alpha) + (B->color_at(i,j)).scalar_product(alpha));
            }
        }
    }
}