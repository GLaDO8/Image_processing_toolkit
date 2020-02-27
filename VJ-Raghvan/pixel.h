#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
    int _x, _y;
    Color _c;
public:
    Pixel();
    virtual ~Pixel();
    Pixel(const Pixel& p);
    Color get_color () const;
    void set_color(float r, float g, float b);
    void set_loc(int x, int y);
    void apply_filter(const Color& c, float a);
    friend std::ostream& operator<<(std::ostream& os, const Pixel& p);
    friend std::istream& operator>>(std::istream& is, Pixel& p);
};

#endif