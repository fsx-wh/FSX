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
	numd volume, price;//���۶����
	numd number;//������
	numc num[66];//���
}Med;//�ṹ����

class Medicine
{
public:
	Med m[MAX];
	Med* M = m;
	numd L;//ҩƷ����
	Medicine();//���캯��
	~Medicine();//��������
	void Set();//���뺯��
	void Pnumber();//������������
	void Pnum();//�����������
	void Pprice();//������������
	void Pvolume();//���۶���������
	void Print();//��ӡ���ݺ���
	void Printf();//������ļ�����
	void Printf0();//д�ļ�����
};

void Medicine::Print()//�����������ӡҩƷ��Ϣ
{
	cout << "����\t        ���\t����\t����\t���۶�\n";
	for (numl i = 1; i <= L; i++)
	{
		printf("%s\t%s\t%.1lf\t%.0lf\t%.2lf\n", m[i].name, m[i].num, m[i].price, m[i].number, m[i].volume);
	}
}

Medicine::Medicine()
{
	L = M->number = M->price = M->volume = 0;
	M->name[0] = ' ';
	cout << "��ӭ����Medicineϵͳ����ƽ̨\n\n\n";
}

Medicine::~Medicine()
{
	//cout << "��л����ʹ�ã�ף��������죡\n\n\n\n";
}

void Medicine::Set()
{
	cout << "����������ҩƷ����\n";
	cin >> L;
	cout << "����������ҩƷ�����ƣ���ţ����ۣ�����\n";
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
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	for (numl i = 1; i <= L; i++)
	{
		fputs(m[i].name, fp);//���ļ���д�ַ���
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
	cout << "������������Ľ���ǣ�\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	fputs("����ҩƷ�������������:\n\n", fp);
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
	cout << "�������۶�����Ľ���ǣ�\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	fputs("����ҩƷ�����۶��������:\n\n", fp);
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
	cout << "���ݵ�������Ľ���ǣ�\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	fputs("����ҩƷ�ĵ����������:\n\n", fp);
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
	cout << "������������Ľ���ǣ�\n\n";
	Print();
	cout << '\n';
	FILE* fp;
	fp = fopen("medicine", "a");
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	fputs("����ҩƷ�������������:\n\n", fp);
	fclose(fp);
	Printf();
}

void Medicine::Printf0()
{
	FILE* fp;
	fp = fopen("medicine", "w");
	if (!fp) { cout << "��ȡ�ļ�ʧ��"; exit(0); }
	fputs("ҩƷ�ĳ�ʼ�������£�\n\n", fp);
	for (numl i = 1; i <= L; i++)
	{
		fputs(m[i].name, fp);//���ļ���д�ַ���
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
	cout << "��ѡ������ķ�ʽ��\n--------------------\n";
	cout << "����ҩƷ�ĵ��������밴��1��\n����ҩƷ�����۶������밴��2��\n����ҩƷ�ı�������밴��3��\n����ҩƷ�����������밴��4��\n�����Ҫ�˳�ϵͳ�밴��0��\n";
	cout << "--------------------\n";
	int aa;
	bool f = 0;
	for (int ii = 1; ii < 5; ii++)
	{
		cin >> aa;
		if (aa > 4 || aa < 0)
			cout << "�Բ���������������������\n";
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
		default:cout << "�Բ���������������������";
			break;
		}
		if (f)break;
		cout << "���������ѡ��";
		cin >> aa;
	}
}

void cc()
{
	Medicine F;
	F.Set();
	F.Printf0();
	ssort(F);
	cout << "\n\n\n��л����ʹ�ã�ף��������죡\n\n\n\n";
}


//#include "Medicine.h"
int main()
{
	cc();//�����ܺ���
	system("pause");
	return 0;
}
