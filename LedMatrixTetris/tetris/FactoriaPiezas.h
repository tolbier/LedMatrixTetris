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
	const uint8_t* getProfile(int tipoPieza) const;
	TetrisGame*& getGame() ;

private:
	TetrisGame* game;
	static const uint8_t PROGMEM pieza_bitmaps[] ;

	static const uint8_t* profiles_data[] ;
};

#endif /* TETRIS_FACTORIAPIEZAS_H_ */
