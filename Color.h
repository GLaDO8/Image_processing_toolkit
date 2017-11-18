//By Aayush Grover

#ifndef Color_H_
#define Color_H_

#include <iostream>
#include<fstream>

using namespace std;

class Color
{
private:
	int r,g,b;
public:
	Color();
	Color(int a, int b1, int c);
	~Color();
	Color(const Color& c);
	int getr();
	int getg();
	int getb();
	Color& scalar_product(float x);
	Color& operator+(Color const& c);
	Color const& operator=(Color const& c);
	bool operator==(const Color& c) const;
	friend ostream& operator<<(ostream& os, Color& c);	//overloading operator<<
	friend istream& operator>>(istream& is, Color& c);	//overloading operator>>
};

#endif