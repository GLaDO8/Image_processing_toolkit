#ifndef COMPOSITE_IMAGE
#define COMPOSITE_IMAGE

class composite_image : public Image {
public:
    composite_image(const Image& i1, const Image& i2, float a);
};

#endif