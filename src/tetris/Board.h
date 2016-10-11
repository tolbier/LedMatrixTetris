/*
 * Board.h
 *
 *  Created on: 13 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_BOARD_H_
#define TETRIS_BOARD_H_
#include "Arduino.h"
#include "Environment.h"
#include "TetrisGame.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BOARD_TOP 12
#define BOARD_LEFT 1

class TetrisGame;

class Board {

public:
	Board(TetrisGame* game);
	virtual ~Board();
	uint8_t width();
	uint8_t height();
	uint8_t top();
	uint8_t left();

	void drawBoard();
	void loop();
	Environment::Color getBoardColor(uint8_t x, uint8_t y);
	void setBoardColor(uint8_t x, uint8_t y,Environment::Color color);
	bool checkInbounds(int8_t x_check,int8_t y_check);
	void check4Lines(int8_t firstline,uint8_t numLines);
private:
	TetrisGame* game;
	Environment::Color _board[BOARD_HEIGHT][BOARD_WIDTH];
	void fallOverLine(uint16_t line);
	bool hasLine(int8_t l);
	void drawBorder();
	bool borderDrawn;
};

#endif /* TETRIS_BOARD_H_ */
