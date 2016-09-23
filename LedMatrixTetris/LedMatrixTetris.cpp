// Do not remove the include below

#include "LedMatrixTetris.h"

TetrisGame* game;
RGBmatrixPanel* matrix;
LevelSelector* levelSelector;
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
	matrix->setRotation(3);
	Serial.begin(9600);
	matrix->begin();
	game= new TetrisGame(matrix,true);
	levelSelector = NULL;
}


void loop()
{
	if (game){
		game->loop();
		bool requestStart=game->isRequestStart();
		if (game->isEndOfGame() || requestStart){
			delete game;
			game=NULL;
			if (requestStart){
				if (levelSelector) {
					delete levelSelector;
				}
				levelSelector = new  LevelSelector(matrix);
			}else{
				game= new TetrisGame(matrix,true);
			}

		}
	}
	if (levelSelector){
		levelSelector->loop();
	}
	matrix->swapBuffers(true);
}
