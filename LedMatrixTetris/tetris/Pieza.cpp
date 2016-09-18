/*
 * Pieza.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#include "Pieza.h"

#define PREVIA_TOP 12
#define PREVIA_LEFT 12


Pieza::Pieza(uint8_t tipoPieza ,FactoriaPiezas* factoriaPiezas) {
	this->factoriaPiezas = factoriaPiezas;
	Board* board=getBoard();
	x = board->width()/2 - board->left()-1;
	y = 0;


	const uint8_t* p= factoriaPiezas->getProfile(tipoPieza);

	this->color = (Environment::Color)pgm_read_byte(p++) ;
	numProfiles =pgm_read_byte(p++);

	for (int i=0;i<getNumProfiles();i++){
		profiles[i]=p++;
		uint8_t  heightProfile =pgm_read_byte(p++);
		p+= heightProfile;
	}

	currentProfileIdx=0;
	setParada(false);
	setPrevia(true);
}

Pieza::~Pieza() {
	// TODO Auto-generated destructor stub
}

int8_t Pieza::getX() const {
	return x;
}

void Pieza::setX(int8_t x) {
	this->x = x;
}

int8_t Pieza::getY() const {
	return y;
}

void Pieza::setY(int8_t y) {
	this->y = y;
}

bool Pieza::isPrevia() const {
	return previa;
}

void Pieza::setPrevia(bool previa) {
	this->previa = previa;
}

uint8_t Pieza::getNumProfiles() const {
	return numProfiles;
}

void Pieza::treatInput() {
     setDropping(false);
	 while (Serial.available()) {
	    // get the new byte:
	    char inChar = (char)Serial.read();
	    if (inChar=='A'|| inChar=='a'){
	    	if (libreIzquierda()) x--;
	    }
	    if (inChar=='d' || inChar=='D'){
	    	if (libreDerecha()) x++;
	    }
	    if (inChar=='w' || inChar=='W'){
	    	if (libreGiro()) giro();
	    }
	    if (inChar=='s' || inChar=='S'){
	    	setDropping(true);
	    }

	  }
}

void Pieza::loop() {
	if (isPrevia()){
		drawPrevia();
		return;
	}
	treatInput();
	this->gravedad();
	this->drawPieza();
	if (isParada()){
		stampPieza();

	}


}
uint8_t Pieza::getNextProfileIdx(){
	uint8_t retorno= (getCurrentProfileIdx()+1)%(this->getNumProfiles());
	return retorno;
}
void Pieza::giro(){
	setCurrentProfileIdx(getNextProfileIdx());
}
void Pieza::drawPrevia() {
	getGame()->fillRect(PREVIA_LEFT,PREVIA_TOP,4,2,Environment::Color::black);
	const uint8_t* p = this->getCurrentProfile();
	getGame()->drawBitmap( PREVIA_LEFT, PREVIA_TOP, p,  color) ;
}
void Pieza::drawPieza() {
	const uint8_t* p = this->getCurrentProfile();
	getGame()->drawBitmap( BOARD_LEFT+x,  BOARD_TOP+y, p,  color) ;
}

const uint8_t* Pieza::getCurrentProfile() {
	return this->profiles[getCurrentProfileIdx()];
}
const uint8_t* Pieza::getNextProfile() {
	return this->profiles[getNextProfileIdx()];
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
 	const uint8_t* p = getCurrentProfile();

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

 	getGame()->getBoard()->check4Lines(y,height);

 }
bool Pieza::libreGiro(){
	bool retorno = libreXY(0,0, this->getNextProfile());
	return retorno;

}
bool Pieza::libreXY(int8_t x_offset,int8_t y_offset){
	const uint8_t* p = this->getCurrentProfile();
	return libreXY(x_offset,y_offset,p);
}
bool Pieza::libreXY(int8_t x_offset,int8_t y_offset,const uint8_t* p){
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
				int8_t x_check=x+i + x_offset;
				int8_t y_check=y+j + y_offset;
				if (!getBoard()->checkInbounds(x_check,y_check) ||
				     getBoard()->getBoardColor(x_check,y_check) //Si Pieza ocupada

				) return false;

			}
			bit--;
		}
	}
	return true;


}

bool Pieza::libreIzquierda(){
	return libreXY(-1,0);
}
bool Pieza::libreDerecha(){
	return libreXY(+1,0);


}
bool Pieza::libreDebajo(){
	return libreXY(0,+1);
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
	unsigned long dropDivisor= 1;
	if (isDropping()) dropDivisor=5;

	if (millis()-lastMillis< (300/dropDivisor) ) return;

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

uint8_t Pieza::getCurrentProfileIdx() const {
	return currentProfileIdx;
}

void Pieza::setCurrentProfileIdx(uint8_t currentProfileIdx) {
	this->currentProfileIdx = currentProfileIdx;
}

void Pieza::setParada(bool parada) {
	this->parada = parada;
}

bool Pieza::isDropping() const {
	return dropping;
}

void Pieza::setDropping(bool dropping) {
	this->dropping = dropping;
}
