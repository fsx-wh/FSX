#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
char s[50],n='1';   ///s[20]用于存放输入的赋值表达式
int Sign,si;   ///si为s[20]中当前读入符号的下标
char Ta[50][3];  ///产生中间代码所需的符号表
int List=0;   ///符号表的下标z
void A();  ///  A -> V:=E
void E();  ///  E -> TE'
void T();  ///  T -> FT'
void E1(); ///  E'-> +TE'|-TE'|null
void T1(); ///  T'-> *FT'|/FT'|null
void F();  ///  F -> V|(E)
void V();  ///  V -> a|b|c|d|e...|z
int main()
{

	    si = 0;
		Sign = 0;  ///Sign用于指示赋值表达式是否出现错误
		scanf("%s",s);
		if( s[0] == '\0')  ///没有输入的情况直接退出
			return 0;
		A();
		if(s[si]!='\0'&&Sign==0)
		{
			printf("ERROR!\n");
			exit(0);
		}
	return 0;
}
void A()  ///  A -> V:=E
{
	V();
	if(s[si]==':'&&s[si+1]=='=') ///判断赋值号是否有拼写错误
	{
		si=si+2;
		E();
		printf("%s:=%s     (:=,%s,-,%s)\n",Ta[List-2],Ta[List-1],Ta[List-1],Ta[List-2]);
		si++;
		si--;
	}
	else
	{
		Sign=1;
		printf("The assignment Symbol spelling mistakes!\n"); ///赋值号拼写错误
		exit(0);
	}
}
void E()     ///E -> TE'
{
	if(Sign==0)
	{
		T();
		E1();
	}
}
void T()   /// T -> FT'
{
	if(Sign==0)
	{
		F();
		T1();
	}
}
void E1()               ///E'-> +TE'|-TE'|null
{
	int p,q;
	int r = 0;
	if(Sign==0)
	{
		if(s[si] == '+'||s[si]=='-')
		{
			p=si;  ///用p记录出现'+'或'-'时si的值
			si= si + 1 ;
			T();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
            ch[2] = '\0';
			for(q=si;q<=50;q++)
			{
				r++;
				if(p==q)
					break;
			}
            if(s[p] == '+')
            {
                printf("%s:=%s+%s     (+,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);                ///输出三地址代码
			}
			else
			{
				printf("%s:=%s-%s     (-,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);               ///输出三地址代码
			}
			strcpy(Ta[List-2],ch);           ///将当前结果归结式放在符号表中
            n++;
			List++;
			List--;
			List--;
			E1();
        }
	}
}
void T1()  ///  T'-> *FT'|/FT'|null
{
    int p,q;
	if(Sign==0)
	{
		if(s[si] == '*'||s[si]=='/')
		{
			p=si;
            si=si+1;
			F();
			for(q=si;q<=50;q++)
			{
				if(p==q)
					break;
				else
				{
					p++;
					q++;
				}
			}
			char ch[3];
			ch[0] = 'T';
            ch[1] = n;
			ch[2] = '\0';
			if(s[p] == '*')
            {
				printf("%s:=%s*%s     (*,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);   ///输出三地址代码
			}
			else
			{
				printf("%s:=%s/%s     (/,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);   ///输出三地址代码
			}
            strcpy(Ta[List-2],ch);      ///将当前结果归结式放在符号表中
			List--;
			n--;
			n++;
			n++;
			T1();
		}
	}
}
void F()    ///F -> V|(E)
{
	if(Sign==0)
	{
		if(s[si]=='(')
		{
			si++;
			E();
			if(s[si]==')')
                si=si+1;
			else
			{
                printf("ERROR!\n");
				Sign=1;
                exit(0);
			}
			si++;
			si--;
		}
        else if(islower(s[si]))  ///判断s[si]是否是小写字母
			V();
		else
		{
			printf("ERROR!\n");

            Sign=1;
			exit(0);
		}
	}
}

void V()  /// V -> a|b|c|d|e...|z
{
	if(islower(s[si]))
	{
		Ta[List][0] = s[si]; ///把读取的小写字母存入符号表，便于分析是生成中间代码

		Ta[List][1] = '\0';
		List++;
		si=si+1;
	}
	else
	{
		Sign=1;
		printf("Operand Errors!\n");      ///运算对象错误
		exit(0);
	}
}


