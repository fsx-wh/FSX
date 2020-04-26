#pragma once

class FData
{
public:
	float a;
	float b;
	float c;
	float con;
	char x;
	char y;
	int kuohao;//0代表无，1代表括号在左，2表示括号在右
	FData();
	void puta(float a);
	void putb(float b);
	void putc(float c);
	void putcon(float con);
	void putcharx(char x);
	void putchary(char y);
};
