#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

class Color 
{
private:
    int _r, _g, _b;
public:
    Color();
    Color(int, int, int);
    virtual ~Color();
    Color(const Color&);
    void set_color(int, int, int);
    int get_r() const;
    int get_g() const;
    int get_b() const;
    Color scalar_product(float a);
    Color operator+(Color const& c); 
    friend ostream& operator<<(ostream& os, const Color& c);
    friend istream& operator>>(istream& is, Color& c);
    Color& operator=(const Color &other);
    bool operator==(const Color &c);
};

#endif