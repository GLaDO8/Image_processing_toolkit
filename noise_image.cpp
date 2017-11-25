#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "noise_image.h"

noise_image::noise_image(const int& w, const int& h): Image(w, h) {
    float g;
    float a = rand()%10;
    float b = rand()%10;
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            g = 255*(1 + sin(i + j + rand()%255*a*b))/2;
            _arr[i][j].set_color(g, g, g);
        }
    }
}