//#include<stdio.h>
//
//#include<stdlib.h>
//
//#include<string.h>
//char prog[80], token[8];
//char ch;
//int syn, p, m = 0, n, sum, kk = 0;
//char* rwtab[6] = { "function","if", "then", "while" , "do" , "endfunc" };
//void yucu();
//void expression();
//void statement();
//void factor();
//void term();
//void irparser();
//
//void scaner()
//{
//	memset(token, 0, sizeof(token));
//	memset(prog, 0, sizeof(prog));
//
//	while (ch == ' ' || ch == '\n')
//		ch = prog[p++];
//
//	m = 0;
//	if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
//	{
//		while ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch <= '9' && ch >= '0'))
//		{
//			token[m++] = ch;
//			ch = prog[p++];
//		}
//		syn = 10;
//		for (n = 0; n < 6; n++)
//			if (strcmp(token, rwtab[n]) == 0)
//			{
//				syn = n + 1;
//				break;
//			}
//		token[m++] = '\0';
//	}
//	else
//	{
//		if (ch <= '9' && ch >= '0') {
//			sum = 0;
//			while (ch <= '9' && ch >= '0')
//			{
//				sum = sum * 10 + ch - '0';
//				ch = prog[p++];
//
//			}
//			syn = 11;
//		}
//		else
//		{
//
//			switch (ch)
//			{
//			case'<':m = 0; token[m++] = ch;
//				ch = prog[p++];
//				if (ch == '=')
//				{
//					syn = 22;
//					token[m + 1] = ch;
//				}
//				else
//				{
//					syn = 20; ch = prog[--p];
//				}
//				break;
//			case'>': m = 0; token[m++] = ch;
//				ch = prog[p++];
//				if (ch == '=')
//				{
//					syn = 24;
//					token[m++] = ch;
//				}
//				else
//				{
//					syn = 23; p--;
//				}
//				break;
//			case'=': m = 0; token[m++] = ch;
//				ch = prog[p++];
//				if (ch == '=')
//				{
//					syn = 25;
//					token[m++] = ch;
//				}
//				else
//				{
//					syn = 18;
//					ch = prog[--p];
//				}
//				break;
//			case'! ': m = 0; token[m++] = ch;
//				ch = prog[++p];
//				if (ch == '=')
//				{
//					syn = 22;
//					token[m++] = ch;
//				}
//				else
//					syn = -1;
//				break;
//			case'+':syn = 13; token[0] = ch; break;
//			case'-': syn = 14; token[0] = ch; break;
//			case'*': syn = 15; token[0] = ch; break;
//			case'/': syn = 16; token[0] = ch; break;
//			case' ; ': syn = 26; token[0] = ch; break;
//			case' ( ': syn = 27; token[0] = ch; break;
//			case' ) ': syn = 28; token[0] = ch; break;
//			case'#': syn = 0; token[0] = ch; break;
//			default:syn = -1;
//			}
//			ch = prog[p++];
//		}
//
//	}
//}
//void irparser()
//{
//	if (syn == 1)
//	{
//		scaner();
//		yucu();/*��䴮����*/
//		if (syn == 6)
//			/*����endfunc*/
//		{
//			scaner();
//			if (syn == 0 && kk == 0)/*�������ʶ����*/
//				printf("success ");
//		}
//		else
//		{
//			if (kk != 1)/*û��endfunc ����*/
//			{
//				printf("error !need 'endfunc '");
//			}
//
//		}
//	}
//	else
//	{
//		printf("error !need 'function '");
//		kk = 1;
//	}
//}
//void yucu()
//{
//	statement();/*��������������*/
//	while (syn == 26)/*�������ʶ�����������ʶ��*/ {
//		scaner();
//		statement();
//	}
//	return;
//}
//void statement()/*����������*/
//{
//	if (syn == 10)
//	{
//		scaner();
//		if (syn == 18)
//			//����Ǹ�ֵ���
//		{
//			scaner();
//
//			expression();
//		}
//		//�������ʵ���﷨�����ж����
//		else
//		{
//			printf("error !evaluate tag error ");
//			kk = 1;
//		}
//	}
//	else if (syn == 6)
//		return;
//
//	else if (syn == 2)
//
//	{
//		scaner();
//		if (syn == 27)
//			//�ж�����ƥ��
//		{
//			do
//			{
//				scaner();
//				//���������ڲ����б��ʽ����
//				expression();
//			} while (syn != 28);
//		}
//		else {
//			printf("error! need another )'");
//			kk = 1;
//		}
//		scaner();
//		statement();
//	}
//
//	else if (syn == 4)
//	{
//		scaner();//ch = prog[p++];
//		if (syn == 27)
//		{
//			do
//			{
//				scaner();
//				expression();
//			} while (syn != 28);
//		}
//		else {
//			printf("error ! need another ')'");
//			kk = 1;
//		}
//		scaner();
//		statement();
//	}
//	else
//	{
//		printf("error !the statement error!");
//		kk = 1;
//	}
//}
//void expression()/*���ʽ��������*/
//{
//	term();
//	while (syn == 13 || syn == 14)
//	{
//		scaner();
//		term();
//	}
//	return;
//}
//
//void term()/*���������*/
//{
//	factor();
//	while (syn == 15 || syn == 16) {
//		scaner();
//		factor();
//	}
//	return;
//}
//void factor()
//{
//	if (syn == 10 || syn == 11) { scaner(); }
//	else/*���Ƿ��Ǳ��ʽ*/
//	{
//		expression();
//		if (syn == 27)
//		{
//			scaner();
//			expression();
//			if (syn == 28)
//			{
//				scaner();
//			}
//			else
//			{
//				printf("error! need another ')'");
//				kk = 1;
//			}
//		}
//		else
//		{
//			printf("error !the expression error!");
//		}
//	}
//}
//void main()
//{
//	p = 0;
//	printf("\nplease input the string: \n");
//	do
//	{
//		ch = getchar();
//		prog[p++] = ch;
//	} while (ch != '#');
//	p = 0;
//	ch = prog[p++];
//	scaner();
//	irparser();
//}

//char prog[100], token[8], ch;
//char* rwtab[6] = { "begin","if","then","while","do","end" };
//int syn, p, m, n, sum;
//int kk;
//void factor(void);
//void expression(void);
//void yucu(void);
//void term(void);
//void statement(void);
//void lrparser(void);
//void scaner(void);
//int main(void)
//{
//	p = kk = 0;
//	printf("\n������һ����'begin'��ͷ����'#'�����ĵ��ʴ�: \n");
//	do
//	{
//		scanf_s("%c", &ch);
//		prog[p++] = ch;
//	} while (ch != '#');
//	p = 0;
//	scaner();
//	lrparser();
//	//getch();
//}
//void lrparser(void)
//{
//	if (syn == 1)
//	{
//		scaner(); /*����һ�����ʷ���*/
//		yucu(); /*����yucu()������*/
//		if (syn == 6)
//		{
//			scaner();
//			if ((syn == 0) && (kk == 0))
//				printf("���뵥�ʴ��ɹ�!\n");
//		}
//		else
//		{
//			if (kk != 1) printf("���ʴ�û����'#'��Ϊ����!\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("���ʴ�û����'begin'Ϊ��ͷ!\n");
//		kk = 1;
//	}
//	return;
//}
//void yucu(void)
//{
//	statement(); /*���ú���statement();*/
//	while (syn == 26)
//	{
//		scaner(); /*����һ�����ʷ���*/
//		if (syn != 6)
//			statement(); /*���ú���statement();*/
//	}
//	return;
//}
//void statement(void)
//{
//	if (syn == 10)
//	{
//		scaner(); /*����һ�����ʷ���*/
//		if (syn == 18)
//		{
//			scaner(); /*����һ�����ʷ���*/
//			expression(); /*���ú���statement();*/
//		}
//		else
//		{
//			printf("���ʴ� ':=' ������!\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("û��Ч�ĵ��ʴ�!\n");
//		kk = 1;
//	}
//	return;
//}
//void expression(void)
//{
//	term();
//	while ((syn == 13) || (syn == 14))
//	{
//		scaner(); /*����һ�����ʷ���*/
//		term(); /*���ú���term();*/
//	}
//	return;
//}
//void term(void)
//{
//	factor();
//	while ((syn == 15) || (syn == 16))
//	{
//		scaner(); /*����һ�����ʷ���*/
//		factor(); /*���ú���factor(); */
//	}
//	return;
//}
//void factor(void)
//{
//	if ((syn == 10) || (syn == 11))
//	{
//		scaner();
//	}
//	else if (syn == 27)
//	{
//		scaner(); /*����һ�����ʷ���*/
//		expression(); /*���ú���statement();*/
//		if (syn == 28)
//		{
//			scaner(); /*����һ�����ʷ���*/
//		}
//		else
//		{
//			printf("���� '('\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("���ʴ��д�!\n");
//		kk = 1;
//	}
//	return;
//}
//void scaner(void)
//{
//	sum = 0;
//	memset(token, 0, sizeof(token));
//    memset(prog, 0, sizeof(prog));
//	m = 0;
//	ch = prog[p++];
//	while (ch == ' ')
//		ch = prog[p++];
//	if (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')))
//	{
//		while (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')) || ((ch >= '0') && (ch <= '9')))
//		{
//			token[m++] = ch;
//			ch = prog[p++];
//		}
//		p--;
//		syn = 10;
//		token[m++] = '\0';
//		for (n = 0; n < 6; n++)
//			if (strcmp(token, rwtab[n]) == 0)
//			{
//				syn = n + 1;
//				break;
//			}
//	}
//	else if ((ch >= '0') && (ch <= '9'))
//	{
//		while ((ch >= '0') && (ch <= '9'))
//		{
//			sum = sum * 10 + ch - '0';
//			ch = prog[p++];
//		}
//		p--;
//		syn = 11;
//	}
//	else
//		switch (ch)
//		{
//		case '<':
//			m = 0;
//			ch = prog[p++];
//			if (ch == '>')
//			{
//				syn = 21;
//			}
//			else if (ch == '=')
//			{
//				syn = 22;
//			}
//			else
//			{
//				syn = 20;
//				p--;
//			}
//			break;
//		case '>':
//			m = 0;
//			ch = prog[p++];
//			if (ch == '=')
//			{
//				syn = 24;
//			}
//			else
//			{
//				syn = 23;
//				p--;
//			}
//			break;
//		case ':':
//			m = 0;
//			ch = prog[p++];
//			if (ch == '=')
//			{
//				syn = 18;
//			}
//			else
//			{
//				syn = 17;
//				p--;
//			}
//			break;
//		case '+':
//			syn = 13;
//			break;
//		case '-':
//			syn = 14;
//			break;
//		case '*':
//			syn = 15;
//			break;
//		case '/':
//			syn = 16;
//			break;
//		case '(':
//			syn = 27;
//			break;
//		case ')':
//			syn = 28;
//			break;
//		case '=':
//			syn = 25;
//			break;
//		case ';':
//			syn = 26;
//			break;
//		case '#':
//			syn = 0;
//			break;
//		default:
//			syn = -1;
//			break;
//		}
//}

#include "stdio.h"
#include "string.h"
#pragma warning(disable : 4996)
char prog[100], token[8], ch;//prog[100]�������洢Ҫ����Ķ���token������ؼ��ֱȽϣ�ch�����洢һ���ַ�
char* rwtab[6] = { "begin","if","then","while","do","end" };//�ؼ��ֱ�
int syn, p, m, n, sum;
/*syn���ֱ��룬pΪprog�����ָ�룬mΪtoken�����ָ�룬nΪrwtab�����ָ�룬sumΪ�ʷ����������������ֵ��С*/
int flag;//flag���ж��Ƿ�end�й�

void factor(void);//��ʽ factor
void expression(void);//���ʽ expression
void yucu(void);
void term(void);//�� term
void statement(void);// ��� statement
void parser(void);
void scaner(void);//ɨ����


int main(void)
{
	p = flag = 0;
	printf("\n����������ԣ�����: \n");

	/*�������ж�ȡҪ����Ķ��󣬲��洢��prog[]������*/
	do
	{
		scanf("%c", &ch);
		//printf("\n input %c now\n",ch);
		prog[p++] = ch;
	} while (ch != '#');

	p = 0;
	scaner();//��Ҫ��ɸ�ֵ�ֱ���ȴʷ���������
	parser();//���ø��ֵݹ��ӳ�������﷨�����Ĺ���
	//getch();
}

/*���ø��ֵݹ��ӳ�������﷨�����Ĺ���*/
void parser(void)
{
	if (syn == 1)//begin
	{
		scaner();       /*����һ�����ʷ���*/
		yucu();         /*����yucu()������*/

		if (syn == 6)//end
		{
			scaner();
			if ((syn == 0) && (flag == 0))//����#��flag=0
				printf("success!\n");
		}
		else
		{
			if (flag != 1) printf("û����end����!\n");//flag���ж��Ƿ�end
			flag = 1;
		}
	}
	else
	{
		printf("û����end��β!\n");
		flag = 1;
	}

	return;
}

void yucu(void)
{
	statement();         /*���ú���statement();*/

	while (syn == 26)//�ֺ�
	{
		scaner();          /*����һ�����ʷ���*/
		if (syn != 6)
			statement();         /*���ú���statement();*/
	}

	return;
}

void statement(void)//���
{
	if (syn == 10)
	{
		scaner();        /*����һ�����ʷ���*/
		if (syn == 18)
		{
			scaner();      /*����һ�����ʷ���*/
			expression();      /*���ú���expression();*/
		}
		else
		{
			printf(":=����\n");
			flag = 1;
		}
	}
	else if(syn == 2)
	{
		scaner();
		if (syn == 27) {
			do 
			{
				scaner();
				expression();
			} while (syn != 28);
			
		}
		else {
			printf("û��������");
			flag = 1;
		}
		scaner();
		statement();
	}
	else if(syn==4)
	{
		scaner();
		if (syn == 27) {
			do
			{
				scaner();
				expression();
			} while (syn != 28);

		}
		else {
			printf("û��������");
			flag = 1;
		}
		scaner();
		statement();

	}
	else
	{
		printf("���Ӵ���!\n");
		flag = 1;
	}

	return;
}

void expression(void)
{
	term();

	while ((syn == 13) || (syn == 14))//+ -
	{
		scaner();             /*����һ�����ʷ���*/
		term();               /*���ú���term();*/
	}

	return;
}

void term(void)
{
	factor();

	while ((syn == 15) || (syn == 16))//* /
	{
		scaner();             /*����һ�����ʷ���*/
		factor();              /*���ú���factor(); */
	}

	return;
}

void factor(void)//��ʽ������
{
	if ((syn == 10) || (syn == 11))//��ʶ��������
	{
		scaner();
	}
	else if (syn == 27)//��ͷ�������ţ�
	{
		scaner();           /*����һ�����ʷ���*/
		expression();        /*���ú���statement();*/

		if (syn == 28)//���������ţ�
		{
			scaner();          /*����һ�����ʷ���*/
		}
		else
		{
			printf("the error on '('\n");
			flag = 1;
		}
	}
	else
	{
		printf("the expression error!\n");
		flag = 1;
	}

	return;
}

/*��Ҫ��ɸ�ֵ�ֱ���ȴʷ���������*/
void scaner(void)//ɨ�������ʷ�����������
{
	sum = 0;//���ֳ�ʼ��Ϊ0

	for (m = 0; m < 8; m++)//��ʼ��token
		token[m++] = NULL;

	m = 0;//mΪtoken��ָ��
	ch = prog[p++];//����ָ��+1

	while (ch == ' ')//�����ո�+1
		ch = prog[p++];

	if (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')))//������ĸ
	{
		while (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')) || ((ch >= '0') && (ch <= '9')))
		{
			token[m++] = ch;
			ch = prog[p++];//p+1,�´�ѭ��ʹ��
		}
		p--;//ѭ��������Ҫ��1
		syn = 10;//10����ĸ��ͷ
		token[m++] = '\0';//\0Ϊ�ַ���������

		/*�б��Ƿ�Ϊ�ؼ���*/
		for (n = 0; n < 6; n++)//nΪrwtab��ָ��
			if (strcmp(token, rwtab[n]) == 0) // rcmp����ֵΪ0��������������С��ͬ
			{
				syn = n + 1;
				break;
			}
	}


	else if ((ch >= '0') && (ch <= '9'))//��������
	{
		while ((ch >= '0') && (ch <= '9'))
		{
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;//����
		syn = 11;//11Ϊ����
	}



	/*�����ֺ���ĸ��ͷ�������������*/
	else
		switch (ch)
		{
		case '<':
			m = 0;
			ch = prog[p++];
			if (ch == '>')
			{
				syn = 21;
			}
			else if (ch == '=')
			{
				syn = 22;
			}
			else
			{
				syn = 20;
				p--;//����
			}
			break;

		case '>':
			m = 0;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 24;
			}
			else
			{
				syn = 23;
				p--;
			}
			break;

		case ':':
			m = 0;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 18;
			}
			else
			{
				syn = 17;
				p--;
			}
			break;

		case '+':
			syn = 13;
			break;

		case '-':
			syn = 14;
			break;

		case '*':
			syn = 15;
			break;

		case '/':
			syn = 16;
			break;

		case '(':
			syn = 27;
			break;

		case ')':
			syn = 28;
			break;

		case '=':
			syn = 25;
			break;

		case ';':
			syn = 26;
			break;

		case '#':
			syn = 0;
			break;

		default:
			syn = -1;
			break;
		}
}
