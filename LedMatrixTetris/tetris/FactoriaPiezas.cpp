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
	return new Pieza((Environment::Color)1);
}

const uint8_t PROGMEM FactoriaPiezas::pieza_bitmaps[] = {

	0,
	2,
	1,4,
	0b10000000,
	0b10000000,
	0b10000000,
	0b10000000,
	4,1,
	0b11110000,

	//1
	3,5,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	0b01000000,
	//2
	3,5,
	0b11100000,
	0b00100000,
	0b11100000,
	0b10000000,
	0b11100000,
	//3
	3,5,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00100000,
	0b11100000,
	//4
	3,5,
	0b10100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000,
	//5
	3,5,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00100000,
	0b11100000,
	//6
	3,5,
	0b11100000,
	0b10000000,
	0b11100000,
	0b10100000,
	0b11100000,
	//7
	3,5,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	//8
	3,5,
	0b11100000,
	0b10100000,
	0b11100000,
	0b10100000,
	0b11100000,
	//9
	3,5,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000

	};
