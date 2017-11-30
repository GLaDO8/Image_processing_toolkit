#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "binary_image.h"

binary_image::binary_image(Image i): Image(i) {
    _bin_arr = new int*[_h];
    for(int i = 0; i < _h; i++) {
        _bin_arr[i] = new int[_w];
    }    
    binarize(get_treshold());
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

int binary_image::get_treshold() {
    int* b_vals = new int[256];
    for(int i = 0; i < 256; i++)    b_vals[i] = 0;

    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            b_vals[_arr[i][j].get_brightness()]++;
        }
    }
    std::vector<int> tresholds;
    int net = 0;
    for(int i = 1; i < 255; i++) {
        if(b_vals[i-1] > b_vals[i] && b_vals[i] < b_vals[i+1]){  tresholds.push_back(i); net += i;}
    }
    return net/tresholds.size();

    sort(tresholds.begin(), tresholds.end());

    // std::cout << "treshold values are" << std::endl;    
    // for(int i = 0; i < tresholds.size(); i++) {
        // std::cout << tresholds[i] << " ";
    // }
    std::cout << std::endl;
    delete b_vals;
    if(tresholds.size() % 2 == 0)   return (tresholds[tresholds.size()/2] + tresholds[tresholds.size()/2 -1])/2;
    else    return tresholds[tresholds.size()/2];
    return 0;
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