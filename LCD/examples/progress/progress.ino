#include "nokia5110.h"

class TProgress : public TNokia5110
{
protected:
	bool paint(uint8_t x, uint8_t y)
	{
		return (word)x + (word)width_ * (word)y > progress;
	}
public:
	word progress;
	TProgress(
		uint8_t SCLK = 8,
		uint8_t SDIN = 9,
		uint8_t DC = 10,
		uint8_t SCE = 11,
		uint8_t RESET = 12,
		uint8_t LED = 13
	)
		: progress(0)
		, TNokia5110(SCLK, SDIN, DC, SCE, RESET, LED)
	{
	}
};

TProgress progress(4, 5, 6, 7, 8, 2);

void setup()
{
	Serial.begin(9600);
	digitalWrite(3, HIGH);
	progress.begin();
}

void loop()
{
	progress.repaint();
	progress.progress++;
}

