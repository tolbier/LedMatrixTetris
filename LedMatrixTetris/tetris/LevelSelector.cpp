/*
 * LevelSelector.cpp
 *
 *  Created on: 23 sept. 2016
 *      Author: toyos
 */

#include "LevelSelector.h"

LevelSelector::LevelSelector(RGBmatrixPanel* matrix) {
	this->matrix = matrix;

}

LevelSelector::~LevelSelector() {
	// TODO Auto-generated destructor stub
}

void LevelSelector::loop() {
	matrix->fillScreen(matrix->Color888(255,255,0));

	matrix->swapBuffers(true);
}
