/*
 * Pieza.h
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_PIEZA_H_
#define TETRIS_PIEZA_H_
#include "Arduino.h"
#include "Environment.h"
class Environment;

class Pieza {
public:
	Pieza(Environment::Color color);
	virtual ~Pieza();
	uint8_t getX() const;
	void setX(uint8_t x);
	uint8_t getY() const;
	void setY(uint8_t y);

private:
	uint8_t x,y;
	Environment::Color color;
};

#endif /* TETRIS_PIEZA_H_ */
