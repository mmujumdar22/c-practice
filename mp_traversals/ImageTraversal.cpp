
#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_ = NULL;
  current_ = Point(unsigned(-1), unsigned(-1));
  visited = new bool[1];
}



/**
 * check if meetTolerance
 */
bool ImageTraversal::Iterator::meetTolerance(const Point p, const Point sp){
    //Check if this mark all the points that cab be visited
    if (p.x >= _png->width() || p.y >= _png->height())
        return false;

    HSLAPixel start = (_png->getPixel(sp.x, sp.y));
    HSLAPixel desired = (_png->getPixel(p.x, p.y));
    if (calculateDelta(desired, start) < _tolerance)
        return true;

    return false;
}

ImageTraversal::Iterator::Iterator(ImageTraversal & traversal, PNG & png, Point &start, double tolerance)
{
        traversal_ = &traversal;
        _png = &png;
        _tolerance = tolerance;
        _startPoint = start;

  current_ = traversal_ -> peek();
  visited = new bool[_png->width() * _png->height()];
  for(unsigned i = 0; i < _png->width() * _png->height(); i++){
    visited[i] = 0;
  }
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if(!traversal_ -> empty()){
    current_ = traversal_ -> pop();
    unsigned curx = current_.x;
    unsigned cury = current_.y;

    visited[curx+cury*_png->width()] = true;

    if(current_.x + 1 < _png->width()){
      Point p1 = Point(current_.x + 1, current_.y);
      if(meetTolerance(p1,_startPoint)){
        traversal_ -> add(p1);
      }
    }
    if(current_.y + 1 < _png->height()){
      Point p2=Point(current_.x, current_.y + 1);
      if(meetTolerance(p2,_startPoint)){
        traversal_ -> add(p2);
      }
    }
    if(int(current_.x - 1) >= 0){
      Point p3 = Point(current_.x - 1, current_.y);
      if(meetTolerance(p3,_startPoint)){
        traversal_ -> add(p3);
      }
    }
    if(int(current_.y - 1) >= 0){
      Point p4 = Point(current_.x, current_.y - 1);
      if(meetTolerance(p4,_startPoint)){
        traversal_ -> add(p4);
      }
    }
    current_ = traversal_ -> peek();
    while(visited[current_.x + current_.y *_png->width()] == true){
      traversal_ -> pop();
      current_ = traversal_ -> peek();
      if(int(current_.x) == -1 && int(current_.y) == -1){
        this -> current_ = Point(-1,-1);
        traversal_ -> pop();
        return * this;
      }
    }
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return Point(current_.x, current_.y);
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if(this -> current_.x == other.current_.x && this -> current_.y == other.current_.y){
    return false;
  }
  return true;
}

ImageTraversal::Iterator::~Iterator(){
  delete[] visited;
}
