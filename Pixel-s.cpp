#include "Pixel-s.h"
Pixel::Pixel(){}
Pixel::~Pixel(){}
Pixel::Pixel(int xc, int yc, Color col){
    x = xc;
    y = yc;
    c=col;
}
Pixel::Pixel(const Pixel &px){
    x = px.x;
    y = px.y;
    c = px.c;
}
void Pixel::setcolor(Color newc){
    c = newc;
}
Color Pixel::getcolor(){
    return c;
}
ostream& operator << (ostream& out, Pixel p){
    out << p.c;
    return out;
}
