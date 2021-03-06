/*
 * FactoriaPiezas.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#include "FactoriaPiezas.h"

FactoriaPiezas::FactoriaPiezas(TetrisGame* game) {
	this->game=game;


}

FactoriaPiezas::~FactoriaPiezas() {
	// TODO Auto-generated destructor stub
}

Pieza* FactoriaPiezas::createPieza() {
	//return new Pieza(random(Environment::Color::red +1),this);
	Pieza* pieza= new Pieza(random(Environment::Color::red)+1,this);
	return pieza;
}
const uint8_t* FactoriaPiezas::profiles_data[]={
		pieza_bitmaps,
		pieza_bitmaps+11,
		pieza_bitmaps+31,
		pieza_bitmaps+51,
		pieza_bitmaps+57,
		pieza_bitmaps+68,
		pieza_bitmaps+79


};

const uint8_t PROGMEM FactoriaPiezas::pieza_bitmaps[] = {

	1,
	2,
	4,1,
	0b11110000,
	2,4,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,

	2,
	4,
	3,2,
	0b10000000,
	0b11100000,
	3,3,
	0b01100000,
	0b01000000,
	0b01000000,
	3,2,
	0b11100000,
	0b00100000,
	3,3,
	0b00100000,
	0b00100000,
	0b01100000,

	3,
	4,
	3,2,
	0b00100000,
	0b11100000,
	3,3,
	0b01000000,
	0b01000000,
	0b01100000,
	3,2,
	0b11100000,
	0b10000000,
	3,3,
	0b01100000,
	0b00100000,
	0b00100000,

	4,
	1,
	3,2,
	0b01100000,
	0b01100000,

	5,
	2,
	3,2,
	0b01100000,
	0b11000000,
	3,3,
	0b01000000,
	0b01100000,
	0b00100000,

	6,
	2,
	3,2,
	0b11000000,
	0b01100000,
	3,3,
	0b00100000,
	0b01100000,
	0b01000000,

	7,
	4,
	3,2,
	0b01000000,
	0b11100000,
	3,3,
	0b01000000,
	0b01100000,
	0b01000000,
	3,2,
	0b11100000,
	0b01000000,
	3,3,
	0b00100000,
	0b01100000,
	0b00100000

};

const uint8_t* FactoriaPiezas::getProfile(int tipoPieza) const {
	return this->profiles_data[tipoPieza-1];
}

TetrisGame*& FactoriaPiezas::getGame()  {
	return game;
}
