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
#define BOARD_TOP 11
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
private:
	TetrisGame* game;
	Environment::Color _board[BOARD_HEIGHT][BOARD_WIDTH];
};

#endif /* TETRIS_BOARD_H_ */
