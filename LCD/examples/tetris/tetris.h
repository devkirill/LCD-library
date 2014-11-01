#ifndef tetris_h
#define tetris_h

#include "Nokia5110.h"
#include "Arduino.h"

class TTetris : public TNokia5110
{
protected:
	bool paint(uint8_t x, uint8_t y);
	byte *matrix;
public:
	TTetris(
		uint8_t SCLK = 8,
		uint8_t SDIN = 9,
		uint8_t DC = 10,
		uint8_t SCE = 11,
		uint8_t RESET = 12,
		uint8_t LED = 13
	);

	bool getPixel(uint8_t x, uint8_t y);
	void setPixel(uint8_t x, uint8_t y, bool color);
};

#endif