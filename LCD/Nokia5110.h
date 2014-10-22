#ifndef nokia5110_h
#define nokia5110_h

class TNokia5110 : TDisplay
{
private:
	uint8_t SCLK_;
	uint8_t SDIN_;
	uint8_t DC_;
	uint8_t SCE_;
	uint8_t RESET_;
	uint8_t LED_;

	virtual bool paint(uint8_t x, uint8_t y) = 0;
	void writeData(uint8_t, uint8_t);
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