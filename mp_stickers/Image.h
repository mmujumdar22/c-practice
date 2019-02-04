/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include "png.h"

class Image : public PNG
{
  void lighten();
  void darken();
  void darken(double amount);
  void saturate();
  void saturate(double amount);
  void desaturate();
  void greyscale();
  void rotateColor(double degrees);
  void illinify();
  void scale(double factor);
  void scale(unsigned w, unsinged h);
}
#endif
