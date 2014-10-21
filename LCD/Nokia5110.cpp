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
	, invertColor(1)
	, TDisplay(80, 24)
{

};

void TNokia5110::writeData(byte dc, byte data)
{
	if (dc == HIGH && invertColor)
		data = ~data;
	digitalWrite(PIN_DC, dc);
	digitalWrite(PIN_SCE, LOW);
	shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
	digitalWrite(PIN_SCE, HIGH);
}

bool TNokia5110::paint(uint8_t x, uint8_t y)
{

}

void TNokia5110::repaint()
{

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
	writeData(LOW, 0x21);  // LCD Extended Commands.
	writeData(LOW, 0xB1);  // Set LCD Vop (Contrast). 
	writeData(LOW, 0x04);  // Set Temp coefficent. //0x04
	writeData(LOW, 0x14);  // LCD bias mode 1:48. //0x13
	writeData(LOW, 0x0C);  // LCD in normal mode.
	writeData(LOW, 0x20);
	writeData(LOW, 0x0C);
}