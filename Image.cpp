//By Aayush Grover

#include "Image.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

Pixel::Pixel() {}
Pixel::Pixel(int a, int b, Color x): x(a), y(b), c(x) {}
Pixel::~Pixel() {}
Pixel::Pixel(const Pixel& p): x(p.x), y(p.y), c(p.c) {}

int Pixel::getr(){return c.getr();}
int Pixel::getg(){return c.getg();}
int Pixel::getb(){return c.getb();}

Pixel const& Pixel::operator=(Pixel const& p)
{
	x=p.x; y=p.y; c=p.c;
}

ostream& operator<<(ostream& os, Pixel& p)
{
	os<<p.c;
	return os;
}

istream& operator>>(istream& is, Pixel& p)
{
	is>>p.x>>p.y>>p.c;
	return is;
}

Image::Image() {}
Image::Image(int w, int h): width(w), ht(h) 
{
	this->p = new Pixel*[this->ht]; 
	for(int i = 0; i < this->ht; ++i)
		this->p[i] = new Pixel[this->width];
}
Image::~Image() {}
Image::Image(const Image& i): width(i.width), ht(i.ht), p(i.p) {}

int Image::getWidth() {return width;}
int Image::getHt() {return ht;}

Image const& Image::operator=(Image const& i)
{
	width=i.width; ht=i.ht;
}

Pixel& Image::getPixel(int i, int j)
{
	return p[i][j];
}

Noise::Noise(int w,int h) 
{
	srand(time(NULL));
	Image(w,h);
	width=w;
	ht=h;
	this->p = new Pixel*[this->ht]; 
	for(int i = 0; i < this->ht; ++i)
		this->p[i] = new Pixel[this->width];
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			int g1 = rand()%256;
			int g2 = rand()%256;
			int g3 = rand()%256;
			p[i][j] = *(new Pixel(i,j,*(new Color(g1,g2,g3)))); 
		}		
	}
}
Noise::~Noise(){}

int Noise::noise(int x,int y)
{
	return p[x][y].getr();
}

ProceduralTexture::ProceduralTexture() {}
ProceduralTexture::ProceduralTexture(Noise *n, float a, float b)
{
	int w = n->getWidth();
	int h = n->getHt();
	Image(w,h);
	this->p = new Pixel*[h]; 
	for(int i = 0; i < h; ++i)
		this->p[i] = new Pixel[w];
	width = w;
	ht = h;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			int G1 = 255*(1 + sin((i + j + n->getPixel(i,j).getr())*a*b))/2;
			int G2 = 255*(1 + sin((i + j + n->getPixel(i,j).getg())*a*b))/2;
			int G3 = 255*(1 + sin((i + j + n->getPixel(i,j).getb())*a*b))/2;
			p[i][j] = *(new Pixel(i,j,*(new Color(G1,G2,G3)))); 
		}		
	}
}
ProceduralTexture::~ProceduralTexture() {}