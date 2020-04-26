#include "Four_operations.h"

Four_operations::Four_operations()
{
	this->num = 0;
	this->Max = 0;
	this->Correct = 0;
	this->needkuohao = false;
	this->needadd = true;
	this->needsub = true;
	this->needmul = true;
	this->needdiv = true;
	this->needprint = true;
	this->needwritetofile = false;
	this->needfloat = false;
	this->needansw = false;
	srand((unsigned)time(0));//写入种子
}

void Four_operations::putall(int Max, bool needkuohao, bool needadd, bool needsub, bool needmul, bool needdiv, bool needprint, bool needw, bool needf,bool needansw)
{
	this->Max = Max;
	this->needkuohao = needkuohao;
	this->needadd = needadd;
	this->needsub = needsub;
	this->needmul = needmul;
	this->needdiv = needdiv;
	this->needprint = needprint;
	this->needwritetofile = needw;
	this->needfloat = needf;
	this->needansw = needansw;
}

int Four_operations::Randnumberint()
{
	int temp;
	temp = rand() % Max;
	if (temp == 0)
	{
		return 1;
	}
	else
	{
		return temp;
	}
}

float Four_operations::Randnumberfloat()
{
	if (this->needfloat)
	{
		return (rand() % (Max * 100) / 100.0) + 0.01;//防止分母为0
	}
	else
	{
		return 0.0f;
	}
}

void Four_operations::Writefile()
{
	FILE* fp1, * fp2;
	fp1 = fopen("问题.txt", "w");
	fp2 = fopen("答案.txt", "w");
	int i;
	if (this->needkuohao)//有括号
	{
		for (i = 0; i < num; i++)
		{
			if (da[i].kuohao == 1)
			{
				if (this->needfloat)
				{
					fprintf(fp1, "%d: (%.2f %c %.2f) %c %.2f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
				else
				{
					fprintf(fp1, "%d: (%.0f %c %.0f) %c %.0f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
			}
			else
			{
				if (this->needfloat)
				{
					fprintf(fp1, "%d: %.2f %c (%.2f %c %.2f) =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
				else
				{
					fprintf(fp1, "%d: %.0f %c (%.0f %c %.0f) =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
			}
		}
	}
	else//无括号
	{
		for (i = 0; i < num; i++)
		{
			if (this->needfloat)
			{
				fprintf(fp1, "%d: %.0f %c %.0f %c %.0f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
			}
			else
			{
				fprintf(fp1, "%d: %.0f %c %.0f %c %.0f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		fprintf(fp2, "%d: %.2f\n", i + 1, da[i].con);
	}
	fclose(fp1);
	fclose(fp2);
}

void Four_operations::Print()
{
	int i;
	float youranswer;//答题者的答案
	cout.precision(2);
	cout.setf(ios::fixed);
	if (this->needkuohao)
	{
		for (i = 0; i < num; i++)
		{
			if (da[i].kuohao == 1)
			{
				if (this->needansw)
				{
					if (this->needfloat)
					{
						printf("%d: (%.2f %c %.2f) %c %.2f =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					else
					{
						printf("%d: (%.0f %c %.0f) %c %.0f =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					cout << "请输入你的答案：" << endl;
					cin >> youranswer;
					da[i].con = (int)((da[i].con + 0.005) * 100) / 100.0;
					if (youranswer == da[i].con)
					{
						this->Correct = this->Correct + 1;
						cout << "回答正确！" << endl;
					}
					else
					{
						cout << "回答错误！正确答案是：" << da[i].con << endl;
					}
				}
				else
				{
					if (this->needfloat)
					{
						printf("%d: (%.2f %c %.2f) %c %.2f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					else
					{
						printf("%d: (%.0f %c %.0f) %c %.0f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
				}
			}
			else
			{
				if (this->needansw)
				{
					if (this->needfloat)
					{
						//cout << i + 1 << ':' << da[i].a << da[i].x << '(' << da[i].b << da[i].y << da[i].c << ')=' << endl;
						printf("%d: %.2f %c (%.2f %c %.2f) =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					else
					{
						//cout << i + 1 << ':' << da[i].a << da[i].x << '(' << da[i].b << da[i].y << da[i].c << ')=' << endl;
						printf("%d: %.0f %c (%.0f %c %.0f) =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					cout << "请输入你的答案：" << endl;
					cin >> youranswer;
					da[i].con = (int)((da[i].con + 0.005) * 100) / 100.0;
					if (youranswer == da[i].con)
					{
						this->Correct = this->Correct + 1;
						cout << "回答正确！" << endl;
					}
					else
					{
						cout << "回答错误！正确答案是：" << da[i].con << endl;
					}
				}
				else
				{
					if (this->needfloat)
					{
						printf("%d: %.2f %c (%.2f %c %.2f) =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
					else
					{
						printf("%d: %.0f %c (%.0f %c %.0f) =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
					}
				}

			}
		}
	}
	else
	{
		for (i = 0; i < num; i++)
		{
			if (this->needansw)
			{
				if (this->needfloat)
				{
					//cout << i + 1 << ':' << da[i].a << da[i].x << da[i].b << da[i].y << da[i].c << '=' << endl;
					printf("%d: %.2f %c %.2f %c %.2f =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
				else
				{
					//cout << i + 1 << ':' << da[i].a << da[i].x << da[i].b << da[i].y << da[i].c << '=' << endl;
					printf("%d: %.0f %c %.0f %c %.0f =_?_\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
				cout << "请输入你的答案：" << endl;
				cin >> youranswer;
				da[i].con = (int)((da[i].con + 0.005) * 100) / 100.0;
				if (youranswer == da[i].con)
				{
					this->Correct = this->Correct + 1;
					cout << "回答正确！" << endl;
				}
				else
				{
					cout << "回答错误！正确答案是：" << da[i].con << endl;
				}
			}
			else
			{
				if (this->needfloat)
				{
					printf("%d: %.2f %c %.2f %c %.2f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
				else
				{
					printf("%d: %.0f %c %.0f %c %.0f =\n", i + 1, da[i].a, da[i].x, da[i].b, da[i].y, da[i].c);
				}
			}
		}
	}
}

float Four_operations::cal(float a, float b, float c, int d, int e, int kuohao)
{
	if (kuohao == 0)
	{
		if (d < 2 && e>1) {
			return caleasy(a, caleasy(b, c, e), d);
		}
		else {
			return caleasy(caleasy(a, b, d), c, e);
		}
	}
	else if (kuohao == 1)//左括号
	{
		return caleasy(caleasy(a, b, d), c, e);
	}
	else if (kuohao == 2)//右括号
	{
		return caleasy(a, caleasy(b, c, e), d);
	}
	else
		return 0.0f;
}

float Four_operations::caleasy(float a, float b, int c)
{
	return c == 0 ? (a + b) : (c == 1 ? (a - b) : (c == 2 ? (a * b) : (a / b)));
}


int Four_operations::cc()
{
	int i = 0;
	float a, b, c;//临时的3个数
	int d, e;//符号
	int kuohao = 0;//括号（默认为0：不带）
	if (this->needkuohao)//有括号
	{
		if (this->needfloat)//带小数
		{
			for (i = 0; i < this->num; i++)
			{
				a = Randnumberfloat();
				b = Randnumberfloat();
				c = Randnumberfloat();
				d = getcharacter();
				e = getcharacter();
				kuohao = getcharacter() % 2 + 1;
				da[i].puta(a);
				da[i].b = b;
				da[i].c = c;
				da[i].kuohao = kuohao;
				da[i].con = cal(a, b, c, d, e, da[i].kuohao);
				changecharacter(i, d, e);
			}
		}
		else
		{
			for (i = 0; i < this->num; i++)
			{
				a = Randnumberint();
				b = Randnumberint();
				c = Randnumberint();
				d = getcharacter();
				e = getcharacter();
				kuohao = getcharacter() % 2 + 1;
				da[i].a = a;
				da[i].b = b;
				da[i].c = c;
				da[i].kuohao = kuohao;
				da[i].con = cal(a, b, c, d, e, da[i].kuohao);
				changecharacter(i, d, e);
			}
		}
	}
	else
	{
		if (this->needfloat)
		{
			for (i = 0; i < this->num; i++)
			{
				a = Randnumberfloat();
				b = Randnumberfloat();
				c = Randnumberfloat();
				d = getcharacter();
				e = getcharacter();
				da[i].a = a;
				da[i].b = b;
				da[i].c = c;
				da[i].kuohao = 0;
				da[i].con = cal(a, b, c, d, e, da[i].kuohao);
				changecharacter(i, d, e);
			}
		}
		else
		{
			for (i = 0; i < this->num; i++)
			{
				a = Randnumberint();
				b = Randnumberint();
				c = Randnumberint();
				d = getcharacter();
				e = getcharacter();
				da[i].a = a;
				da[i].b = b;
				da[i].c = c;
				da[i].kuohao = 0;
				da[i].con = cal(a, b, c, d, e, da[i].kuohao);
				changecharacter(i, d, e);
			}
		}
	}
	if (this->needprint)
	{
		Print();
		if (this->needansw)
		{
			cout << "此次答题共" << this->num << "道，答对 " << this->Correct << "道！" << endl;
		}
	}
	if (this->needwritetofile)
	{
		Writefile();
	}
	return 0;
}

void Four_operations::putnum(int num)
{
	this->num = num;
	da = new FData[num];
}

int Four_operations::getcharacter()
{
	int sign;//随机数符号
	sign = rand() % 4;
	switch (sign)
	{
	case 3:
		if (this->needdiv)
		{
			break;
		}
		else
		{
			return getcharacter();
		}
	case 2:
		if (this->needmul)
		{
			break;
		}
		else
		{
			return getcharacter();
		}
	case 1:
		if (this->needsub)
		{
			break;
		}
		else
		{
			return getcharacter();
		}
	case 0:
		if (this->needadd)
		{
			break;
		}
		else
		{
			return getcharacter();
		}
	default:
		return getcharacter();
	}
	return sign;
}

void Four_operations::changecharacter(int i, int x, int y)
{
	if (x == 3)
	{
		da[i].x = '/';
	}
	else if (x == 2)
	{
		da[i].x = 'x';
	}
	else if (x == 1)
	{
		da[i].x = '-';
	}
	else if (x == 0)
	{
		da[i].x = '+';
	}
	else
	{
		da[i].x = NULL;
	}
	if (y == 3)
	{
		da[i].y = '/';
	}
	else if (y == 2)
	{
		da[i].y = 'x';
	}
	else if (y == 1)
	{
		da[i].y = '-';
	}
	else if (y == 0)
	{
		da[i].y = '+';
	}
	else
	{
		da[i].y = NULL;
	}
}
