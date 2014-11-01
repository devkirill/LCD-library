#include "tetris.h"

#define sizeX 10
#define sizeY 20
#define sizeCell 4

bool TTetris::paint(uint8_t x, uint8_t y)
{
	int X = y - 4;
	int Y = x - 2;
	if (X == -1 || Y == -1 || X == sizeCell * sizeX + 1 || Y == sizeCell * sizeY + 1)
		if (X >= -1 && Y >= -1 && X <= sizeCell * sizeX + 1 && Y <= sizeCell * sizeY + 1)
			return true;
	if (X < 0)
		return invertColor;
	if (X > sizeCell * sizeX)
		return invertColor;
	if (Y < 0)
		return invertColor;
	if (Y > sizeCell * sizeY)
		return invertColor;
	if (X % sizeCell == 0 || Y % sizeCell == 0)
		return false;

	return getPixel(sizeX - X/sizeCell - 1, sizeY - Y/sizeCell - 1);
}

TTetris::TTetris(
	uint8_t SCLK,
	uint8_t SDIN,
	uint8_t DC,
	uint8_t SCE,
	uint8_t RESET,
	uint8_t LED
)
	: TNokia5110(SCLK, SDIN, DC, SCE, RESET, LED)
{
	matrix = new byte [sizeX * sizeY];
	for (byte i = 0; i < sizeX * sizeY; i++)
		matrix[i] = false;
}

bool TTetris::getPixel(uint8_t x, uint8_t y)
{
	return matrix[x + sizeX * y];
}
void TTetris::setPixel(uint8_t x, uint8_t y, bool color)
{
	matrix[x + sizeX * y] = color;
}

#undef sizeX
#undef sizeY
#undef sizeCell