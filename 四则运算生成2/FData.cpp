#include "FData.h"

FData::FData()
{
	a = b = c = 0;
	con = 0;
}

void FData::puta(float a)
{
	this->a = a;
}

void FData::putb(float b)
{
	this->b = b;
}

void FData::putc(float c)
{
	this->c = c;
}

void FData::putcon(float con)
{
	this->con = con;
}

void FData::putcharx(char x)
{
	this->x = x;
}

void FData::putchary(char y)
{
	this->y = y;
}
