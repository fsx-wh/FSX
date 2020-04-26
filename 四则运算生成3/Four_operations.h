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
	int num;//出题数量
	int Max;//最大值
	int Correct;//对题数
	bool needkuohao;//是否需要小括号
	bool needadd;//是否需要+
	bool needsub;//是否需要-
	bool needmul;//是否需要x
	bool needdiv;//是否需要÷
	bool needprint;//是否需要打印到屏幕
	bool needwritetofile;//是否需要写到文件
	bool needfloat;//是否需要小数运算
	bool needansw;//是否需要现场答题
	FData *da;

	Four_operations();
	void putall(int Max, bool needkuohao, bool needadd, bool needsub, bool needmul, bool needdiv, bool needprint, bool needw, bool needf,bool needansw);//得到相关数据
	int Randnumberint();//得到整数随机数
	float Randnumberfloat();//得到小数随机数
	void Writefile();//写文件里
	void Print();//输出到屏幕
	float cal(float a, float b, float c, int d, int e,int kuohao);//计算结果
	float caleasy(float a, float b, int c);//简单计算
	int cc();//主功能函数
	void putnum(int num);//得到个数
	int getcharacter();//得到随机符号
	void changecharacter(int i, int x,int y);//运算符号解码
};
