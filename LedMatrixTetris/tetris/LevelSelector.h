/*
 * LevelSelector.h
 *
 *  Created on: 23 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_LEVELSELECTOR_H_
#define TETRIS_LEVELSELECTOR_H_
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h>
class LevelSelector {
public:
	LevelSelector(RGBmatrixPanel* matrix);
	virtual ~LevelSelector();
	void loop();
private:
	RGBmatrixPanel* matrix;
};

#endif /* TETRIS_LEVELSELECTOR_H_ */
