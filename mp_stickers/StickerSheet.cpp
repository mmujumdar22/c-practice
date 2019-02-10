
#include "Image.h"
#include "StickerSheet.h"

	StickerSheet::StickerSheet(const Image &picture, unsigned max) {
    maxStickers_ = max;
    countStickers_ = 1;

    stickerArr_ = new Image[maxStickers_];
    xCoordinate_ = new int[maxStickers_];
    yCoordinate_ = new int[maxStickers_];
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
	}

	StickerSheet::StickerSheet(const StickerSheet &other) {
     maxStickers_ = other.maxStickers_;
     countStickers_ = other.countStickers_;

     stickerArr_ = new Image[maxStickers_];


     for(unsigned int i = 0; i < maxStickers_; i++)
     {
       stickerArr_[i] = other.stickerArr_[i];
     }
	}

	const StickerSheet &StickerSheet::operator=(const StickerSheet &other) {

      return *this = other;
  	// return <#initializer#>;
	}

	void StickerSheet::changeMaxStickers(unsigned max) {

	}

	int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
    stickerArr_[countStickers_] = sticker;
    xCoordinate_[countStickers_] = x;
    xCoordinate_[countStickers_] = y;
    countStickers_++;
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
      for (unsigned x = 0; x < this->width(); x++)
      {
        for (unsigned y = 0; y < this->height(); y++)
        {
          HSLAPixel & pixel = this->getPixel(x, y);
        }
      }
    }


    return final;
}
