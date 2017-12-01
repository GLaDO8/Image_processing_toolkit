#ifndef SCALEDIMAGE_H_
#define SCALEDIMAGE_H_

class ScaledImage : public Image
{
protected:
    std::string type;
public:
    ScaledImage();
    ScaledImage(Image *ing);
    ScaledImage(Image *img, std::string s);
};

#endif