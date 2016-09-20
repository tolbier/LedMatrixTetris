// Do not remove the include below
#include "LedMatrixTetris.h"

TetrisGame* game;
RGBmatrixPanel* matrix;

void setup()
{
	matrix= new RGBmatrixPanel(
		MATRIX_A,
		MATRIX_B,
		MATRIX_C,
		MATRIX_CLK,
		MATRIX_LAT,
		MATRIX_OE,
		true);

	randomSeed(analogRead(0));
	Serial.begin(9600);
	matrix->begin();
	game= new TetrisGame(matrix,true);

}


void loop()
{
	game->loop();
    if (game->isEndOfGame()){
    	delete game;
    	game= new TetrisGame(matrix,true);

    }
}
