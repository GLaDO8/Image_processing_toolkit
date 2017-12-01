
# Image_processing_toolkit

## Synopsis

This Image processing toolkit is written in C++ and works on .ppm files. Its a CLI based toolkit.
.ppm files are portable pixmap format. It was created in the 80s for usage in E-mails. 
The format of a .ppm file looks like this. 
```
P3
3 2
255
#The part above is the header
#"P3" means this is a RGB colour image in ASCII
#"3 2" is the width and height of the image in pixels
#"255" is the maximum value for each colour
#The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```
**NOTE**
.ppm files are huge files because of the absence of image compression mechanisms and other file-reduction techniques. 

## Toolkit functionalities

* **TASK-4 Brightness-based image segmentation (Contributed by Shreyas Gupta)**
	Image segmentation is a partitioning process in which the image is broken down into different segments based on the parameter
    required. The parameter can be anything from brightness, specific colour etc. Our toolkit does the image segmentation based on
    brightness. The segmentation technique used is histogram based. the histogram is divided into segments based on local-minims. 
    the colouring of the segments is like the following. 
      The first 6 segments (relatively lower brightness) have the following colours. {red, green, blue, yellow, magenta, cyan} 
      the rest of the segments are coloured black.
      


* **TASK-7 Composition of scaled-reflected image and original image (Contributed by Aayush Grover)**
	The image is scaled down to 0.5 by width and height and combined 4 times (the scaled down images are reflected on each of the axis) to give a new image. This new image is then clipped 
    by a scaled down stencil.
 


* **TASK-8 Noise image connected components (Contributed by Vijay Raghavan)**
	The original image is combined with a noise image of the same and then the new image's brightness histogram is made to find out 
    the connected components which are labeled as {red, green, blue, yellow, magenta, cyan} and then the remaining as black. 
    


* **TASK-2 Gaussian filter on special reflected image (Contributed by Nikhil Pappu)**
    pixel locations in the minima 8-neighbourhood of the reflected image of the main file are marked.
    this image is modified to have the 24-neighbourhood of the marked pixels as black and the rest as white. the gaussian filter is applied
    on the marked locations and the output image is created.

## Using the tollkit
* Download all the files to a folder
* Open the terminal in the folder
* The name_of_file is the .ppm file on which the toolkit will function. the following images have been provided 
{lena.ppm, fruit.ppm, blocks.ppm, plus.ppm}
* run the following command in the terminal
```
$ g++ *.cpp -o toolkit
$ ./toolkit name_of_file 
```
* Choose the task you want to execute.

## Contributors
  * Aayush Grover
  * Vijay Raghavan
  * Shreyas Gupta
  * Nikhil Pappu

