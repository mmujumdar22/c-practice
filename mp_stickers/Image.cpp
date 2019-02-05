#include <iostream>
using namespace cs225;
#include "png.h"

Image::lighten()
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.l = pixel.l + 0.1;

    }
  }
}

Image::lighten(double amount)
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.l = pixel.l + amount;

    }
  }
}

Image::darken()
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.l = pixel.l - 0.1;

    }
  }
}

Image::darken(double amount)
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.l = pixel.l - amount;

    }
  }
}

Image::saturate()
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.s = pixel.s + 0.1;

    }
  }
}

Image::saturate(double amount)
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.s = pixel.s + amount;

    }
  }
}

Image::desaturate()
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.s = pixel.s - 0.1;

    }
  }
}

Image::desaturate(double amount)
{
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.s = pixel.s - amount;

    }
  }
}
