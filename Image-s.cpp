#include "Image-s.h"
Image::Image(){}
Image::~Image(){}
Image::Image(int w, int h){
    width = w;
    height = h;
}
void Image::arrini(){
    pixarr = new Pixel*[width];
    for(int i=0; i<width; i++){
        pixarr[i] = new Pixel[height];
    }
}
void Image::setwidth(int w){
    width = w;
}
void Image::setheight(int h){
    height = h;
}
int Image::getwidth(){
    return width;
}
int Image::getheight(){
    return height;
}
void Image::setpixarr(int i, int j, Pixel p){
    pixarr[i][j] = p;
}
Pixel Image::getpixarr(int i, int j){
    return pixarr[i][j];
}
void Image::filter(Color c, float alpha){
    Color currcolor; Color *finalcolor; int r, g, b, newr, newg, newb;
    for(int i = 0; i<width; i++){
        for(int j = 0; j<height; j++){
            currcolor = pixarr[i][j].getcolor();
            newr = (1-alpha)*currcolor.getr()+alpha*c.getr();
            newb = (1-alpha)*currcolor.getb()+alpha*c.getb();
            newg = (1-alpha)*currcolor.getg()+alpha*c.getg();
            finalcolor = new Color(newr, newg, newb);
            pixarr[i][j].setcolor(*finalcolor);
        }
    }
}
