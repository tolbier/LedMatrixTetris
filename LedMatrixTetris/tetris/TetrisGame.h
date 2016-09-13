/*
 * TetrisGame.h
 *
 *  Created on: 11 sept. 2016
 *      Author: toyos
 */

#ifndef TETRIS_TETRISGAME_H_
#define TETRIS_TETRISGAME_H_
#include "Arduino.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "Score.h"


#define MATRIX_CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define MATRIX_LAT 33
#define MATRIX_OE  34
#define MATRIX_A   30
#define MATRIX_B   31
#define MATRIX_C   32

class Score;
class TetrisGame {
public:
	TetrisGame();
	virtual ~TetrisGame();
	void loop();
	RGBmatrixPanel* matrix;
	const uint8_t* getDigitBitmap(uint8_t digit);
	uint8_t drawBitmap(int x, int y, const uint8_t *bmp, uint16_t color) ;
	uint16_t black , yellow , darkyellow , red , white , pink ,palePink , blue , cyan ,orange ,darkOrange ,green ,grey,magenta;
private:
	Score* score;
	static const uint8_t PROGMEM digit_bitmaps[] ;

};

#endif /* TETRIS_TETRISGAME_H_ */
