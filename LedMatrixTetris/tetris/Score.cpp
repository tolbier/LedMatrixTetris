/*
 * Score.cpp
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#include "Score.h"

Score::Score(TetrisGame* game) {
	this->points=0;
	this->game=game;
}

Score::~Score() {
	// TODO Auto-generated destructor stub
}

void Score::loop() {
	this->drawScore();

}

void Score::drawScore() {
	game->drawBitmap(0,0,  game->getDigitBitmap(0), game->matrix->Color888(0, 255, 0));
}
