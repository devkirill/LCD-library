#ifndef LCD_h
#define LCD_h

class LCD
{
private:
	uint8_t Width;
	uint8_t Height;
	virtual bool Paint(uint8_t x, uint8_t y) = 0;
public:
	LCD(uint8_t width, uint8_t height);
	virtual void Repaint() = 0;
};

#endif