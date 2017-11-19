#include "Image.h"
//default constructor and deconstructor
Image::Image(){}
Image::~Image(){}
//parameterised constructor
Image::Image(int w, int h){
    width = w;
    height = h;
}
//Initialisation of the pixel array.
void Image::arrini(){
    pixarr = new Pixel*[width];
    for(int i=0; i<width; i++){
        pixarr[i] = new Pixel[height];
    }
}
//setter functions
void Image::setwidth(int w){
    width = w;
}
void Image::setheight(int h){
    height = h;
}
//set the name of the file for use in the input operator overloading
void Image::file_name_set(String name){
    filename = name;
}
//getter functions
int Image::getwidth(){
    return width;
}
int Image::getheight(){
    return height;
}
String Image::get_file_name(){
    return filename;
}
//setter and getter functions for the pixel array.
void Image::setpixarr(int i, int j, Pixel p){
    pixarr[i][j] = p;
}
Pixel Image::getpixarr(int i, int j){
    return pixarr[i][j];
}
//filtering function !!!OPTIONAL!!!
void Image::filter(Color c, float alpha){
    Color currcolor; Color *finalcolor; int r, g, b, newr, newg, newb;
    for(int i = 0; i<width; i++){
        for(int j = 0; j<height; j++){
            currcolor = pixarr[i][j].getcolor();
            newr = (1-alpha)*currcolor.getr()+alpha*c.getr();
            newb = (1-alpha)*currcolor.getb()+alpha*c.getb();
            newg = (1-alpha)*currcolor.getg()+alpha*c.getg();
            finalcolor = new Color(newr, newg, newb);
            pixarr[i][j].setcolor(*finalcolor);
        }
    }
}
//ignore this method for now
void Image::make_histogram(){
    
}
//input operator overloading
friend istream& operator >>(istream& in, Image img){
    String type; int maxcolor, h, w; Color *x; Pixel *pix;
    ifstream inputfile(img.get_file_name());
    inputfile >> type;
    inputfile >> w >> h;
    img.setwidth(w); img.setheight(h);
    inputfile >> maxcolor;
    for(int i = 0; i<img.getwidth(); i++){
        for(int j = 0; j<img.getheight(); j++){
            inputfile >>r >>g >>b;
            x = new Color(r, g, b);
            pix = new Pixel(i, j, *x);
            img.setpixarr(i, j, *pix);
            img.getpixarr(i, j).setbrightness((r+g+b)/3);
        }
    }
    return in;
}
//output operator overloading
friend ostream& operator << (ostream& out, Image img){
    ofstream outputfile("output.ppm");
    outputfile<<"P3"<<endl;
    outputfile<<img.getwidth()<< " " <<img.getheight()<<endl;
    outputfile<<"255"<<endl;
    for(int i = 0; i<img.width; i++){
        for(int j = 0; j<img.height; j++){
            outputfile<<img.pixarr[i][j].getcolor().getr()<<" "<<img.pixarr[i][j].getcolor().getg()<< " "<<img.pixarr[i][j].getcolor().getb() << " ";
        }
    }
    return out;
}
