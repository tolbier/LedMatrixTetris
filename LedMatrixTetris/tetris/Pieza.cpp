/*
 * Pieza.cpp
 *
 *  Created on: 14 sept. 2016
 *      Author: toyos
 */

#include "Pieza.h"


Pieza::Pieza(uint8_t tipoPieza ,FactoriaPiezas* factoriaPiezas) {
	x = 0;
	y = 0;
	this->factoriaPiezas = factoriaPiezas;

	const uint8_t* p= factoriaPiezas->getProfile(tipoPieza);

	this->color = (Environment::Color)pgm_read_byte(p++);
	Serial.print("color:");
	Serial.println(color);

	this->numProfiles =pgm_read_byte(p++);
	Serial.print("numProfiles:");
	Serial.println(numProfiles);

	for (int i=0;i<getNumProfiles();i++){
		profiles[i]=p++;
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
	this->drawPieza();


}

void Pieza::drawPieza() {
	//uint8_t TetrisGame::drawBitmap(int x, int y, const uint8_t *bmp, uint16_t color) {
	const uint8_t* p = this->getCurrentProfile();

//	Serial.println("drawPieza");
//	Serial.print("color:");
//	Serial.println(color);
	uint8_t width = pgm_read_byte(p++);
	uint8_t height = pgm_read_byte(p++);
//	Serial.print("width:");
//	Serial.println(width);
//	Serial.print("height:");
//	Serial.println(height);

	uint8_t b;
	uint8_t bit;

	for (uint8_t j = 0; j < height; j++) {
		bit = 7;
		for (uint8_t i = 0; i < width; i++) {
			b = pgm_read_byte(p++);
			if ((b >> bit) & 0x1) {

				this->factoriaPiezas->getGame()->matrix->drawPixel(
				BOARD_TOP +  (j+y),
				BOARD_LEFT - (i+x), color);
			}
			bit--;
		}
	}
}

const uint8_t* Pieza::getCurrentProfile() {
	return this->profiles[this->currentProfileIdx];
}
