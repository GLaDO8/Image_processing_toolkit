#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    float _r, _g, _b;
public:
    Color();
    Color(float, float, float);
    virtual ~Color();
    Color(const Color&);
    void set_color(float, float, float);
    float get_r() const;
    float get_g() const;
    float get_b() const;
    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    friend std::istream& operator>>(std::istream& is, Color& c);
    Color& operator=(const Color &other);
};

#endif