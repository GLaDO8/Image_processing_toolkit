#include <bits/stdc++.h>
#include "Image.h"
#include "ScaledImage.h"
#include "CombinedImage.h"
#include "CompositeImage.h"
#include "SquareClip.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream file(argv[1]);
	string mode;
	int width,ht,max_val;
	file>>mode>>width>>ht>>max_val;
	cout<<"Our group task ID combination is: 2,7,8"<<endl;//1,2,4,6,7,8"<<endl;
	// ofstream out1("output_task7(a)_imt2016005.ppm");
	// ofstream out2("output_task7(b)_imt2016005.ppm");
	// ofstream out3("output_task7(c)_imt2016005.ppm");
	// ofstream out4("output_task7(d)_imt2016005.ppm");
	// ofstream out5("output_task7(e)_imt2016005.ppm");
	ofstream out6("output_task7_imt2016005.ppm");
	// out1<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out2<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out3<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out4<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	// out5<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
	out6<<mode<<endl<<width<<" "<<ht<<endl<<max_val<<endl;
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
	// 		out1<<sc1->color_at(i,j);
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out2<<sc2->color_at(i,j);
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out3<<sc3->color_at(i,j);
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out4<<sc4->color_at(i,j);
	// 	}
	// }
	// for (int i = 0; i < ht; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		out5<<ci->color_at(i,j);
	// 	}
	// }
	for (int i = 0; i < ht; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			out6<<clip->color_at(i,j);
		}
	}
	return 0;
}