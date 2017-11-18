//By Aayush Grover

#ifndef Image_H_
#define Image_H_

#include "Color.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class Pixel
{
private:
	int x,y;
	Color c;
public:
	Pixel();
	Pixel(int a, int b, Color x);
	~Pixel();
	Pixel(const Pixel& p);
	int getr();
	int getg();
	int getb();
	Pixel const& operator=(Pixel const& p);
	friend ostream& operator<<(ostream& os, Pixel& p);	//overloading operator<<
	friend istream& operator>>(istream& is, Pixel& p);	//overloading operator>>
};

class Image
{
protected:
	int width, ht;
	Pixel ** p;
public:
	Image();
  	Image(int w, int h);	
  	~Image();
	Image(const Image& i);
	int getWidth();
	int getHt();
	Image const& operator=(Image const& i);
	Pixel& getPixel(int i, int j);
};

class Noise : public Image
{
public:
	Noise(int w,int h);
	~Noise();
	int noise(int x,int y);
};

class ProceduralTexture : public Image
{
public:
	ProceduralTexture();
	ProceduralTexture(Noise *n, float a, float b);
	~ProceduralTexture();
};

#endif