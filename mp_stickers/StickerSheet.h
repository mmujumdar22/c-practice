
/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */

// #include "Image.h"
// #pragma once
//
//
//
// class StickerSheet {
// private:
//
//   unsigned int maxStickers_;
//   unsigned int countStickers_;
//   Image *stickerArr_;
//   int *xCoordinate_;
//   int *yCoordinate_;
// public:
//
// 	//Initializes this StickerSheet with a base picture and the ability to hold a max number of stickers (Images) with indices 0 through max - 1. More...
//  	StickerSheet (const Image &picture, unsigned max);
//
//  	//Frees all space that was dynamically allocated by this StickerSheet. More...
//  	~StickerSheet ();
//
//  	//The copy constructor makes this StickerSheet an independent copy of the source. More...
//  	StickerSheet (const StickerSheet &other);
//
//  	//The assignment operator for the StickerSheet class. More...
//  	const StickerSheet & 	operator= (const StickerSheet &other);
//
//  	//Modifies the maximum number of stickers that can be stored on this StickerSheet without changing existing stickers' indices. More...
//  	void changeMaxStickers (unsigned max);
//
//  	// 	Adds a sticker to the StickerSheet, so that the top-left of the sticker's Image is at (x, y) on the StickerSheet. More...
// 	int addSticker (Image &sticker, unsigned x, unsigned y);
//  	//Changes the x and y coordinates of the Image in the specified layer. More...
// 	bool translate (unsigned index, unsigned x, unsigned y);
//
//  	//	Removes the sticker at the given zero-based layer index. More...
// 	void removeSticker (unsigned index);
//
//  	//Returns a pointer to the sticker at the specified index, not a copy of it. More...
//
// 	Image * getSticker (unsigned index);
//
// 	Image 	render () const;
// };

#include "Image.h"
#pragma once



class StickerSheet {
private:

	unsigned maxStickers_;
	unsigned countStickers_;
	Image *stickerArr_;
	unsigned *xCoordinate_;
	unsigned *yCoordinate_;
	// int *count;
	// Image *picture;
public:

	//Initializes this StickerSheet with a base picture and the ability to hold a max number of stickers (Images) with indices 0 through max - 1. More...
	StickerSheet (const Image &picture, unsigned max);

	//Frees all space that was dynamically allocated by this StickerSheet. More...
	~StickerSheet ();

	void copy(StickerSheet const & other);

	//The copy constructor makes this StickerSheet an independent copy of the source. More...
	StickerSheet (const StickerSheet &other);

	//The assignment operator for the StickerSheet class. More...
	const StickerSheet & 	operator= (const StickerSheet &other);

	//Modifies the maximum number of stickers that can be stored on this StickerSheet without changing existing stickers' indices. More...
	void changeMaxStickers (unsigned max);

	// 	Adds a sticker to the StickerSheet, so that the top-left of the sticker's Image is at (x, y) on the StickerSheet. More...
	int addSticker (Image &sticker, unsigned x, unsigned y);
	//Changes the x and y coordinates of the Image in the specified layer. More...
	bool translate (unsigned index, unsigned x, unsigned y);

	//	Removes the sticker at the given zero-based layer index. More...
	void removeSticker (unsigned index);

	//Returns a pointer to the sticker at the specified index, not a copy of it. More...

	Image * getSticker (unsigned index);

	Image 	render () const;
};
