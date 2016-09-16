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
	//PRUEBA
//	for(int i=19;i>=15;i--){
//		this->_board[i][4]= Environment::Color::blue;
//	}
	// FIN PRUEBA

	game->fillRect(10,4,22,12,Environment::Color::grey);
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

			this->game->drawPixel(
					BOARD_LEFT + j,
					BOARD_TOP + i,
					game->getMatrixColor(getBoardColor(j,i)));
		}

	}

}

uint8_t Board::top() {
	return BOARD_TOP;
}

uint8_t Board::left() {
	return BOARD_LEFT;
}
void Board::setBoardColor(uint8_t x, uint8_t y,Environment::Color color) {
	_board[y][x]=color;
}
Environment::Color Board::getBoardColor(uint8_t x, uint8_t y) {
	return _board[y][x];
}
bool Board::checkInbounds(int8_t x_check,int8_t y_check){
	return (x_check>=0 && x_check<this->width() &&
			y_check>=0 && y_check<this->height() );

}
