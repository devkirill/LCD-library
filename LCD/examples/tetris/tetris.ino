#include "tetris.h"

TTetris tetris(4, 5, 6, 7, 8, 2);

void setup()
{
	Serial.begin(9600);
	digitalWrite(3, HIGH);
	tetris.invertColor = true;
	tetris.begin();
	tetris.repaint();
}

void loop()
{
}