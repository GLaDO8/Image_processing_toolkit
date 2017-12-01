#include <iostream>
#include <algorithm>
#include <fstream>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "composite_image.h"

composite_image::composite_image(const Image& i1, const Image& i2, float a): Image(std::min(i1.get_w(), i2.get_w()), 
                                                                    std::min(i1.get_h(), i2.get_h())) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j].set_color(i1.color_at(i, j).scalar_product(1-a) + i2.color_at(i, j).scalar_product(a));
        }
    }
}


// int main(int argc, char** argv) {
//     std::string img1_file(argv[1]);
//     std::string img2_file(argv[2]);

//     float a = atof(argv[3]);
//     Image i1, i2;

//     std::ifstream f_ptr1(img1_file);
//     std::ifstream f_ptr2(img2_file);

//     f_ptr1 >> i1;
//     f_ptr2 >> i2;

//     composite_image c(i1, i2, a);

//     std::ofstream o_ptr("output.ppm");
//     o_ptr << c;
//     return 0;
// }