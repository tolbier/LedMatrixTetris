/*
 * Leveler.h
 *
 *  Created on: 18 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_LEVELER_H_
#define TETRIS_LEVELER_H_
#include "TetrisGame.h"
#define LEVELER_MAX_LEVEL 10

class TetrisGame;
class Leveler {
public:
	Leveler(uint8_t level, TetrisGame* game);
	virtual ~Leveler();
	uint8_t getLevel() const;
	void changeLines(uint16_t lines);
	void loop();
	void drawLeveler() ;
	unsigned long getSpeedTime();
	void addInitLevel() ;
	void substractInitLevel() ;
private:
	uint8_t level;
	uint8_t initLevel;
	TetrisGame *game;
	void setLevel(uint8_t level);
	uint8_t getInitLevel() const;
	void setInitLevel(uint8_t initLevel);
	void drawLevelerDigit();


	static const unsigned long speedTimes[] ;
};

#endif /* TETRIS_LEVELER_H_ */
