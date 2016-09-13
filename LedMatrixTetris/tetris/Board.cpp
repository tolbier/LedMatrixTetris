/*
 * Board.cpp
 *
 *  Created on: 13 sept. 2016
 *      Author: toyos
 */

#include "Board.h"

Board::Board(TetrisGame* game) {
	this->game = game;
	for (int i=0;i<height();i++){
		for (int j=0;j<width();j++){
			this->_board[i][j]= Environment::Color::black;

		}

	}
	game->matrix->fillRect(10,4,22,12,game->grey);
}

Board::~Board() {

}

uint8_t Board::width() {
	return BOARD_WIDTH;
}

uint8_t Board::height() {
	return BOARD_HEIGHT;
}
void Board::loop() {
	this->drawBoard();
}
void Board::drawBoard() {

	for (int i=0;i<height();i++){
		for (int j=0;j<width();j++){

			this->game->matrix->drawPixel(
					BOARD_TOP + i,
					BOARD_LEFT - j,
					game->matrixColor[getBoardColor(j,i)]);
		}

	}

}

Environment::Color Board::getBoardColor(uint8_t x, uint8_t y) {
	return _board[y][x];
}
