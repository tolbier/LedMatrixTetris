/*
 * Leveler.cpp
 *
 *  Created on: 18 sept. 2016
 *      Author: toyos
 */

#include "Leveler.h"

Leveler::Leveler(uint8_t level, TetrisGame* game) {
	setInitLevel(level);
	this->game=game;

}

Leveler::~Leveler() {
	// TODO Auto-generated destructor stub
}

uint8_t Leveler::getLevel() const {
	return level;
}
void Leveler::addInitLevel() {
	setInitLevel(this->initLevel+1);
}
void Leveler::substractInitLevel() {
	setInitLevel(this->initLevel-1);
}

void Leveler::setLevel(uint8_t level) {
	if (level>LEVELER_MAX_LEVEL){
		level=LEVELER_MAX_LEVEL;
	}else if (!level) {
		level =1;
	}
	this->level = level;
}


void Leveler::changeLines(uint16_t lines) {
	uint16_t level= getInitLevel( )+(lines/10);
	setLevel(level);
}

void Leveler::loop() {
	this->drawLeveler();
}
void Leveler::drawLevelerDigit() {

	uint8_t digit = this->level%10;

	if (level>=10)game->drawBitmap(11,27,  game->getDigitBitmap(1), Environment::Color::red);
	game->drawBitmap(13,27,  game->getDigitBitmap(digit), Environment::Color::red);

}
void Leveler::drawLeveler() {

	game->fillRect(12,27, 4 ,5,Environment::Color::black);
	drawLevelerDigit();

	if 		(game->isLevelSelection() &&
			(((millis()%500)>250ul)))
			game->fillRect(12,27, 4 ,5,Environment::Color::black);



}

uint8_t Leveler::getInitLevel() const {
	return initLevel;
}

void Leveler::setInitLevel(uint8_t initLevel) {
	if (!initLevel){
		initLevel=1;
	}else if (initLevel>LEVELER_MAX_LEVEL){
		initLevel=LEVELER_MAX_LEVEL;
	}
	this->initLevel = initLevel;
	setLevel(initLevel);
}


unsigned long Leveler::getSpeedTime(){
	return speedTimes[level-1];
}


const unsigned long Leveler::speedTimes[] = {

		500, //1
		450, //2
		400, //3
		350, //4
		300, //5
		250, //6
		200, //7
		150, //8
		100, //9
		50	//10

};
