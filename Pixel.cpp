#include "Pixel.h"
//default constructor and deconstructor
Pixel::Pixel(){}
Pixel::~Pixel(){}
//parameterised constructor
Pixel::Pixel(int xc, int yc, Color col){
    x = xc;
    y = yc;
    c=col;
}
//copy constructor
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
//set the brightness of each pixel
void Pixel::setbrightness(int bright){
    brightness = bright;
}
//output operator overloading
ostream& operator << (ostream& out, Pixel p){
    out << p.c;
    return out;
}
