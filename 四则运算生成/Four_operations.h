#pragma once
#include"FData.h"
#include<cstdio>
#include<cstring>
#include<ctime>
#include<iostream>
using namespace std;

class Four_operations
{
public:
	int num;//��������
	int Max;//���ֵ
	int Correct;//������
	bool needkuohao;//�Ƿ���ҪС����
	bool needadd;//�Ƿ���Ҫ+
	bool needsub;//�Ƿ���Ҫ-
	bool needmul;//�Ƿ���Ҫx
	bool needdiv;//�Ƿ���Ҫ��
	bool needprint;//�Ƿ���Ҫ��ӡ����Ļ
	bool needwritetofile;//�Ƿ���Ҫд���ļ�
	bool needfloat;//�Ƿ���ҪС������
	bool needansw;//�Ƿ���Ҫ�ֳ�����
	FData *da;

	Four_operations();
	void putall(int Max, bool needkuohao, bool needadd, bool needsub, bool needmul, bool needdiv, bool needprint, bool needw, bool needf,bool needansw);//�õ��������
	int Randnumberint();//�õ����������
	float Randnumberfloat();//�õ�С�������
	void Writefile();//д�ļ���
	void Print();//�������Ļ
	float cal(float a, float b, float c, int d, int e,int kuohao);//������
	float caleasy(float a, float b, int c);//�򵥼���
	int cc();//�����ܺ���
	void putnum(int num);//�õ�����
	int getcharacter();//�õ��������
	void changecharacter(int i, int x,int y);//������Ž���
};
