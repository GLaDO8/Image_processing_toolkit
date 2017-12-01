#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#include "Base/color.h"
#include "Base/pixel.h"
#include "Base/image.h"

#include "image_035.h"

#include "ScaledImage.h"
#include "CombinedImage.h"
#include "SquareClip.h"

#include "noise_image.h"
#include "composite_image.h"
#include "binary_image.h"
#include "cc_image.h"

#include "Histogram.h"

using namespace std;

void task2(string);
void task7(string);
void task4(string);
void task8(string);

int main(int argc, char const *argv[])
{
	// ifstream file(argv[1]);

	// ifstream f_ptr(argv[1]); // Added by VJ
	// Image i; // Added by VJ
	// f_ptr >> i; // Added by VJ

	
	cout<<"Our group task ID combination is: 2,4,7,8"<<endl;//1,2,4,6,7,8"<<endl;
	int task; bool flag = false;
	while(true) {
		cout << "Enter task ID (0 to exit): ";
		cin >> task;
		switch(task) {
			case 2: {task2(argv[1]); break;}
			case 4: {task4(argv[1]); break;}
			case 7: {task7(argv[1]); break;}
			case 8: {task8(argv[1]); break;}
			case 0: {flag = true; break;}
			default : {cout << "Task not found!" << endl; break;}
		}
		if(flag)	break;
	}
	return 0;
}

void task2(string filename) {
	ifstream file(filename);
    Image_035* image = new Image_035();
    file >> *image;
    image->set_arr_der();
    image->reflection_y();
    Pixel** A = image->get_r_arr();
    image->min_blue();
    image->generate_C();
    image->gaussian_filter();
    Pixel** C = image->get_r_arr2();
    Image* i1 = new Image(image->get_w(),image->get_h());
    Image* i2 = new Image(image->get_w(),image->get_h());
    i1->set_arr2(C);
    i2->set_arr2(A);
    // CompositeImage *comp = new CompositeImage(i1,i2,0.75); 
    // image->set_arr2(comp->get_arr());
	composite_image* comp = new composite_image(*i1, *i2, 0.75);
	image->set_arr2(comp->get_arr());
	std::ofstream outFile("output_task2_imt2016035.ppm");
    outFile << *image;
    file.close();
    outFile.close();
}

void task7(string filename) {
	ifstream file(filename);
	string mode;
	int width,ht,max_val;
	file>>mode>>width>>ht>>max_val;


	ofstream out6("output_task7_imt2016005.ppm");
	// ofstream out61("output_task7_imt2016005a.ppm");	
	// ofstream out62("output_task7_imt2016005b.ppm");	
	// ofstream out63("output_task7_imt2016005c.ppm");	
	// ofstream out64("output_task7_imt2016005d.ppm");	
	// ofstream out65("output_task7_imt2016005e.ppm");	
		
	out6<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out61<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out62<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out63<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out64<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out65<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	Image *input = new Image(width,ht);
	for (int i = 0; i < ht; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			int r,g,b;
			file>>r>>g>>b;
			input->set_pixel(i,j,r,g,b);
		}
	}
	ScaledImage *sc1 = new ScaledImage(input);
	ScaledImage *sc2 = new ScaledImage(input,"A");
	ScaledImage *sc3 = new ScaledImage(input,"AB");
	ScaledImage *sc4 = new ScaledImage(input,"B");
	CombinedImage *ci = new CombinedImage(sc1,sc2,sc3,sc4);
	SquareClip *clip = new SquareClip(ci,min(floor(ht/2),floor(width/2)));

	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out61<<sc1->color_at(i,j)<<" ";
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out62<<sc2->color_at(i,j)<<" ";
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out63<<sc3->color_at(i,j)<<" ";
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out64<<sc4->color_at(i,j)<<" ";
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out65<<ci->color_at(i,j)<<" ";
	// 	}
	// }
	for (int i = 0; i < ht; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			out6<<clip->color_at(i,j)<<" ";
		}
	}
	file.close();
}

void task4(string input) {
	ifstream inputfile(input);
	Histogram h;
	inputfile >> h;
    h.ini_britarr();
	h.ini_local_min();
	inputfile.close();

    Histogram output = h.segmentation();
    ofstream outfile("output_task4_imt2016122.ppm");
	outfile << output << '\n';
}

void task8(string filename) {
	ifstream f_ptr(filename);
	Image i;
	f_ptr >> i;

	noise_image n(i.get_w(), i.get_h());
	// cc_image c(CompositeImage(&i, &n, 0.5));
	cc_image c(composite_image(i, n, 0.5));
	ofstream o_ptr("output_task8_imt2016083.ppm");
	o_ptr << c;

	f_ptr.close();
}