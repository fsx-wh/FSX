#pragma once
#include<iostream>
#include<ostream>
#include<stdlib.h>
using namespace std;
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define MAX 600
typedef double numd;
typedef char numc;
typedef long numl;

typedef struct
{
	numc name[66];
	numd volume, price;//销售额，单价
	numd number;//销售量
	numc num[66];//编号
}Med;//结构体名

class Medicine
{
public:
	Med m[MAX];
	Med* M = m;
	numd L;//药品总数
	Medicine();//构造函数
	~Medicine();//析构函数
	void Set();//输入函数
	void Pnumber();//销量排名函数
	void Pnum();//编号排名函数
	void Pprice();//单价排名函数
	void Pvolume();//销售额排名函数
	void Print();//打印数据函数
	void Printf();//输出到文件函数
	void Printf0();//写文件函数
};

void Medicine::Print()//输出函数，打印药品信息
{
	cout << "名称\t        编号\t单价\t销量\t销售额\n";
	for (numl i = 1; i <= L; i++)
	{
		printf("%s\t%s\t%.1lf\t%.0lf\t%.2lf\n", m[i].name, m[i].num, m[i].price, m[i].number, m[i].volume);
	}
}

Medicine::Medicine()
{
	L = M->number = M->price = M->volume = 0;
	M->name[0] = ' ';
	cout << "欢迎来到Medicine系统服务平台\n\n\n";
}

Medicine::~Medicine()
{
	//cout << "感谢您的使用，祝您生活愉快！\n\n\n\n";
}

void Medicine::Set()
{
	cout << "请输入最大的药品种类\n";
	cin >> L;
	cout << "请依次输入药品的名称，编号，单价，销量\n";
	int i;
	for (i = 1; i <= L; i++)
	{
		cin >> m[i].name >> m[i].num >> m[i].price >> m[i].number;
		m[i].volume = m[i].price * m[i].number;
	}
}

void Medicine::Printf()
{
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	for (numl i = 1; i <= L; i++)
	{
		fputs(m[i].name, fp);//向文件中写字符串
		fputc(' ', fp);
		fputs(m[i].num, fp);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].price);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].number);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].volume);
		fputs("\n\n", fp);
	}
	fclose(fp);
}

bool compare(const Med* st1, const Med* st2)
{
	return st1->number > st2->number;
}

void Medicine::Pnumber()
{
	numl  j;
	numd flag = 1;
	numd mm = L - 1;
	Med R;
	for (; mm > 0 && flag == 1; mm--)
	{
		flag = 0;
		for (j = 1; j <= mm; j++)
		{
			if (m[j].number < m[j + 1].number)
			{
				flag = 1;
				R = m[j];
				m[j] = m[j + 1];
				m[j + 1] = R;
			}
		}
	}
	cout << "根据销量排序的结果是：\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	fputs("根据药品的销量情况排序:\n\n", fp);
	fclose(fp);
	Printf();
}

void Medicine::Pvolume()
{
	numl  j;
	numd flag = 1;
	numd mm = L - 1;
	Med R;
	for (; mm > 0 && flag == 1; mm--)
	{
		flag = 0;
		for (j = 1; j <= mm; j++)
		{
			if (m[j].volume < m[j + 1].volume)
			{
				flag = 1;
				R = m[j];
				m[j] = m[j + 1];
				m[j + 1] = R;
			}
		}
	}
	cout << "根据销售额排序的结果是：\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	fputs("根据药品的销售额情况排序:\n\n", fp);
	fclose(fp);
	Printf();
}

void Medicine::Pprice()
{
	numl  j;
	numd flag = 1;
	numd mm = L - 1;
	Med R;
	for (; mm > 0 && flag == 1; mm--)
	{
		flag = 0;
		for (j = 1; j <= mm; j++)
		{
			if (m[j].price < m[j + 1].price)
			{
				flag = 1;
				R = m[j];
				m[j] = m[j + 1];
				m[j + 1] = R;
			}
		}
	}
	cout << "根据单价排序的结果是：\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	fputs("根据药品的单价情况排序:\n\n", fp);
	fclose(fp);
	Printf();
}

void Medicine::Pnum()
{
	numl  j;
	numd flag = 1;
	numd mm = L - 1;
	Med R;
	for (; mm > 0 && flag == 1; mm--)
	{
		flag = 0;
		for (j = 1; j <= mm; j++)
		{
			if (strcmp(m[j].num, m[j + 1].num) == 1)
			{
				flag = 1;
				R = m[j];
				m[j] = m[j + 1];
				m[j + 1] = R;
			}
		}
	}
	cout << "根据名称排序的结果是：\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	fputs("根据药品的名称情况排序:\n\n", fp);
	fclose(fp);
	Printf();
}

void Medicine::Printf0()
{
	FILE* fp;
	fp = fopen("medicine", "w");
	if (!fp) { cout << "读取文件失败"; exit(0); }
	fputs("药品的初始数据如下：\n\n", fp);
	for (numl i = 1; i <= L; i++)
	{
		fputs(m[i].name, fp);//向文件中写字符串
		fputc(' ', fp);
		fputs(m[i].num, fp);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].price);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].number);
		fputc(' ', fp);
		fprintf(fp, "%lf", m[i].volume);
		fputs("\n\n", fp);
	}
	fclose(fp);
}

void ssort(Medicine F)
{
	cout << "请选择排序的方式：\n--------------------\n";
	cout << "根据药品的单价排序请按“1”\n根据药品的销售额排序请按“2”\n根据药品的编号排序请按“3”\n根据药品的销量排序请按“4”\n如果想要退出系统请按“0”\n";
	cout << "--------------------\n";
	int aa;
	bool f = 0;
	for (int ii = 1; ii < 5; ii++)
	{
		cin >> aa;
		if (aa > 4 || aa < 0)
			cout << "对不起！输入有误，请重新输入\n";
		else break;
	}
	for (int ii = 1; ii < MAX; ii++)
	{
		switch (aa)
		{
		case 1:F.Pprice(); break;
		case 2:F.Pvolume(); break;
		case 3:F.Pnum(); break;
		case 4:F.Pnumber(); break;
		case 0:f = 1; break;/*exit(0);*/
		default:cout << "对不起！输入有误，请重新输入";
			break;
		}
		if (f)break;
		cout << "请继续您的选择：";
		cin >> aa;
	}
}

void cc()
{
	Medicine F;
	F.Set();
	F.Printf0();
	ssort(F);
	cout << "\n\n\n感谢您的使用，祝您生活愉快！\n\n\n\n";
}


//#include "Medicine.h"
int main()
{
	cc();//主功能函数
	system("pause");
	return 0;
}
