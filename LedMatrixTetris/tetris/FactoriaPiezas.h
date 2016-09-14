/*
 * FactoriaPiezas.h
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_FACTORIAPIEZAS_H_
#define TETRIS_FACTORIAPIEZAS_H_

#include "Pieza.h"
#include "TetrisGame.h"
class TetrisGame;
class FactoriaPiezas {
public:
	FactoriaPiezas(TetrisGame* game);
	virtual ~FactoriaPiezas();
	Pieza* createPieza();

private:
	TetrisGame* game;
	static const uint8_t PROGMEM pieza_bitmaps[] ;
};

#endif /* TETRIS_FACTORIAPIEZAS_H_ */
