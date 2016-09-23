/*
 * LevelSelector.h
 *
 *  Created on: 23 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_LEVELSELECTOR_H_
#define TETRIS_LEVELSELECTOR_H_

#include <Arduino.h>
#define LEVEL_SELECTOR_INIT_LEVEL 1;
class RGBmatrixPanel;
class LevelSelector {
public:
	LevelSelector(RGBmatrixPanel* matrix);
	virtual ~LevelSelector();
	void loop();
private:
	RGBmatrixPanel* matrix;
	uint8_t level;
	void draw();
	const uint8_t* getDigitBitmap(uint8_t digit) ;
};

#endif /* TETRIS_LEVELSELECTOR_H_ */
