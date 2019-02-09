/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */
//
// #pragma once
// #ifndef IMAGE_H
// #define IMAGE_H
//
// #include "cs225/PNG.h"
//
// using namespace std;
//
//
// class Image : public cs225::PNG
// {
// public:
//   void lighten();
//   void lighten(double amount);
//   void darken();
//   void darken(double amount);
//   void saturate();
//   void saturate(double amount);
//   void desaturate();
//   void desaturate(double amount);
//   void greyscale();
//   void rotateColor(double degrees);
//   void illinify();
//   void scale(double factor);
//   void scale(unsigned w, unsigned h);
//
//   Image& operator=(const Image& d);
//   Image(unsigned int width, unsigned int height);
//   Image();
// //unsigned getPixelIndex(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
// };
//
// #endif
#include "cs225/PNG.h"

#pragma once

class Image : public cs225::PNG {

public:
    void lighten();

    void lighten(double amount);

    void darken();

    void darken(double amount);

    void saturate();

    void saturate(double amount);

    void desaturate();

    void desaturate(double amount);

    void greyscale();

    void rotateColor(double degrees);

    void illinify();

    void scale(double factor);

    void scale(unsigned w, unsigned h);

  //  Image& operator=(const Image& d);
    Image(unsigned int width, unsigned int height);
    Image();
};
