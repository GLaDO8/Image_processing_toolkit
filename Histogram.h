#ifndef __HISTOGRAM_H_INCLUDED__
#define __HISTOGRAM_H_INCLUDED__

using namespace std;
class Histogram: public Image{
    //britarr is an int array which will have a count of the number of pixels with THAT specific brightness.
    //colorarr is an array with all the colors which will denote the image segmentation.
    //local_min will store all the local minimas of the histogram.
    private:
        int britarr[256];
        vector<int> local_min;
        Color colorarr[7];
    public:
        Histogram();
        Histogram(int w, int h);
        ~Histogram();
        void ini_britarr();
        void ini_local_min();
        Histogram segmentation();
        int get_brightness(int i, int j);
};
#endif
