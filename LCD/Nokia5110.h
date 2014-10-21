#ifndef nokia5110_h
#define nokia5110_h

class Nokia5110 : LCD
{
private:
	uint8_t _SCLK;
	uint8_t _SDIN;
	uint8_t _DC;
	uint8_t _SCE;
	uint8_t _RESET;
	uint8_t _LED;
	bool Paint(uint8_t x, uint8_t y);
public:
	Nokia5110(
		uint8_t SCLK = 8,
		uint8_t SDIN = 9,
		uint8_t DC = 10,
		uint8_t SCE = 11,
		uint8_t RESET = 12,
		uint8_t LED = 13
	);
	void Repaint();
};

#endif