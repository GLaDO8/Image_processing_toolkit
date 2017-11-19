#ifndef __COLOR_H_INCLUDED__
#define __COLOR_H_INCLUDED__
#include <iostream>
using namespace std;
class Color{
private:
    float red, green, blue;
public:
    Color();
    ~Color();
    Color(float r, float g, float b);
    Color(const Color &colo);
    float getr();
    float getg();
    float getb();
    friend ostream& operator << (ostream& out, Color c);
};
#endif
