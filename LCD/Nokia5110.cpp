#include "Nokia5110.h"

TNokia5110::TNokia5110(
	uint8_t SCLK,
	uint8_t SDIN,
	uint8_t DC,
	uint8_t SCE,
	uint8_t RESET,
	uint8_t LED
)
	: SCLK_(SCLK)
	, SDIN_(SDIN)
	, DC_(DC)
	, SCE_(SCE)
	, RESET_(RESET)
	, LED_(LED)
	, invertColor(0)
	, TDisplay(84, 48)
{

};

bool TNokia5110::paint(uint8_t x, uint8_t y)
{
	return false;
}

void TNokia5110::writeData(uint8_t dc, uint8_t data)
{
	if (dc == HIGH && invertColor)
		data = ~data;
	digitalWrite(DC_, dc);
	digitalWrite(SCE_, LOW);
	shiftOut(SDIN_, SCLK_, MSBFIRST, data);
	digitalWrite(SCE_, HIGH);
}

uint8_t TNokia5110::paintCell(uint8_t x, uint8_t y)
{
	uint8_t res = 0;
	for (uint8_t k = 7; k < 8; k--)
	{
		res *= 2;
		res += paint(x, y * 8 + k) ? 1 : 0;
	}
	return res;
}

void TNokia5110::repaint()
{
	for (uint8_t y = 0; y * 8 < height_; y++)
	{
		for (uint8_t x = 0; x < width_; x++)
		{
			writeData(HIGH, paintCell(x, y));
		}
	}
}

void TNokia5110::begin()
{
	pinMode(SCE_, OUTPUT);
	pinMode(RESET_, OUTPUT);
	pinMode(DC_, OUTPUT);
	pinMode(SDIN_, OUTPUT);
	pinMode(SCLK_, OUTPUT);
	pinMode(LED_, OUTPUT);
	digitalWrite(LED_, HIGH);
	digitalWrite(RESET_, LOW);
	digitalWrite(RESET_, HIGH);
	writeData(LOW, 0x20 | 0x01);  // LCD Extended Commands.
	writeData(LOW, 0x10 | 0x04);  // LCD bias mode 1:48. //0x13 0x14
	writeData(LOW, 0x80 | 0x00);  // Set LCD Vop (Contrast). / Shift
	writeData(LOW, 0x20);         // normal mode
	writeData(LOW, 0x08 | 0x04);  // Set display to Normal
}