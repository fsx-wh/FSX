#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
char s[50],n='1';   ///s[20]���ڴ������ĸ�ֵ���ʽ
int Sign,si;   ///siΪs[20]�е�ǰ������ŵ��±�
char Ta[50][3];  ///�����м��������ķ��ű�
int List=0;   ///���ű���±�z
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
		Sign = 0;  ///Sign����ָʾ��ֵ���ʽ�Ƿ���ִ���
		scanf("%s",s);
		if( s[0] == '\0')  ///û����������ֱ���˳�
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
	if(s[si]==':'&&s[si+1]=='=') ///�жϸ�ֵ���Ƿ���ƴд����
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
		printf("The assignment Symbol spelling mistakes!\n"); ///��ֵ��ƴд����
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
			p=si;  ///��p��¼����'+'��'-'ʱsi��ֵ
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
                printf("%s:=%s+%s     (+,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);                ///�������ַ����
			}
			else
			{
				printf("%s:=%s-%s     (-,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);               ///�������ַ����
			}
			strcpy(Ta[List-2],ch);           ///����ǰ������ʽ���ڷ��ű���
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
				printf("%s:=%s*%s     (*,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);   ///�������ַ����
			}
			else
			{
				printf("%s:=%s/%s     (/,%s,%s,%s)\n",ch,Ta[List-2],Ta[List-1], Ta[List-2],Ta[List-1],ch);   ///�������ַ����
			}
            strcpy(Ta[List-2],ch);      ///����ǰ������ʽ���ڷ��ű���
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
        else if(islower(s[si]))  ///�ж�s[si]�Ƿ���Сд��ĸ
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
		Ta[List][0] = s[si]; ///�Ѷ�ȡ��Сд��ĸ������ű����ڷ����������м����

		Ta[List][1] = '\0';
		List++;
		si=si+1;
	}
	else
	{
		Sign=1;
		printf("Operand Errors!\n");      ///����������
		exit(0);
	}
}


