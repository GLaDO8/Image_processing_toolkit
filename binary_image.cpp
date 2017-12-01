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
    int pixel_count[256]; // pixel count of each brightness value.
    for(int i = 0; i < 256; i++)    pixel_count[i] = 0;

    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            pixel_count[_arr[i][j].get_brightness()]++;
        }
    }   
    std::vector<int> tresholds;
    for(int i = 1; i < 256; i++) {
        if(pixel_count[i] < pixel_count[i-1] && pixel_count[i] < pixel_count[i+1]) {
            tresholds.push_back(i);
        }
    }
    std::sort(tresholds.begin(), tresholds.end());
    if(tresholds.size() == 0) {
        // for(int i = 0; i < 256; i++) {
        //     std::cout << pixel_count[i] << " ";
        // }
        // std::cout << std::endl;
        exit(1);
        return 0;
    }
    if(tresholds.size() % 2 == 1) {
        return tresholds.at(tresholds.size()/2);
    }
    else {
        return (tresholds.at(tresholds.size()/2 - 1) + tresholds.at(tresholds.size()/2))/2;
    }
}