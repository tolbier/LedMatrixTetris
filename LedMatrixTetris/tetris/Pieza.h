/*
 * Pieza.h
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_PIEZA_H_
#define TETRIS_PIEZA_H_
#include "Arduino.h"
#include "Environment.h"
#include "FactoriaPiezas.h"
class Environment;

class FactoriaPiezas;
class TetrisGame;
class Board;
class Pieza {
public:
	Pieza(uint8_t tipoPieza ,FactoriaPiezas* factoriaPiezas );
	virtual ~Pieza();
	uint8_t getX() const;
	void setX(uint8_t x);
	uint8_t getY() const;
	void setY(uint8_t y);
	uint8_t getNumProfiles() const;
	void loop();
	void drawPieza();
	const uint8_t* getCurrentProfile();
	Board* getBoard();
	FactoriaPiezas*& getFactoriaPiezas() ;
	TetrisGame* getGame();
	void gravedad();
	bool libreDebajo();
	uint8_t height();
	uint8_t width();

private:

	uint8_t x,y;
	Environment::Color color;
	FactoriaPiezas* factoriaPiezas;
	const uint8_t* profiles[4] ;
	uint8_t numProfiles;
	uint8_t currentProfileIdx;

};

#endif /* TETRIS_PIEZA_H_ */
