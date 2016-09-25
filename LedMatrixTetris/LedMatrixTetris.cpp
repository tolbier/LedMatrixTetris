// Do not remove the include below
#include "LedMatrixTetris.h"

TetrisGame* game;
RGBmatrixPanel* matrix;

// define the pin you want to use
const int BUTTONS_PIN = A0;

// set how many buttons you have connected
const int BUTTONS_TOTAL = 4;

// find out what the value of analogRead is when you press each of your buttons and put them in this array
// you can find this out by putting Serial.println(analogRead(BUTTONS_PIN)); in your loop() and opening the serial monitor to see the values
// make sure they are in order of smallest to largest
const int BUTTONS_VALUES[BUTTONS_TOTAL] = {0, 508, 675,775};

// you can also define constants for each of your buttons, which makes your code easier to read
// define these in the same order as the numbers in your BUTTONS_VALUES array, so whichever button has the smallest analogRead() number should come first
const int BUTTON_RED = 0;
const int BUTTON_GREEN = 1;
const int BUTTON_BLUE = 2;
const int BUTTON_YELLOW = 3;

// make an AnalogMultiButton object, pass in the pin, total and values array
AnalogMultiButton buttons(BUTTONS_PIN, BUTTONS_TOTAL, BUTTONS_VALUES);

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
	game= new TetrisGame(matrix,&buttons,true);

}


void loop()
{
	buttons.update();
	game->loop();
	bool requestStart=game->isRequestStart();
	bool demo = !requestStart;
    if (game->isEndOfGame() || requestStart){
    	delete game;
       	game= new TetrisGame(matrix,&buttons,demo);

    }
	matrix->swapBuffers(true);
}
