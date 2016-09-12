/*
 * Score.h
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_SCORE_H_
#define TETRIS_SCORE_H_
#include "Arduino.h"
#include "TetrisGame.h"

class TetrisGame;
class Score {
public:
	Score(TetrisGame* game);
	virtual ~Score();

	void loop();
private:
	uint8_t points;
	TetrisGame* game;

	void drawScore();
};

#endif /* TETRIS_SCORE_H_ */
