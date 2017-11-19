#include "Color-s.h"
Color::Color(){}
Color::~Color(){}
Color::Color(float r, float g, float b){
    red = r;
    green  = g;
    blue = b;
}
Color::Color(const Color &colo){
    red = colo.red;
    green  = colo.green;
    blue = colo.blue;
}
float Color::getr(){
    return red;
}
float Color::getg(){
    return green;
}
float Color::getb(){
    return blue;
}
ostream& operator << (ostream& out, Color c){
    if(c.getr()==0 && c.getg()==0 && c.getb()==0){
        out<< "+ ";
    }
    else if(c.getr()==1 && c.getg()==1 && c.getb()==1){
        out<< "o ";
    }
    else{
        out<< "* ";
    }
    return out;
}
