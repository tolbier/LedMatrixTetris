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
	Serial.print("color:");
	Serial.println(color);

	this->numProfiles =pgm_read_byte(p++);
	Serial.print("numProfiles:");
	Serial.println(numProfiles);

	for (int i=0;i<getNumProfiles();i++){
		profiles[i]=p++;
		Serial.print("profiles[i]");
		Serial.println(*(profiles[i]));

		uint8_t  heightProfile =pgm_read_byte(p++);
		Serial.print("heightProfile:");
		Serial.println(heightProfile);
		for (uint8_t j=0;j<heightProfile;j++) p++;
	}

	currentProfileIdx=0;
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
bool Pieza::libreDebajo(){
	Serial.print("Pieza:height()");
	Serial.println(height());
	return (y+height() <this->getBoard()->height());

}

uint8_t Pieza::height(){
	const uint8_t* p = getCurrentProfile();

	return *(p+1);
}
uint8_t Pieza::width(){
	return getCurrentProfile()[0];
}
void Pieza::gravedad() {
	static unsigned long lastMillis =0;
	if (millis()-lastMillis<250) return;

	if (libreDebajo()) y++;
	lastMillis = millis();
}
