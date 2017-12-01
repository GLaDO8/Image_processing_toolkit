# Image_processing_toolkit

## Synopsis

This Image processing toolkit is written in C++ and works on .ppm files. 
.ppm files are portable pixmap format. It was created in the 80s for usage in E-mails. 
The format of a .ppm file looks like this. 
```
P3
3 2
255
#The part above is the header
#"P3" means this is a RGB color image in ASCII
#"3 2" is the width and height of the image in pixels
#"255" is the maximum value for each color
#The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```
**NOTE**

.ppm files are huge files because of the absense of image compression mechanisms and other file-reduction techniques. 

## Toolkit functionalities

 * **Brightness-based image segmentation (Contributed by Shreyas Gupta)**
 
    Image segmentation is a partitioning process in which the image is broken down into different segments based on the parameter
    required. The parameter can be anything from brightness, specific color etc. Our toolkit does the image segmentation based on
    brightness. The segmentation technique used is histogram based. the histogram is divided into segments based on local-minimas. 
    the colouring of the segments is like the following. 
      The first 6 segments (relatively lower brightness) have the following colors. {red, green, blue, yellow, magenta, cyan} 
      the rest of the segments are coloured black.
      
* **Composition of scaled-reflected image and original image (Contributed by Aayush Grover)**

    The image is scaled down to 0.5 by width and height and combined 4 times (the scaled down images are reflected on each of the axis) to give a new image. This new image is then clipped 
    by a scaled down stencil.
 
* **Noise image connected components (Contributed by Vijay Raghavan)**

    The original image is combined with a noise image of the same and then the new image's brightness histogram is made to find out 
    the connected components which are labeled as {red, green, blue, yellow, magenta, cyan} and then the remaining as black. 
    
* **Gaussian filter on special reflected image (Contributed by Nikhil Pappu)**

    Pixel locations in the minima 8-neighbourhood of the reflected image of the main file are marked.
    this image is modified to have the 24-neighbourhood of the marked pixels as black and the rest as white. the gaussian filter is applied
    on the marked locations and the output image is created.
    
## Contributors
  * Aayush Grover (IMT2016005)
  * Vijay Raghavan (IMT2016083)
  * Shreyas Gupta (IMT2016122)
  * Nikhil Pappu (IMT2016035)
