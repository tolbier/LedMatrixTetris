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
	uint16_t getPoints() const;
	void setPoints(uint16_t points);
	void addPoints(uint16_t points) ;
	uint16_t getLines() const;
	void setLines(uint16_t lines);
	void addLines(uint16_t lines);

private:
	uint16_t points;
	uint16_t lines;
	TetrisGame* game;

	void drawScore();
	void drawPoints() ;
	void drawLines() ;
};

#endif /* TETRIS_SCORE_H_ */
