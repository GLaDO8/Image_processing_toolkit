#ifndef BINARY_IMAGE
#define BINARY_IMAGE

class binary_image: public Image {
public:
    binary_image(Image i, int treshold);
    int** get_bin_arr() const;
private:
    int** _bin_arr;
    void binarize(int treshold);
    // int get_brightness(const Color& c);
};

#endif