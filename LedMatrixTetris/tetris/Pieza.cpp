/*
 * Pieza.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#include "Pieza.h"


Pieza::Pieza(Environment::Color color) {
	x = 0;
	y = 0;

	this->color = color;
}

Pieza::~Pieza() {
	// TODO Auto-generated destructor stub
}

uint8_t Pieza::getX() const {
	return x;
}

void Pieza::setX(uint8_t x) {
	this->x = x;
}

uint8_t Pieza::getY() const {
	return y;
}

void Pieza::setY(uint8_t y) {
	this->y = y;
}
