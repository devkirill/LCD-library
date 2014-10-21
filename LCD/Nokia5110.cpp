Nokia5110::Nokia5110(
	uint8_t SCLK,
	uint8_t SDIN,
	uint8_t DC,
	uint8_t SCE,
	uint8_t RESET,
	uint8_t LED
)
	: _SCLK(SCLK)
	, _SDIN(SDIN)
	, _DC(DC)
	, _SCE(SCE)
	, _RESET(RESET)
	, _LED(LED)
{

};