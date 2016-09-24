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
#include "FontTomThumb.h"
#include "Environment.h"
#include "FactoriaPiezas.h"
#include "Pieza.h"
#include "Score.h"
#include "Board.h"
#include "Leveler.h"
#define INIT_LEVEL_DEMO 10
#define INIT_LEVEL_GAME 1

class Score;
class Board;
class FactoriaPiezas;
class RGBmatrixPanel;
class Pieza;
class Environment;
class Leveler;

class TetrisGame {
public:
	TetrisGame(RGBmatrixPanel* matrix, bool demo);
	virtual ~TetrisGame();
	void loop();

	const uint8_t* getDigitBitmap(uint8_t digit);
	uint8_t drawBitmap(int8_t x, int8_t y, const uint8_t *bmp,  Environment::Color color) ;
	void drawPixel(int8_t x, int8_t y,  uint16_t color);
	Board*& getBoard() ;
	Score*& getScore() ;
	uint16_t color888(uint8_t r,uint8_t g,uint8_t b);
	uint16_t color444(uint8_t r,uint8_t g,uint8_t b);

	void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, Environment::Color color) ;
	void drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2,Environment::Color color) ;
	const uint16_t getMatrixColor(Environment::Color color ) const;
	void swapBuffers(bool copy);
	void addLines(uint8_t lines);
	Leveler*& getLeveler() ;


	bool isEndOfGame() const;
	void setEndOfGame(bool endOfGame);
	bool isRequestStart() const;
	bool isDemo() const;
	bool isLevelSelection() const;
bool isGameOver() const;
	void setGameOver(bool gameOver = false);

private:
	void showGameOver();
	void treatInputDemo() ;
	void treatInputSelection();
	bool demo;
	bool levelSelection;
	bool requestStart;
	bool gameOver=false;
	bool endOfGame=false;
	RGBmatrixPanel* matrix;
	Score* score;
	Board* board;
	FactoriaPiezas* factoriaPiezas;
	Pieza* pieza;
	Pieza* nextPieza;
	static const uint8_t PROGMEM digit_bitmaps[] ;
	uint16_t matrixColor[10];

	Leveler* leveler;
};

#endif /* TETRIS_TETRISGAME_H_ */
