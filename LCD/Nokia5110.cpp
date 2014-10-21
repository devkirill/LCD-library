Nokia5110::Nokia5110(
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
{

};

void Nokia5110::DWrite(uint8_t pin, bool value)
{
	digitalWrite(pin, value);
}