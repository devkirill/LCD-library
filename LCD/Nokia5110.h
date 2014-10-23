#ifndef nokia5110_h
#define nokia5110_h

#include "Display.h"
#include "arduino.h"

// Datasheet:
// http://pdf.datasheetcatalog.com/datasheet/philips/PCD8544U.pdf

class TNokia5110 : public TDisplay
{
private:
	uint8_t SCLK_;
	uint8_t SDIN_;
	uint8_t DC_;
	uint8_t SCE_;
	uint8_t RESET_;
	uint8_t LED_;

	void command(uint8_t);
	void writeByte(uint8_t);
protected:
	virtual bool paint(uint8_t x, uint8_t y);
	virtual uint8_t paintCell(uint8_t x, uint8_t y);
public:
	bool invertColor;

	TNokia5110(
		uint8_t SCLK = 8,
		uint8_t SDIN = 9,
		uint8_t DC = 10,
		uint8_t SCE = 11,
		uint8_t RESET = 12,
		uint8_t LED = 13
	);
	void repaint();
	void begin();
};

#endif