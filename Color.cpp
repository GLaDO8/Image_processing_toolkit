//By Aayush Grover

#include "Color.h"
#include <iostream>
#include <fstream>

using namespace std;

Color::Color() {}
Color::Color(int a, int b1, int c): r(a), g(b1), b(c) {}
Color::~Color() {}
Color::Color(const Color& c): r(c.r), b(c.b), g(c.g) {}

int Color::getr(){return r;}
int Color::getg(){return g;}
int Color::getb(){return b;}

Color& Color::scalar_product(float x)
{
	Color& res = *(new Color());
	res.r = x*(r);
	res.g = x*(g);
	res.b = x*(b);
	if(res.r > 255) res.r-=255;
	if(res.g > 255) res.g-=255;
	if(res.b > 255) res.b-=255;
	return res;
}

Color& Color::operator+(Color const& c) 
{
	Color* t = new Color();
	Color& res = *t;
	res.r=r+c.r;
	res.g=g+c.g;
	res.b=b+c.b; 
	return res;
}

Color const& Color::operator=(Color const& c)
{
	r=c.r; g=c.g; b=c.b;
}

bool Color::operator==(const Color& c) const
{
	return (r==c.r && g==c.g && b==c.b);
}

ostream& operator<<(ostream& os, Color& c)
{	
	os<<c.r<<" "<<c.g<<" "<<c.b<<" ";
	return os;
}

istream& operator>>(istream& is, Color& c)
{
	is>>c.r>>c.g>>c.b;
	return is;
}