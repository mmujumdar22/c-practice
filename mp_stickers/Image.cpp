#include <iostream>
#include <cmath>
#include <math.h>

//#include "PNG.h"
#include "Image.h"
using namespace std;
using namespace cs225;

void Image::lighten()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.l = pixel.l + 0.1;

        if(pixel.l >= 1)
          pixel.l = 1;
    }
  }
}

void Image::lighten(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.l = pixel.l + amount;
        if(pixel.l >= 1)
          pixel.l = 1;
    }
  }
}

void Image::darken()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      if(pixel.l != 0)
        pixel.l = pixel.l - 0.1;
        if(pixel.l <= 0)
          pixel.l = 0;
    }
  }
}

void Image::darken(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.l = pixel.l - amount;
      if(pixel.l <= 0)
        pixel.l = 0;
    }
  }
}

void Image::saturate()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.s = pixel.s + 0.1;
        if(pixel.l >= 1)
          pixel.l = 1;
    }
  }
}

void Image::saturate(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.s = pixel.s + amount;
        if(pixel.l >= 1)
          pixel.l = 1;
    }
  }
}

void Image::desaturate()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

        pixel.s = pixel.s - 0.1;
        if(pixel.l <= 0)
          pixel.l = 0;
    }
  }
}

void Image::desaturate(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);


        pixel.s = pixel.s - amount;

        if(pixel.l <= 0)
          pixel.l = 0;
    }
  }
}

void Image::greyscale()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);


      pixel.s = 0;
    }
  }
}

void Image::illinify()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      if(pixel.h < 113.5 || pixel.h >= 293.5) //if hue is less that 113.5 or more/= than 293.5 then the pixel should turn orange else blue
        pixel.h = 11.0;
      else
        pixel.h = 216.0;
    }
  }
}
void Image::rotateColor(double degrees)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.h = pixel.h + degrees;

      if(pixel.h < 0)
        pixel.h = pixel.h + 360;
      else
        pixel.h = remainder(pixel.h, 360.0);
    }
  }
}


void Image::scale(double factor)
{
    if(factor==1.0) {
        return;
    }

    unsigned int newWidth = this->width()*factor;
    unsigned int newHeight = this->height()*factor;

    const Image *newImage = new Image(newWidth, newHeight);
    double x_ratio = this->width()/(double)newWidth ;
    double y_ratio = this->height()/(double)newHeight ;
    double px, py ;
    for (int i=0;i<(int)newHeight;i++) {
        for (int j=0;j<(int)newWidth;j++) {
            px = floor(j*x_ratio) ;
            py = floor(i*y_ratio) ;
            newImage->getPixel(j,i) = this->getPixel(px,py);
        }
    }
    this->operator=(*newImage);
}

void Image::scale(unsigned w, unsigned h)
{
    if(this->width()==w && this->height()==h) {
        return;
    }

    unsigned int newWidth = w;//this->width()*factor;
    unsigned int newHeight = h;//this->height()*factor;

    const Image *newImage = new Image(newWidth, newHeight);
    double x_ratio = this->width()/(double)newWidth ;
    double y_ratio = this->height()/(double)newHeight ;
    double px, py ;
    for (int i=0;i<(int)newHeight;i++) {
        for (int j=0;j<(int)newWidth;j++) {
            px = floor(j*x_ratio) ;
            py = floor(i*y_ratio) ;
            newImage->getPixel(j,i) = this->getPixel(px,py);
        }
    }
    this->operator=(*newImage);
 }

Image::Image(unsigned int width, unsigned int height) : PNG(width, height) {
    PNG(width,height);
};

Image::Image(){
    PNG();
};
