// Do not remove the include below
#include "LedMatrixTetris.h"

TetrisGame* game;


void setup()
{
	game= new TetrisGame();

}


void loop()
{
	game->loop();

}
