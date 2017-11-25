#include <iostream>
#include <algorithm>
#include <fstream>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "composite_image.h"
#include "noise_image.h"
#include "binary_image.h"

using namespace std;

int main(int argc, char** argv) {
    std::string img_file(argv[1]);

    float a = atof(argv[2]);
    int treshold = atoi(argv[3]);

    Image i;
    std::ifstream f_ptr(img_file);

    f_ptr >> i;
    noise_image n(i.get_w(), i.get_h());

    composite_image c(i, n, a);
    std::ofstream o_ptr("output.ppm");
    o_ptr << c;

    std::ofstream o_ptr_b("bin_output.ppm");
    binary_image b(c, treshold);

    o_ptr_b << b;
    
    return 0;
}