/*
 * TetrisGame.cpp
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#include "TetrisGame.h"

TetrisGame::TetrisGame(RGBmatrixPanel* matrix, bool demo) {

	this->matrix = matrix;

	matrixColor[Environment::Color::black]=color444(0, 0, 0);
	matrixColor[Environment::Color::cyan]=color444(0, 15, 15);;
	matrixColor[Environment::Color::blue]=color444(0, 0, 15);
	matrixColor[Environment::Color::orange]=color444(15, 7, 0);;
	matrixColor[Environment::Color::yellow]=color444(15, 15, 0);
	matrixColor[Environment::Color::green]=color444(0, 15, 0);
	matrixColor[Environment::Color::magenta]=color888(153, 6, 85);
	matrixColor[Environment::Color::red]=color444(10, 0, 0);
	matrixColor[Environment::Color::grey]=color444(1, 1, 1);
	matrixColor[Environment::Color::white]=color444(15, 15, 15);

	this->board = new Board(this);
	this->factoriaPiezas= new FactoriaPiezas(this);
	pieza=NULL;

	score=new Score(this);
	leveler = new Leveler(DEMO_LEVEL,this);
	nextPieza = factoriaPiezas->createPieza();
	this->demo = demo;
	this->requestStart=false;

}

TetrisGame::~TetrisGame() {
	//if (pieza)	delete pieza;
	if (nextPieza)	delete nextPieza;
	if (score) delete score;
	if (factoriaPiezas) delete factoriaPiezas;
	if (leveler) delete leveler;
	if (board) delete board;

}
void TetrisGame::treatInputDemo() {

	 while (Serial.available()) {
	    // get the new byte:
	    char inChar = (char)Serial.read();
	    if ( 	(inChar=='A'|| inChar=='a')||
	    		(inChar=='d' || inChar=='D')||
				(inChar=='w' || inChar=='W') ||
				(inChar=='s' || inChar=='S')){
	    	this->requestStart = true;
	    }

	  }
}
void TetrisGame::loop() {
	if (!pieza){
		//TODO refactorizar esté código
		pieza = nextPieza;
		if (!pieza->libre()){
			setEndOfGame(true);
			return;
		}
		pieza->setPrevia(false);
		nextPieza = factoriaPiezas->createPieza();
	}


	board->loop();
	pieza->loop();
	nextPieza->loop();
	if (pieza->isParada()){
		delete pieza;
		pieza=NULL;
	}
	leveler->loop();
	score->loop();
	if (this->isDemo()){
		treatInputDemo();
	}

}

const uint8_t* TetrisGame::getDigitBitmap(uint8_t digit) {
	return Environment::digit_bitmaps + digit*7;
}

Board*& TetrisGame::getBoard()  {
	return board;
}

Score*& TetrisGame::getScore()  {
	return score;
}

uint8_t TetrisGame::drawBitmap(int8_t x, int8_t y, const uint8_t *bmp, Environment::Color color) {
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
void TetrisGame::drawPixel(int8_t x, int8_t y,  uint16_t color){
	this->matrix->drawPixel(x, y,color);
}

uint16_t TetrisGame::color888(uint8_t r, uint8_t g, uint8_t b) {
	return this->matrix->Color888(r,g,b);
}

uint16_t TetrisGame::color444(uint8_t r, uint8_t g, uint8_t b) {
	return this->matrix->Color444(r,g,b);
}

void TetrisGame::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,Environment::Color color) {
	matrix->fillRect( x, y,  w, h,
			getMatrixColor( color));
}
void TetrisGame::drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2,Environment::Color color) {
	matrix->drawLine(x1,y1,x2,y2,getMatrixColor( color));
}

const uint16_t TetrisGame::getMatrixColor(Environment::Color color ) const {
	return matrixColor[color] ;
}
void TetrisGame::swapBuffers(bool copy){
	this->matrix->swapBuffers(copy);
}


void TetrisGame::addLines(uint8_t lines){
	this->getScore()->addLines(lines);
	getLeveler()->changeLines(getScore()->getLines());

}

Leveler*& TetrisGame::getLeveler()  {
	return leveler;
}

bool TetrisGame::isEndOfGame() const {
	return endOfGame;
}

void TetrisGame::setEndOfGame(bool endOfGame) {
	this->endOfGame = endOfGame;
	}

	bool TetrisGame::isRequestStart() const {
		return requestStart;
	}
