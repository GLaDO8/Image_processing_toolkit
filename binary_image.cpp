#include <iostream>
#include <algorithm>
#include <fstream>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "binary_image.h"

binary_image::binary_image(Image i, int treshold): Image(i) {
    _bin_arr = new int*[get_h()];
    for(int i = 0; i < get_h(); i++) {
        _bin_arr[i] = new int[get_w()];
    }    
    binarize(treshold);
}

void binary_image::binarize(int treshold) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            if(_arr[i][j].get_brightness() > treshold) {
                _arr[i][j].set_color(255, 255, 255);
                _bin_arr[i][j] = -1;
            }
            else {
                _arr[i][j].set_color(0, 0, 0);
                _bin_arr[i][j] = 0;
            };
        }
    }
}

int** binary_image::get_bin_arr() const {
    return _bin_arr;
}

// int binary_image::get_brightness(const Color& c) {
//     return (c.get_r() + c.get_g() + c.get_b())/3;
// }

// int main(int argc, char** argv) {
//     std::string file_name(argv[1]);
//     int treshold = atoi(argv[2]);
//     std::ifstream f_ptr(file_name);

//     Image i;
//     f_ptr >> i;

//     binary_image b(i, treshold);

//     std::ofstream o_ptr("output.ppm");
//     o_ptr << i;
//     return  0;
// }