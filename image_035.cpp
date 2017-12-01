#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "image_035.h"


Image_035::Image_035(int w, int h): Image(w, h) {}
Image_035::Image_035(){}
Image_035::~Image_035() {if(!_arr)delete _arr;}

void Image_035::set_arr_der(){
    r_arr = new Pixel*[_h];
    for(int i = 0; i < _h; i++) {
        r_arr[i] = new Pixel[_w];
        for(int j = 0; j < _w; j++) {
            r_arr[i][j].set_loc(i, j);
        }
    }
    
    r_arr2 = new Pixel*[_h];
    for(int i = 0; i < _h; i++) {
        r_arr2[i] = new Pixel[_w];
        for(int j = 0; j < _w; j++) {
            r_arr2[i][j].set_loc(i, j);
        }
    }
}

Pixel** Image_035::get_r_arr(){
    return r_arr;
}

Pixel** Image_035::get_r_arr2(){
    return r_arr2;
}
void Image_035::reflection_y(){
    for(int i = 0; i<_h; i++) {
        for(int j = 0; j<_w; j++) {
            r_arr[i][j] = _arr[i][_w-j-1];
            r_arr[i][j].set_loc(j, i);
        }
    }
}

void Image_035::min_blue(){
    for(int i = 0; i<_h; i++){
        for(int j = 0; j<_w; j++){
            int mini = i; int minj = j;
            int rowLimit = _h-1;
            int columnLimit = _w-1;
            int count1 = 0;
            int count2 = 0;
            for(int x = std::max(0, i-1); x <= std::min(i+1, rowLimit); x++){
                for(int y = std::max(0, j-1); y <= std::min(j+1, columnLimit); y++){
                    if(x != i || y != j){
                        if(r_arr[i][j].get_color().get_b() > r_arr[x][y].get_color().get_b()){
                            count1++;
                        }
                    }
                }
            }
            
            if(count1>0){
                r_arr2[i][j].set_min_blue(true);
            }
            count1 = 0;
            count2 = 0;
        }
    }
}

void Image_035::generate_C(){
    for(int i = 0; i<_h; i++){
        for(int j = 0; j<_w; j++){
            if(r_arr2[i][j].get_min_blue()){
                r_arr2[i][j].set_color(255, 255, 255);
            }
            else{
                r_arr2[i][j].set_color(0, 0, 0);
            }
        }
    }
    
    for(int i = 0; i<_h; i++){
        for(int j = 0; j<_w; j++){
            if(r_arr2[i][j].get_min_blue()){
                int rowLimit = _h-1;
                int columnLimit = _w-1;
                for(int x = std::max(0, i-2); x <= std::min(i+2, rowLimit); x++){
                    for(int y = std::max(0, j-2); y <= std::min(j+2, columnLimit); y++){
                        if(x != i || y != j){
                            r_arr2[x][y].set_color(255, 255, 255);
                        }
                    }
                }
            }
        }
    }
}

double average(std::vector<int> const &v){
        double return_value = 0.0;
        int n = v.size();
       
        for ( int i=0; i < n; i++)
        {
            return_value += v[i];
        }
       
        return ( return_value / n);
}

void Image_035::gaussian_filter(){
    for(int i = 0; i<_h; i++){
        for(int j = 0; j<_w; j++){
            std::vector<int> v;
            int rowLimit = _h-1;
            int columnLimit = _w-1;
            
            v.push_back(0);
            if(r_arr2[i][j].get_min_blue()){
                v.push_back(41);
            }
            for(int x = std::max(0, i-2); x <= std::min(i+2, rowLimit); x++){
                for(int y = std::max(0, j-2); y <= std::min(j+2, columnLimit); y++){
                    if(x != i || y != j){
                        if(r_arr2[x][y].get_min_blue()){
                            if(abs(x-i) + abs(y-j) == 1)
                                v.push_back(26);
                            else if(abs(x-i) + abs(y-j) == 3)
                                v.push_back(4);
                            else if(abs(x-i) + abs(y-j) == 2){
                                if(x==i || y==j)
                                    v.push_back(7);
                                else
                                    v.push_back(16);
                            }
                            else if(abs(x-i) + abs(y-j) == 4)
                                v.push_back(1);
                        }
                    }
                }
            }
            int avg = average(v);
            r_arr2[i][j].set_color((255 * avg/273), (255 * avg/273), (255 * avg/273));
        }
    }
}