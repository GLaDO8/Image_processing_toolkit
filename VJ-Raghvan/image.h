#ifndef IMAGE_H
#define IMAGE_H

class Image {
    int _w, _h, max_pixel;
    std::string _encoding;
    Pixel** _arr;
public:
    Image(int w, int h);
    Image();
    virtual ~Image();
    Color color_at(int x, int y) const;
    void filter(const Color& c, float a);
    void set_arr();
    friend std::ostream& operator<<(std::ostream& os, const Image& i);
    friend std::istream& operator>>(std::istream& in, Image& i);    
};

#endif