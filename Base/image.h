#ifndef IMAGE_H
#define IMAGE_H

class Image {
protected:
    int _w, _h, max_pixel;
    std::string _encoding;
    Pixel** _arr;
public:
    Image(int w, int h);
    Image();
    // Image(const Image& i);
    virtual ~Image();
    int get_w() const;
    int get_h() const;
    Color color_at(int i, int j) const;
    // void filter(const Color& c, float a);
    void set_arr();
    friend std::ostream& operator<<(std::ostream& os, const Image& i);
    friend std::istream& operator>>(std::istream& in, Image& i);    
};

#endif