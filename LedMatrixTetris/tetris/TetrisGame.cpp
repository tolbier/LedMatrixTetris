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


	black = color444(0, 0, 0);
	yellow = color444(15, 15, 0);
	red = color444(15, 0, 0);
	white = color444(15, 15, 15);
	blue = color444(0, 0, 10);
	cyan = color444(0, 15, 15);
	orange = color444(15, 5, 0);
	green = color444(0, 15, 0);
	grey =  color444(1, 1, 1);
	magenta =  color888(229, 9, 127);

	matrixColor[0]=black;
	matrixColor[1]=cyan;
	matrixColor[2]=blue;
	matrixColor[3]=orange;
	matrixColor[4]=yellow;
	matrixColor[5]=green;
	matrixColor[6]=magenta;
	matrixColor[7]=red;
	matrixColor[8]=grey;
	matrixColor[9]=white;

	this->board = new Board(this);
	this->factoriaPiezas= new FactoriaPiezas(this);
	pieza=NULL;
	matrix->begin();
	score=new Score(this);
}

TetrisGame::~TetrisGame() {
	// TODO Auto-generated destructor stub
}

void TetrisGame::loop() {
	if (!pieza) pieza = factoriaPiezas->createPieza();
	score->loop();

	board->loop();
	pieza->loop();
	matrix->swapBuffers(true);
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
	0b10000000,
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

Board*& TetrisGame::getBoard()  {
	return board;
}

Score*& TetrisGame::getScore()  {
	return score;
}

uint8_t TetrisGame::drawBitmap(int x, int y, const uint8_t *bmp, Environment::Color color) {
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
				drawPixel(x+i, y + j, getMatrixColor(color));
			}
			bit--;
		}
	}
	return width;
}
void TetrisGame::drawPixel(int x, int y,  uint16_t color){
	this->matrix->drawPixel(y, matrix->height()-1-x,color);
}

uint16_t TetrisGame::color888(uint8_t r, uint8_t g, uint8_t b) {
	return this->matrix->Color888(r,g,b);
}

uint16_t TetrisGame::color444(uint8_t r, uint8_t g, uint8_t b) {
	return this->matrix->Color444(r,g,b);
}

void TetrisGame::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,Environment::Color color) {
	matrix->fillRect( x,  y,  w,  h,
			getMatrixColor( color));
}

const uint16_t TetrisGame::getMatrixColor(Environment::Color color ) const {
	return matrixColor[color] ;
}
