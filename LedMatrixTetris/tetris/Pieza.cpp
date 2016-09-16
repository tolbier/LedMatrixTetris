/*
 * Pieza.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#include "Pieza.h"


Pieza::Pieza(uint8_t tipoPieza ,FactoriaPiezas* factoriaPiezas) {
	this->factoriaPiezas = factoriaPiezas;
	Board* board=getBoard();
	x = board->width()/2 - board->left();
	y = 0;


	const uint8_t* p= factoriaPiezas->getProfile(tipoPieza);

	this->color = (Environment::Color)pgm_read_byte(p++) ;
	this->numProfiles =pgm_read_byte(p++);
	for (int i=0;i<getNumProfiles();i++){
		profiles[i]=p++;
		uint8_t  heightProfile =pgm_read_byte(p++);
		for (uint8_t j=0;j<heightProfile;j++) p++;
	}

	currentProfileIdx=0;
	setParada(false);
}

Pieza::~Pieza() {
	// TODO Auto-generated destructor stub
}

uint8_t Pieza::getX() const {
	return x;
}

void Pieza::setX(uint8_t x) {
	this->x = x;
}

uint8_t Pieza::getY() const {
	return y;
}

void Pieza::setY(uint8_t y) {
	this->y = y;
}

uint8_t Pieza::getNumProfiles() const {
	return numProfiles;
}

void Pieza::loop() {
	this->gravedad();
	this->drawPieza();
	if (isParada()){
		stampPieza();
	}


}

void Pieza::drawPieza() {
	const uint8_t* p = this->getCurrentProfile();
	this->factoriaPiezas->getGame()->drawBitmap( BOARD_LEFT+x,  BOARD_TOP+y, p,  color) ;
}

const uint8_t* Pieza::getCurrentProfile() {
	return this->profiles[this->currentProfileIdx];
}

Board* Pieza::getBoard() {
	return getGame()->getBoard();
}
TetrisGame* Pieza::getGame() {
	return getFactoriaPiezas()->getGame();
}
 FactoriaPiezas*& Pieza::getFactoriaPiezas()  {
	return factoriaPiezas;
}
void Pieza::stampPieza(){
 	const uint8_t* p = this->getCurrentProfile();

 	uint8_t width = pgm_read_byte(p++);
 	uint8_t height = pgm_read_byte(p++);

 	uint8_t b;
 	uint8_t bit;

 	for (uint8_t j = 0; j < height; j++) {
 		for (uint8_t i = 0; i < width; i++) {
 			if ((i % 8) == 0) {
 				b = pgm_read_byte(p++);
 				bit = 7;
 			}
 			if ((b >> bit) & 0x1) {

 				uint8_t x_check=x+i;
 				uint8_t y_check=y+j;
 				getBoard()->setBoardColor(x_check,y_check,this->color );

 			}
 			bit--;
 		}
 	}



 }

bool Pieza::libreDebajo(){
	const uint8_t* p = this->getCurrentProfile();

	uint8_t width = pgm_read_byte(p++);
	uint8_t height = pgm_read_byte(p++);

	uint8_t b;
	uint8_t bit;

	for (uint8_t j = 0; j < height; j++) {
		for (uint8_t i = 0; i < width; i++) {
			if ((i % 8) == 0) {
				b = pgm_read_byte(p++);
				bit = 7;
			}
			if ((b >> bit) & 0x1) {
				uint8_t x_check=x+i;
				uint8_t y_check=y+j+1;

				if (getBoard()->getBoardColor(x_check,y_check) //Si Pieza ocupada
				   || y_check >= getBoard()->height()
				) return false;

			}
			bit--;
		}
	}
	return true;


}


uint8_t Pieza::height(){
	const uint8_t* p = getCurrentProfile();

	return pgm_read_byte(p+1);
}
uint8_t Pieza::width(){
	return getCurrentProfile()[0];
}
void Pieza::gravedad() {
	static unsigned long lastMillis =0;
	if (millis()-lastMillis<250) return;

	if (libreDebajo()){
		y++;
	}else{
		setParada(true);
	}
	lastMillis = millis();
}

bool Pieza::isParada() const {
	return parada;
}

void Pieza::setParada(bool parada) {
	this->parada = parada;
}
