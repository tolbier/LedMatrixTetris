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

	game->fillRect(0, BOARD_TOP-1,BOARD_WIDTH+2,BOARD_HEIGHT+1,Environment::Color::grey);
}

Board::~Board() {

}
void Board::fallOverLine(uint16_t line){


	for (int i=line;i>0;i--){
		for (int j=0;j<width();j++){
		  setBoardColor(j,i,this->getBoardColor(j,i-1));
		}
	}

	//rellenamos de negros la primera linea
	for (int j=0;j<width();j++){
	  setBoardColor(j,0,Environment::Color::black);
	}

}
void Board::check4Lines(int8_t firstLine,uint8_t numLines){
	int foundLines=0;
	//Comprobar las lineas que se completaron
	for (int i=0;i<numLines;i++){
		uint8_t line= firstLine + i;
		if (hasLine(line)){
			this->game->drawLine(line+BOARD_TOP,14,line+BOARD_TOP,5,Environment::Color::white);
			fallOverLine(line);
			foundLines++;;
		}
	}
	//HACER PARPADEAR LAS LINEAS
	if (foundLines){

		for (int i=0;i<6;i++){
			this->game->swapBuffers(false);
			delay(50);
		}
		game->addLines(foundLines);
	}





}
bool Board::hasLine(int8_t l){
	for (int i=0;i<width();i++){
		if (! this->getBoardColor(i,l)){
			return false;
		}
	}
	return true;

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
