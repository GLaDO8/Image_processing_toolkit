#include <iostream>
#include <fstream>
#include <vector>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "Histogram.h"

using namespace std;
Histogram::Histogram(){
    for (size_t i = 0; i < 256; i++) {
        britarr[i] = 0;
    }
    colorarr[0] = Color(255,0,0);
    colorarr[1] = Color(0,255,0);
    colorarr[2] = Color(0,0,255);
    colorarr[3] = Color(255,255,0);
    colorarr[4] = Color(255,0,255);
    colorarr[5] = Color(0, 255, 255);
    colorarr[6] = Color(0, 0, 0);
}
Histogram::Histogram(int w, int h):Image(w, h){
    for (size_t i = 0; i < 256; i++) {
        britarr[i] = 0;
    }
    colorarr[0] = Color(255,0,0);
    colorarr[1] = Color(0,255,0);
    colorarr[2] = Color(0,0,255);
    colorarr[3] = Color(255,255,0);
    colorarr[4] = Color(255,0,255);
    colorarr[5] = Color(0, 255, 255);
    colorarr[6] = Color(0, 0, 0);
}
Histogram::~Histogram(){}
int Histogram::get_brightness(int i, int j){
    return (_arr[i][j].get_color().get_r() + _arr[i][j].get_color().get_g() + _arr[i][j].get_color().get_b())/3;
}
void Histogram::ini_britarr(){
    int numb = 0;
    for(int i=0; i<_h; i++){
        for(int j=0; j<_w; j++){
            numb = get_brightness(i,j);
            britarr[numb]+=1;
        }
    }
}
void Histogram::ini_local_min(){
    local_min.push_back(0);
    for(int i=1; i<255; i++){
        if(britarr[i-1]>britarr[i] && britarr[i]<=britarr[i+1]){
            local_min.push_back(i);
        }
    }
    local_min.push_back(255);
}
Histogram Histogram::segmentation(){
    int sections = local_min.size()-1;
    int curr_brit; Histogram result1(get_w(), get_h());
    Color currcolor; Color *finalcolor; int newr, newg, newb; Pixel *pix;
    if(local_min.size()==2){
        for(int i=0; i<_h; i++){
            for(int j=0; j<_w; j++){
                currcolor = _arr[i][j].get_color();
                newr = (0.6)*currcolor.get_r()+0.4*_arr[_w-i][j].get_color().get_r();
                newb = (0.6)*currcolor.get_b()+0.4*_arr[_w-i][j].get_color().get_b();
                newg = (0.6)*currcolor.get_g()+0.4*_arr[_w-i][j].get_color().get_g();
                result1.set_pixel(i, j, newr, newg, newb);
            }
        }
        return result1;
    }
    else{
        for(int i=0; i<_h; i++){
            for(int j=0; j<_w; j++){
                curr_brit = get_brightness(i, j);
                for(int k=0; k<sections; k++){
                    if(curr_brit<local_min[k+1] && curr_brit>=local_min[k]){
                        if(k<6){
                            result1.set_pixel(i, j, colorarr[k].get_r(), colorarr[k].get_g(), colorarr[k].get_b());
                        }
                        else{
                            result1.set_pixel(i, j, colorarr[6].get_r(), colorarr[6].get_g(), colorarr[6].get_b());
                        }
                    }
                }
            }
        }
    return result1;
    }
}


// int main(int argc, char *argv[]){
//     Histogram h; Histogram output;
//     string name = argv[1];
//     ifstream inputfile(name);
//     inputfile >> h;
//     h.ini_britarr();
//     h.ini_local_min();
//     output = h.segmentation();
//     ofstream outfile("output.ppm");
//     outfile << output << '\n';
//     return 0;
// }