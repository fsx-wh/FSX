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
	for (;;)
	{
		cout << "*******欢迎使用四则运算出题器 ！***********" << endl;
		cout << endl;
		cout << "输入2个数字，0代表结束，1代表继续：" << endl;
		cin >> n;
		while(n != 0 && n != 1)
		{
			cout << "输入数据不合理，请重新输入！" << endl;
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
			cin >> needkuohao;
			cout << "是否需要小数？需要按1，不需要按0：" << endl;
			cin >> needfloat;
			cout << "是否需要写入文件？需要按1，不需要按0：" << endl;
			cin >> needwritetofile;
			cout << "是否需要输出到屏幕显示？需要按1，不需要按0：" << endl;
			cin >> needprint;
			cout << "是否需要加法？需要按1，不需要按0：" << endl;
			cin >> needadd;
			cout << "是否需要减法？需要按1，不需要按0：" << endl;
			cin >> needsub;
			cout << "是否需要乘法？需要按1，不需要按0：" << endl;
			cin >> needmul;
			cout << "是否需要除法？需要按1，不需要按0：" << endl;
			cin >> needdiv;
			cout << "是否需要现场答题？需要按1，不需要按0：" << endl;
			cin >> needansw;
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