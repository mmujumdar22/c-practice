#include <iostream>
#include <cmath>
using namespace cs225;
#include "png.h"

void Image::lighten()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.l = pixel.l + 0.1;

    }
  }
}

void Image::lighten(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.l = pixel.l + amount;

    }
  }
}

void Image::darken()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.l = pixel.l - 0.1;

    }
  }
}

void Image::darken(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.l = pixel.l - amount;

    }
  }
}

void Image::saturate()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.s = pixel.s + 0.1;

    }
  }
}

void Image::saturate(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.s = pixel.s + amount;

    }
  }
}

void Image::desaturate()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.s = pixel.s - 0.1;

    }
  }
}

void Image::desaturate(double amount)
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);

      pixel.s = pixel.s - amount;

    }
  }
}
void Image::scale(double factor)
{
  int newWidth = this->width()*factor;
  int newHeight = this->height()*factor;

  PNG image = new PNG(newWidth,newHeight);

  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      


    }
  }
}
