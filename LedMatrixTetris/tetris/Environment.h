/*
 * Environment.h
 *
 *  Created on: 13 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_ENVIRONMENT_H_
#define TETRIS_ENVIRONMENT_H_

class Environment {

public:
	Environment();
	virtual ~Environment();
	enum  Color {black,cyan,blue,orange,yellow,green,magenta,red};
};

#endif /* TETRIS_ENVIRONMENT_H_ */
