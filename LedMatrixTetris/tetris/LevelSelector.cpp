/*
 * LevelSelector.cpp
 *
 *  Created on: 23 sept. 2016
 *      Author: toyos
 */

#include "LevelSelector.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
LevelSelector::LevelSelector(RGBmatrixPanel* matrix) {
	this->matrix = matrix;
	this->level=LEVEL_SELECTOR_INIT_LEVEL;

}

LevelSelector::~LevelSelector() {
	// TODO Auto-generated destructor stub
}

void LevelSelector::loop() {
//	matrix->fillScreen(matrix->Color888(255,255,0));
//
//	matrix->swapBuffers(true);
	this->draw();
}



void LevelSelector::draw() {
	matrix->fillRect(12,27, 4 ,5,matrix->Color888(0,0,0));
	uint8_t digit = this->level%10;

	if (level>=10)
		matrix->drawBitmap(11,27,  getDigitBitmap(1), matrix->Color888(255,0,0));
	matrix->drawBitmap(13,27,  getDigitBitmap(digit), matrix->Color888(255,0,0));


}
const uint8_t* LevelSelector::getDigitBitmap(uint8_t digit) {
	return Environment::digit_bitmaps + digit*7;
}
