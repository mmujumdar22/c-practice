//
// #include "Image.h"
// #include "StickerSheet.h"
//
// 	StickerSheet::StickerSheet(const Image &picture, unsigned max) {
//     maxStickers_ = max;
//     countStickers_ = 1;
//
//     stickerArr_ = new Image[maxStickers_];
//     xCoordinate_ = new int[maxStickers_];
//     yCoordinate_ = new int[maxStickers_];
//     stickerArr_[0] = picture;
//     xCoordinate_[0] = 0;
//     yCoordinate_[0] = 0;
//     //
//     // for(int i = 1; i < maxStickers_; i++)
//     // {
//     //   stickerArr_[i] = NULL;
//     // }
//
//
// 	}
//
// 	StickerSheet::~StickerSheet() {
//        delete[] stickerArr_;
// 	}
//
// 	StickerSheet::StickerSheet(const StickerSheet &other) {
//      maxStickers_ = other.maxStickers_;
//      countStickers_ = other.countStickers_;
//
//      stickerArr_ = new Image[maxStickers_];
//
//
//      for(unsigned int i = 0; i < maxStickers_; i++)
//      {
//        stickerArr_[i] = other.stickerArr_[i];
//      }
// 	}
//
// 	const StickerSheet &StickerSheet::operator=(const StickerSheet &other) {
//
//       return *this = other;
//   	// return <#initializer#>;
// 	}
//
// 	void StickerSheet::changeMaxStickers(unsigned max) {
//
// 	}
//
// 	int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
//     stickerArr_[countStickers_] = sticker;
//     xCoordinate_[countStickers_] = x;
//     xCoordinate_[countStickers_] = y;
//     countStickers_++;
//     return countStickers_;
// 	}
//
//
// 	bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
// 		return false;
// 	}
//
// 	void StickerSheet::removeSticker(unsigned index) {
//
// 	}
//
// 	Image* StickerSheet::getSticker(unsigned index) {
//     if(index <= maxStickers_)
//       return &stickerArr_[index];
//     else
//       return nullptr;
// 	}
//
// 	Image StickerSheet::render() const {
//
//     Image final = stickerArr_[0];
//
//     for(unsigned int i = 1; i < countStickers_; i++)
//     {
//       for (unsigned x = 0; x < this->width(); x++)
//       {
//         for (unsigned y = 0; y < this->height(); y++)
//         {
//           HSLAPixel & pixel = this->getPixel(x, y);
//         }
//       }
//     }
//
//
//     return final;
// }
#include "cs225/PNG.h"
#include "Image.h"
#include "StickerSheet.h"
#include <iostream>

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
	maxStickers_ = max;
	countStickers_ = 1;

	stickerArr_ = new Image[maxStickers_];
	xCoordinate_ = new unsigned[maxStickers_]();
	yCoordinate_ = new unsigned[maxStickers_]();
	stickerArr_[0] = picture;
	xCoordinate_[0] = 0;
	yCoordinate_[0] = 0;
	//
	// for(int i = 1; i < maxStickers_; i++)
	// {
	//   stickerArr_[i] = NULL;
	// }


}

StickerSheet::~StickerSheet() {
	delete[] stickerArr_;
	delete[] xCoordinate_;
	delete[] yCoordinate_;
}



StickerSheet::StickerSheet(const StickerSheet & other) {
	// Clear self
	delete[] stickerArr_;
	delete[] xCoordinate_;
	delete[] yCoordinate_;
	std::cout << "Copy constructor" << std::endl;

	// Copy `other` to self
	copy(other);
}

const StickerSheet &StickerSheet::operator=(const StickerSheet & other) {

	if (this != &other) {
		// Copy `other` to self
       copy(other);
	}
	return *this;
}

void StickerSheet::changeMaxStickers(unsigned max)
{
//	StickerSheet changedMax = new StickerSheet(*this->, max);
 Image *changedMax = new Image[max];
	//int newXCoor =
 int* newX = new int[max];
 int* newY = new int[max];
 int* newC = new int[max];
 unsigned newStickerCount = 0;
 StickerSheet* newStickerSheet = new StickerSheet(stickerArr_[0],max);

 if (max < maxStickers_)
 {

	 for (unsigned i = 1; i < max; i++)
	 {
		 newStickerSheet->addSticker(stickerArr_[i], xCoordinate_[i], yCoordinate_[i]);

		 // if (count[i] != 0) {
			//  delete stickerArr_[i];
			 // stickerArr_[i] = NULL;
			 // count[i]--;
		// }
	 }
	 // for(unsigned j = max; j < maxStickers_; j++ )
	 // {
		//  delete stickerArr_[j];
	 // }
	// maxStickers_ = max;
 }

 if (max > maxStickers_) {
	 // for (unsigned i = 0; i < max; i++){
		// 	 changedMax[i] = NULL;
		// 	 newC[i] = 0;
		//  }
	// }
	 for (unsigned i = 1; i < maxStickers_; i++)
	 {
		 // if (count[i]!=0){
			 // changedMax[i] = new Image(*stickerArr_[i]);
			 // newX[i] = xCoordinate_[i];
			 // newY[i] = yCoordinate_[i];
			 // newC[i] = count[i];
			 // newSticker_ct++;
		 newStickerSheet->addSticker(stickerArr_[i], xCoordinate_[i], yCoordinate_[i]);
		 //}
		 // else{
			//  newC[i] = 0;
		 // }
	 }
    this->operator=(*newStickerSheet);
 // _destroy();
 // sticker_max = max;
 // stickers = changedMax;
 // xCoordinate_ = newX;
 // yCoordinate_ = newY;
 // count = newC;
 // countStickers_ = newSticker_ct;
 // picture = newPicture;
}
}

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
	stickerArr_[countStickers_].operator=(sticker);
	xCoordinate_[countStickers_] = x;
	yCoordinate_[countStickers_] = y;
	//std::cout << xCoordinate_[countStickers_] << " " << yCoordinate_[countStickers_] << std::endl;
	countStickers_++;
	std::cout << "addSticker" << std::endl;
	return countStickers_;
}


bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
	return false;
}

void StickerSheet::removeSticker(unsigned index) {

}

Image* StickerSheet::getSticker(unsigned index) {
	if(index <= maxStickers_)
		return &stickerArr_[index];
	else
		return nullptr;
}

Image StickerSheet::render() const {

	Image final = stickerArr_[0];

	for(unsigned int i = 1; i < countStickers_; i++)
	{
		Image nextImage = stickerArr_[i];
		unsigned nextImageWidth = nextImage.width();
		unsigned nextImageHeight = nextImage.height();

	//	std::cout << " render "<< nextImageHeight << " " << nextImageWidth << std::endl;
		for (unsigned x = 0; x < nextImageWidth; x++)
		{
			for (unsigned y = 0; y < nextImageHeight; y++)
			{
				unsigned startxPosition = xCoordinate_[i];
				unsigned startyPosition = yCoordinate_[i];
				//std::cout << startxPosition << " " << startyPosition << std::endl;
				if(startxPosition + x <= final.width() && startyPosition <= final.height()){

					final.getPixel(startxPosition+x, startyPosition+y) = nextImage.getPixel(x, y);
				//	std::cout << __LINE__ << std::endl;
				//	std::cout << startxPosition + x<< ", " << startyPosition + y<< "  ";
				}
			}
		}
	}


	return final;
}

void StickerSheet::copy(StickerSheet const & other) {
	maxStickers_ = other.maxStickers_;
	countStickers_ = other.countStickers_;
	stickerArr_ = new Image[maxStickers_];

	for(unsigned int i = 0; i < maxStickers_; i++)
	{
		stickerArr_[i] = other.stickerArr_[i];
		xCoordinate_[i] = other.xCoordinate_[i];
		yCoordinate_[i] = other.yCoordinate_[i];
	}
}
//clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o
//clang++ .objs/Image.o .objs/StickerSheet.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-part1.o .objs/tests/tests-part2.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -o test
