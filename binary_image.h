#ifndef BINARY_IMAGE
#define BINARY_IMAGE

class binary_image: public Image {
public:
    binary_image(Image i, int treshold);
private:
    void binarize(int treshold);
    // int get_brightness(const Color& c);
};

#endif