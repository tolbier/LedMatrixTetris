/*
 * Environment.h
 *
 *  Created on: 13 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_ENVIRONMENT_H_
#define TETRIS_ENVIRONMENT_H_
#include <Arduino.h>
class Environment {

public:
	Environment();
	virtual ~Environment();
	enum  Color {black,cyan,blue,orange,yellow,green,magenta,red,grey,white};
	static const uint8_t PROGMEM digit_bitmaps[] ;
};

#endif /* TETRIS_ENVIRONMENT_H_ */
