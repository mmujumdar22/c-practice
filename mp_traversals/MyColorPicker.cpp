#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;
using namespace std;

MyColorPicker::MyColorPicker(unsigned spaceBetween)
{
 	_spaceBetween = spaceBetween;
    Color1 = HSLAPixel(55,0.8,0.5);
	Color2 = HSLAPixel(200,0.8,0.3);
	Color3 = HSLAPixel(100,0.8,0.3);
	Color4 = HSLAPixel(55,0.8,0.5);
}

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
	if (x % (3 * _spaceBetween) < _spaceBetween && y % (3 * _spaceBetween) < _spaceBetween) {
	    return Color1;
	} else if(x % (3 * _spaceBetween) >= _spaceBetween && y % (3 * _spaceBetween) < _spaceBetween){
	    return Color2;
	}else if(x % (3 * _spaceBetween) < _spaceBetween && y % (3 * _spaceBetween) >= _spaceBetween){
	    return Color3;
	}else{
	    return Color4;
	}
}
