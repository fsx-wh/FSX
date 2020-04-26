#include"Four_operations.h"

int main()
{
	int n;
	int num;
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
	bool needansw;//是否需要答题
	int kuohao;
	int add;
	int sub;
	int mul;
	int div;
	int prinn;
	int wrif;
	int fl;
	int an;
	for (;;)
	{
		cout << "*******欢迎使用四则运算出题器 ！***********" << endl;
		cout << endl;
		cout << "输入2个数字，0代表结束，1代表继续：" << endl;
		cin >> n;
		while(n != 0 && n != 1)
		{
			cout << "输入数据不合理，请重新输入！" << endl;
			cout << "输入2个数字，0代表结束，1代表继续：" << endl;
			cin >> n;
		}
		if (n == 0)
		{
			cout << "再见！" << endl;
			break;
		}
		else if (n == 1)
		{
			Four_operations f = Four_operations();
			cout << "输入出题的个数：" << endl;
			cin >> num;
			f.putnum(num);
			cout << "输入最大的整数：" << endl;
			cin >> Max;
			cout << "是否需要括号？需要按1，不需要按0：" << endl;
			cin >> kuohao;
			if (kuohao == 0)
			{
				needkuohao = false;
			}
			else
			{
				needkuohao = true;
			}
			cout << "是否需要小数？需要按1，不需要按0：" << endl;
			cin >> fl;
			if (fl == 0)
			{
				needfloat = false;
			}
			else
			{
				needfloat = true;
			}
			cout << "是否需要写入文件？需要按1，不需要按0：" << endl;
			cin >> wrif;
			if (wrif == 0)
			{
				needwritetofile = false;
			}
			else
			{
				needwritetofile = true;
			}
			cout << "是否需要输出到屏幕显示？需要按1，不需要按0：" << endl;
			cin >> prinn;
			if (prinn == 0)
			{
				needprint = false;
			}
			else
			{
				needprint = true;
			}
			cout << "是否需要加法？需要按1，不需要按0：" << endl;
			cin >> add;
			if (add == 0)
			{
				needadd = false;
			}
			else
			{
				needadd = true;
			}
			cout << "是否需要减法？需要按1，不需要按0：" << endl;
			cin >> sub;
			if (kuohao == 0)
			{
				needsub = false;
			}
			else
			{
				needsub = true;
			}
			cout << "是否需要乘法？需要按1，不需要按0：" << endl;
			cin >> mul;
			if (mul == 0)
			{
				needmul = false;
			}
			else
			{
				needmul = true;
			}
			cout << "是否需要除法？需要按1，不需要按0：" << endl;
			cin >> div;
			if (div == 0)
			{
				needdiv = false;
			}
			else
			{
				needdiv = true;
			}
			cout << "是否需要现场答题？需要按1，不需要按0：" << endl;
			cin >> an;
			if (an == 0)
			{
				needansw = false;
			}
			else
			{
				needansw = true;
			}
			if (needansw)
			{
				cout << "请同学们开始答题！" << endl;
			}
			f.putall(Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat,needansw);
			f.cc();
		}
	}
	return 0;
}