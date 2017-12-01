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

 * Brightness-based image segmentation.
    Image segmentation is a partitioning process in which the image is broken down into different segments based on the parameter
    required. The parameter can be anything from brightness, specific color etc. Our toolkit does the image segmentation based on
    brightness. The segmentation technique used is histogram based. the histogram is divided into segments based on local-minimas. 
    the colouring of the segments is like the following. 
      The first 6 segments (relatively lower brightness) have the following colors. {red, green, blue, yellow, magenta, cyan} 
      the rest of the segments are coloured black.
      
* Image-scaling+refection+composition
    the image is scaled down to 0.5 by width and height and combined 4 times to give a new image. This new image is then clipped 
    by a scaled down stencil.
 
* Noise image connected components
    The original image is combined with a noise image of the same and then the new image's brightness histogram is made to find out 
    the connected components which are labeled as {red, green, blue, yellow, magenta, cyan} and then the remaining as black. 
    
* Gaussian filter on special reflected image
    pixel locations in the minima 8-neighborhood of the reflected image of the main file are marked.
    this image is modified to have the 24-neighborhood of the marked pixels as black and the rest as white. the guassian filter is applied
    on the marked locations and the output image is created.
    
## Contributors
  
