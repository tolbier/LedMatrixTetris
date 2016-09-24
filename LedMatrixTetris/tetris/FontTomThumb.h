/*
 * FontTomThumb.h
 *
 *  Created on: 24 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_FONTTOMTHUMB_H_
#define TETRIS_FONTTOMTHUMB_H_
#include <Adafruit_GFX.h>
#define TOMTHUMB_USE_EXTENDED 0
class FontTomThumb {
public:
	FontTomThumb();
	virtual ~FontTomThumb();
	static const GFXfont TomThumb PROGMEM ;
private:
	static const uint8_t TomThumbBitmaps[] PROGMEM ;
	static const GFXglyph TomThumbGlyphs[] PROGMEM ;
};

#endif /* TETRIS_FONTTOMTHUMB_H_ */
