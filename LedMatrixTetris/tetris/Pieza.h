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

	void loop();


	bool isParada() const;
	bool isPrevia() const;
	void setPrevia(bool previa);

private:
    bool parada;
    bool previa;

	int8_t x,y;
	Environment::Color color;
	FactoriaPiezas* factoriaPiezas;
	const uint8_t* profiles[4] ;
	uint8_t numProfiles;
	uint8_t currentProfileIdx;
	void stampPieza();
	void treatInput() ;
	bool libreDerecha();
	bool libreIzquierda();
	void gravedad();
	bool libreDebajo();
	void drawPieza();
	void drawPrevia() ;
	bool libreXY(int8_t x_offset,int8_t y_offset);
	bool libreXY(int8_t x_offset,int8_t y_offset,const uint8_t* p);
	bool libreGiro();
	void giro();
	const uint8_t* getNextProfile() ;
	const uint8_t* getCurrentProfile();
	uint8_t getNextProfileIdx();
	Board* getBoard();
	FactoriaPiezas*& getFactoriaPiezas() ;
	TetrisGame* getGame();
	uint8_t height();
	uint8_t width();
	void setParada(bool parada);
	uint8_t getCurrentProfileIdx() const;
	void setCurrentProfileIdx(uint8_t currentProfileIdx);
	int8_t getX() const;
	void setX(int8_t x);
	int8_t getY() const;
	void setY(int8_t y);
	uint8_t getNumProfiles() const;
	};

#endif /* TETRIS_PIEZA_H_ */
