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
