/*
 * TetrisGame.h
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_TETRISGAME_H_
#define TETRIS_TETRISGAME_H_
#include "Arduino.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "Environment.h"
#include "FactoriaPiezas.h"
#include "Pieza.h"
#include "Score.h"
#include "Board.h"

#define MATRIX_CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define MATRIX_LAT 33
#define MATRIX_OE  34
#define MATRIX_A   30
#define MATRIX_B   31
#define MATRIX_C   32

class Score;
class Board;
class FactoriaPiezas;
class RGBmatrixPanel;
class Pieza;
class Environment;
class TetrisGame {
public:
	TetrisGame();
	virtual ~TetrisGame();
	void loop();

	const uint8_t* getDigitBitmap(uint8_t digit);
	uint8_t drawBitmap(int x, int y, const uint8_t *bmp,  Environment::Color color) ;
	void drawPixel(int x, int y,  uint16_t color);
	Board*& getBoard() ;
	Score*& getScore() ;
	uint16_t color888(uint8_t r,uint8_t g,uint8_t b);
	uint16_t color444(uint8_t r,uint8_t g,uint8_t b);

	void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, Environment::Color color) ;

	const uint16_t getMatrixColor(Environment::Color color ) const;

	uint16_t black , yellow , darkyellow , red , white , pink ,palePink ,
				blue , cyan ,orange ,darkOrange ,green ,grey,magenta;
private:
	RGBmatrixPanel* matrix;
	Score* score;
	Board* board;
	FactoriaPiezas* factoriaPiezas;
	Pieza* pieza;
	static const uint8_t PROGMEM digit_bitmaps[] ;
	uint16_t matrixColor[10];

};

#endif /* TETRIS_TETRISGAME_H_ */
