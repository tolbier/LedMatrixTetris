/*
 * Score.cpp
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#include "Score.h"

Score::Score(TetrisGame* game) {
	this->points=0;
	this->lines=0;

	this->game=game;
}

Score::~Score() {
	// TODO Auto-generated destructor stub
}

void Score::loop() {
	this->drawScore();
}
void Score::drawPoints() {
	game->fillRect(0,0,16,5,Environment::Color::black);
		uint16_t divisor=1000;

		for (int i=0;i<4;i++){

			uint8_t digit = (getPoints()/divisor)%10;
			game->drawBitmap(4*i,0,  game->getDigitBitmap(digit), Environment::Color::green);
			divisor=divisor /10;
		}
}
void Score::drawLines() {
	game->fillRect(0,6,16,5,Environment::Color::black);
		uint16_t divisor=100;

		for (int i=0;i<3;i++){
			uint8_t digit = (getLines()/divisor)%10;
			game->drawBitmap(4*(i +1),6,  game->getDigitBitmap(digit), Environment::Color::blue);
			divisor=divisor /10;
		}
}

void Score::drawScore() {
	drawPoints();
	drawLines();
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

uint16_t Score::getLines() const {
	return lines;
}

void Score::addLines(uint16_t lines) {
	this->lines += lines;
}
