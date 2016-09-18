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
	setLevel(getInitLevel());
}

Leveler::~Leveler() {
	// TODO Auto-generated destructor stub
}

uint8_t Leveler::getLevel() const {
	return level;
}

void Leveler::setLevel(uint8_t level) {
	if (level>20) level=20;
	this->level = level;
}


void Leveler::changeLines(uint16_t lines) {
	uint16_t level= getInitLevel( )+(lines/10);
	if (level>20) level=20;
	setLevel(level);
}

void Leveler::loop() {
	this->drawLeveler();
}
void Leveler::drawLeveler() {

	for (int level=1;level<=this->level;level++){
		const uint8_t* pColors= getLevelColors(level);
		uint16_t color = game->color888(pColors[0],pColors[1],pColors[2]);
		game->drawPixel(coords[(level-1)*2],coords[(level-1)*2 +1],color );
	}

	drawBlinkLeveler();

}

uint8_t Leveler::getInitLevel() const {
	return initLevel;
}

void Leveler::setInitLevel(uint8_t initLevel) {
	if (!initLevel){
		initLevel=1;
	}else if (initLevel>20){
		initLevel=20;
	}
	this->initLevel = initLevel;
}

void Leveler::drawBlinkLeveler(){

	if (millis()%200 < 100 ) return ;
	game->drawPixel(coords[(level-1)*2],coords[(level-1)*2 +1],game->getMatrixColor(Environment::Color::black) );
}
const uint8_t* Leveler::getLevelColors(uint8_t level){
	return colors + ((level-1) * 3);
}
unsigned long Leveler::getSpeedTime(){
	return speedTimes[level-1];
}

const uint8_t Leveler::coords[]={

	15,31,
	15,30,
	15,29,
	15,28,
	15,27,
	14,27,
	13,27,
	12,27,
	12,28,
	12,29,
	12,30,
	12,31,
	13,31,
	14,31,
	14,30,
	14,29,
	14,28,
	13,28,
	13,29,
	13,30

};


const uint8_t Leveler::colors[]={
		0,	0,	255,
		0,	64, 255,
		0,	128,255,
		0,	192,255,
		0,	255,255,
		0,	255,192,
		0,	255,128,
		0,	255,64,
		0,	255,0,
		85,	255,0,
		170,255,0,
		255,255,0,
		255,223,0,
		255,192,0,
		255,160,0,
		255,128,0,
		255,96, 0,
		255,64,	0,
		255,32,	0,
		255,0,	0

};
const unsigned long Leveler::speedTimes[] = {
		600,
		572,
		544,
		517,
		489,
		461,
		433,
		406,
		378,
		350,
		322,
		294,
		267,
		239,
		211,
		183,
		156,
		128,
		100,
		50

};
