/*
 * TetrisGame.cpp
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#include "TetrisGame.h"

TetrisGame::TetrisGame() {
	this->matrix= new RGBmatrixPanel(
			MATRIX_A,
			MATRIX_B,
			MATRIX_C,
			MATRIX_CLK,
			MATRIX_LAT,
			MATRIX_OE,
			true);


	matrix->begin();
	score=new Score(this);
}

TetrisGame::~TetrisGame() {
	// TODO Auto-generated destructor stub
}

void TetrisGame::loop() {
	//matrix->drawPixel(0, 0, matrix->Color888(255, 255, 255));
	score->loop();
	matrix->swapBuffers(false);
}

const uint8_t PROGMEM TetrisGame::digit_bitmaps[] = {
	//0
	3,5,
	0b11100000,
	0b10100000,
	0b10100000,
	0b10100000,
	0b11100000,
	//1
	3,5,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	//2
	3,5,
	0b11100000,
	0b00100000,
	0b11100000,
	0b10000000,
	0b11100000,
	//3
	3,5,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00100000,
	0b11100000,
	//4
	3,5,
	0b10100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000,
	//5
	3,5,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b11100000,
	//6
	3,5,
	0b11100000,
	0b10000000,
	0b11100000,
	0b10100000,
	0b11100000,
	//7
	3,5,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	//8
	3,5,
	0b11100000,
	0b10100000,
	0b11100000,
	0b10100000,
	0b11100000,
	//9
	3,5,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000

	};

const uint8_t* TetrisGame::getDigitBitmap(uint8_t digit) {
	return this->digit_bitmaps + digit*7;
}

uint8_t TetrisGame::drawBitmap(int x, int y, const uint8_t *bmp, uint16_t color) {
	uint8_t width = pgm_read_byte(bmp);
	uint8_t height = pgm_read_byte(bmp + 1);
	const unsigned char *p = bmp + 2;
	uint8_t b;
	uint8_t bit;

	for (uint8_t j = 0; j < height; j++) {
		for (uint8_t i = 0; i < width; i++) {
			if ((i % 8) == 0) {
				b = pgm_read_byte(p);
				p++;
				bit = 7;
			}
			if ((b >> bit) & 0x1) {
				matrix->drawPixel(y + j, 15-x - i, color);
			}
			bit--;
		}
	}
	return width;
}
