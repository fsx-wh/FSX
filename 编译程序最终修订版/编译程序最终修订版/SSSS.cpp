/*�������ɷ���������*/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* g[11] = { "void", "int", "float", "char", "if", "else","while","do","for","return","main" };
int Number[11] = { 3,4,5,6,7,8,9,10,11,12,13 };

char* ss[6] = { "<=", ">=", "==", "!=", "&&", "||" };
int Number1[6] = { 20,22,23,24,25,26 };

FILE* fp;
int Line = 1;
bool flag = 0, ff = 0;
int iso;

void CC();//�����ܺ���
int ISKW(char str[]);//�жϹؼ��ֺ���
bool ISC(char ch);//�ַ�����
bool ISNUM(char ch);//�ж����ֺ���
bool ISJU(char str[]);//�жϳ�����
void SAM(char c, FILE* fp);//ĳ���غ���
int ISO(char sss[]);

int main()
{
	FILE* fp1;
	fp1 = fopen("11.txt", "w");//д��
	char c;
	for (;;) {
		scanf("%c", &c);
		fputc(c, fp1);   //���̶�ȡ���ַ��뵽 �ļ���
		if (c == '#')break;
	}
	fclose(fp1);
	fp = fopen("11.txt", "r");//��ȡ
	CC();//����
	return 0;
}

void CC() //����������
{
	int n;
	char str1[100], sss[3];
	char c, cc;
	char d = '?';
	int i = 0;
	char str[100];
	int error_num = 0;
	int ans[100];
	for (; (c = fgetc(fp)) != EOF;) {
		if (c == ' ' || c == '\t') {
			continue;
		}
		else if (c == '\n') {
			SAM(c, fp);
		}
		else if (c == '/') {
			i = 0;
			flag = 1;
			c = fgetc(fp);
			if (c == '*') {
				for (; /*c != '/'*/;) {
					if (d == '*' && c == '/') { break; }
					d = c;
					c = fgetc(fp);
				}
				fseek(fp, -1, 1);      //��ǰ�ƶ�һ���ַ�
			}
			else {
				for (; c != '\n';) {
					c = fgetc(fp);
				}
				fseek(fp, -1, 1);
			}
		}
		else if (ISNUM(c)) {
			i = 0;//���ڲ���������һ��������������ڵ�������һ�����ֵ�ʱ��i��ֵ��ı䡣
			for (; ISNUM(c) || ISC(c);) {//�������ִ���9����������ҿ��ǵ��˳������������������ַ�
				str1[i] = c;
				i++;
				c = fgetc(fp);
			}
			str1[i] = '\0';
			fseek(fp, -1, 1);   //���ڶ����һ����ĸ����ʱ�ļ�λ�ñ��Ϊ�����ĸ����һ����ĸ��������Ҫ��ǰ�ƶ�һ��λ�á�
			if (ISJU(str1)) {
				cout << "<2," << str1 << ">,";
			}
			else {
				error_num++;
				ans[error_num] = Line;//����������е��кŸ�ֵ����
				cout << "LexicalError,";
			}
		}
		else if (ISC(c)) {
			i = 0;
			for (; ISC(c) || ISNUM(c);) {
				str[i++] = c;
				c = fgetc(fp);
			}
			str[i] = '\0';
			i = 0;
			fseek(fp, -1, SEEK_CUR);
			n = ISKW(str);
			if (n != 0) {
				cout << "<" << n << ",->,";
			}
			else {
				cout << "<1," << str << ">,";
			}
		}
		else {
			if ((cc = fgetc(fp)) != EOF) {
				sss[0] = c;
				sss[1] = cc;
				sss[2] = '\0';
				if ((iso = ISO(sss)) != 0) {
					cout << '<' << iso << ",->,";
					ff = 1;
					//fseek(fp, -1, 1);
				}
			}
			if (ff == 0) {
				if (c != '#')
					fseek(fp, -1, 1);
				switch (c) {
				case '+': cout << "<14,->,"; break;
				case '-': cout << "<15,->,"; break;
				case '*': cout << "<16,->,"; break;
				case '/': cout << "<17,->,"; break;
				case '%': cout << "<18,->,"; break;
				case '<': cout << "<19,->,"; break;
					//case '<=':cout << "<20,->,"; break;
				case '>': cout << "<21,->,"; break;
					//case '>=':cout << "<22,->,"; break;
					//case '==':cout << "<23,->,"; break;
					//case '!=':cout << "<24,->,"; break;
					//case '&&':cout << "<25,->,"; break;
					//case '||':cout << "<26,->,"; break;
				case '=': cout << "<27,->,"; break;
				case '(': cout << "<28,->,"; break;
				case ')': cout << "<29,->,"; break;
				case '[': cout << "<30,->,"; break;
				case ']': cout << "<31,->,"; break;
				case '{': cout << "<32,->,"; break;
				case '}': cout << "<33,->,"; break;
				case ';': cout << "<34,->,"; break;
				case ',': cout << "<35,->,"; break;
				}
			}
			ff = 0;
		}
	}
	if (error_num != 0) {
		cout << "LexicalError(s) on line(s) ";
		for (int ii = 1; ii <= error_num; ii++) {
			cout << ans[ii] << ',';
		}
		cout << "\n";
	}
}

void SAM(char c, FILE * fp) {
	char d;
	FILE* fpp;
	fpp = fp;
	for (;;) {
		if ((d = fgetc(fp)) != EOF) {
			if (d == ' ')
			{
				continue;
			}
			if (d == '\n') {
				fseek(fp, -1L, SEEK_CUR);
				break;
			}
			else {
				Line++;
				fseek(fp, -1L, SEEK_CUR);
				if (flag == 1) {
					flag = 0;
				}
				else
				{
					cout << endl;
				}
				break;
			}
		}
	}
}

bool ISJU(char str[])//�жϳ�����
{
	int i, N;
	N = strlen(str);
	if (N == 1) {
		return 1;
	}
	else {
		for (i = 0; i < N; i++)
			if (ISC(str[i]))break;
		if (i == N)
			return 1;
		else
			return 0;
	}
}

bool ISNUM(char ch)//�ж����ֺ���
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return 0;
}

bool ISC(char ch)//�ַ�����
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return 1;
	else
		return 0;
}

int ISKW(char str[])//�жϹؼ��ֺ���
{
	int i, m;
	for (i = 0; i < 11; i++) {
		if (strcmp(str, g[i]) == 0) {
			m = Number[i];
			return m;
		}
	}
	return 0;
}


int ISO(char sss[]) {
	int i, m;
	for (i = 0; i < 6; i++) {
		if (strcmp(sss, ss[i]) == 0) {
			m = Number1[i];
			return m;
		}
	}
	return 0;
}


