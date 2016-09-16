// Do not remove the include below
#include "LedMatrixTetris.h"

TetrisGame* game;


void setup()
{
	randomSeed(analogRead(0));
	Serial.begin(9600);
	game= new TetrisGame();

}


void loop()
{
	game->loop();

}
