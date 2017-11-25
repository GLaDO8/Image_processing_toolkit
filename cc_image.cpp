#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "binary_image.h"

#include "cc_image.h"

cc_image::cc_image(Image i, int treshold): binary_image(i, treshold) {connectize();}

void cc_image::connectize() {
    int** bin_arr = get_bin_arr();
    int w = get_w();
    int h = get_h();

    int label = 1;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(bin_arr[i][j] == -1) {
                _DFS_Util(i, j, label, bin_arr);
                label += 1;
            }
        }
    }
    colors = new Color[7];

    colors[0] = Color(255, 0, 0);
    colors[1] = Color(0 ,255, 0);
    colors[2] = Color(0 ,0, 255);
    colors[3] = Color(255 ,165, 0);
    colors[4] = Color(255 ,255, 0);
    colors[5] = Color(255 ,192, 203);
    colors[6] = Color(128 ,0, 128);
    
}

void cc_image::_DFS_Util(int i, int j, int label, int**& bin_arr) {
    bin_arr[i][j] = label;
    std::vector<std::pair<int,int> > neighbors = _get_neighbors(i, j);

    for(auto & n : neighbors) {
        if(bin_arr[n.first][n.second] == -1) {
            _DFS_Util(n.first, n.second, label, bin_arr);
        }
    }
}

std::vector<std::pair<int, int> > cc_image::_get_neighbors(int i, int j) {
    std::vector<std::pair<int,int> > neighbors;
    int w = get_w(), h = get_h();

    for(int m = -1; m < 2; m++) {
        if(i + m >= 0 && i + m < h) {
            for(int n = -1; n < 2; n++) {
                if(j + n >= 0 && j + n < w) {
                    neighbors.push_back(std::make_pair(i+m, j+n));
                }
            }
        }
    }
    return neighbors;    
}

void cc_image::print() {
    int** bin_arr = get_bin_arr();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            std::cout << bin_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const cc_image& cc_i) {
    os << "P3" << std::endl;
    os << cc_i.get_w() << " " << cc_i.get_h() << std::endl;
    os << 255 << std::endl;

    int** bin_arr = cc_i.get_bin_arr();
    for(int i = 0; i < cc_i.get_h(); i++) {
        for(int j = 0; j < cc_i.get_w(); j++) {
            os << cc_i.colors[bin_arr[i][j]%7] << " ";
        }
        os << std::endl;
    }
}
