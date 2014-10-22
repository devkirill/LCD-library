#ifndef LCD_h
#define LCD_h

#include "arduino.h"

class TDisplay
{
protected:
	uint8_t width_;
	uint8_t height_;
	virtual bool paint(uint8_t x, uint8_t y) = 0;
public:
	TDisplay(uint8_t width, uint8_t height);
	virtual void repaint() = 0;
};

#endif