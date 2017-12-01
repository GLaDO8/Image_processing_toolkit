#include "Color.h"
#include <bits/stdc++.h>

using namespace std;

Color::Color(){_r = _g = _b = 0;}
Color::Color(int r, int g, int b): _r(r), _g(g), _b(b) {}
Color::~Color(){}
Color::Color(const Color& p) 
{
    _r = p._r;
    _g = p._g;
    _b = p._b;
}

void Color::set_color(int r, int g, int b) 
{
    _r = r;
    _g = g;
    _b = b;
}

int Color::get_r() const {return _r;}
int Color::get_g() const {return _g;}
int Color::get_b() const {return _b;}

Color Color::scalar_product(float a)
{
    Color res;
    res._r = _r*a;
    res._g = _g*a;
    res._b = _b*a;
    return res;
}

Color Color::operator+(Color const& c) 
{
    Color res;
    res._r=_r+c._r;
    res._g=_g+c._g;
    res._b=_b+c._b; 
    return res;
}

Color& Color::operator=(const Color &other) 
{
    _r = other._r;
    _g = other._g;
    _b = other._b;
    return *this;
}

bool Color::operator==(const Color &c)
{
    return (_r==c._r && _b==c._b && _g==c._g);
}

ostream& operator<<(ostream& os, const Color& c) 
{
    os << (c._r) << " " << (c._g) << " " << (c._b)<< " ";
    return os;
}

istream& operator>>(istream& is, Color& c) 
{
    is >> c._r >> c._g >> c._b;
    return is;
}