#include "color.h"
#include <iostream>

Color::Color(){_r = _g = _b = 0;}
Color::Color(float r, float g, float b): _r(r), _g(g), _b(b) {}
Color::~Color(){}
Color::Color(const Color& p) {
    _r = p._r;
    _g = p._g;
    _b = p._b;
}

void Color::set_color(float r, float g, float b) {
    _r = r;
    _g = g;
    _b = b;
}
float Color::get_r() const{return _r;}
float Color::get_g() const{return _g;}
float Color::get_b() const{return _b;}

Color& Color::operator=(const Color &other) {
    _r = other._r;
    _g = other._g;
    _b = other._b;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << static_cast<int>(c._r) << " " << static_cast<int>(c._g) << " " << static_cast<int>(c._b);
    return os;
}

std::istream& operator>>(std::istream& is, Color& c) {
    is >> c._r >> c._g >> c._b;
    return is;
}