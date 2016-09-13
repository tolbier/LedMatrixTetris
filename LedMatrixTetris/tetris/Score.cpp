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
	static unsigned long lastMillis=0;
	if (millis()-lastMillis >=100){
		addPoints(1);
		lastMillis = millis();
	}

	this->drawScore();

}

void Score::drawScore() {
	game->matrix->fillRect(0,0,5,16,game->matrix->Color888(0,0,0));
	uint16_t divisor=1000;

	for (int i=0;i<4;i++){

		uint8_t digit = (getPoints()/divisor)%10;
		game->drawBitmap(4*i,0,  game->getDigitBitmap(digit), game->matrix->Color888(0, 255, 0));
		divisor=divisor /10;
	}
}

uint16_t Score::getPoints() const {
	return points;
}

void Score::setPoints(uint16_t points) {
	this->points = points%10000;
}
void Score::addPoints(uint16_t points) {
	setPoints(getPoints()+ points);
}
