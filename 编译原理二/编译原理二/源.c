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
//		yucu();/*语句串分析*/
//		if (syn == 6)
//			/*读到endfunc*/
//		{
//			scaner();
//			if (syn == 0 && kk == 0)/*程序分析识别完*/
//				printf("success ");
//		}
//		else
//		{
//			if (kk != 1)/*没以endfunc 结束*/
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
//	statement();/*调用语句分析函数*/
//	while (syn == 26)/*—个语句识别结束，继续识别*/ {
//		scaner();
//		statement();
//	}
//	return;
//}
//void statement()/*语句分析函数*/
//{
//	if (syn == 10)
//	{
//		scaner();
//		if (syn == 18)
//			//如果是赋值语句
//		{
//			scaner();
//
//			expression();
//		}
//		//这个过程实现语法分析判断语句
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
//			//判断括号匹配
//		{
//			do
//			{
//				scaner();
//				//进入括号内部进行表达式分析
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
//void expression()/*表达式分析函数*/
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
//void term()/*项分析函数*/
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
//	else/*看是否是表达式*/
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
//	printf("\n请输入一段以'begin'开头，以'#'结束的单词串: \n");
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
//		scaner(); /*读下一个单词符号*/
//		yucu(); /*调用yucu()函数；*/
//		if (syn == 6)
//		{
//			scaner();
//			if ((syn == 0) && (kk == 0))
//				printf("输入单词串成功!\n");
//		}
//		else
//		{
//			if (kk != 1) printf("单词串没有以'#'作为结束!\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("单词串没有以'begin'为开头!\n");
//		kk = 1;
//	}
//	return;
//}
//void yucu(void)
//{
//	statement(); /*调用函数statement();*/
//	while (syn == 26)
//	{
//		scaner(); /*读下一个单词符号*/
//		if (syn != 6)
//			statement(); /*调用函数statement();*/
//	}
//	return;
//}
//void statement(void)
//{
//	if (syn == 10)
//	{
//		scaner(); /*读下一个单词符号*/
//		if (syn == 18)
//		{
//			scaner(); /*读下一个单词符号*/
//			expression(); /*调用函数statement();*/
//		}
//		else
//		{
//			printf("单词串 ':=' 表达错误!\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("没有效的单词串!\n");
//		kk = 1;
//	}
//	return;
//}
//void expression(void)
//{
//	term();
//	while ((syn == 13) || (syn == 14))
//	{
//		scaner(); /*读下一个单词符号*/
//		term(); /*调用函数term();*/
//	}
//	return;
//}
//void term(void)
//{
//	factor();
//	while ((syn == 15) || (syn == 16))
//	{
//		scaner(); /*读下一个单词符号*/
//		factor(); /*调用函数factor(); */
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
//		scaner(); /*读下一个单词符号*/
//		expression(); /*调用函数statement();*/
//		if (syn == 28)
//		{
//			scaner(); /*读下一个单词符号*/
//		}
//		else
//		{
//			printf("错误 '('\n");
//			kk = 1;
//		}
//	}
//	else
//	{
//		printf("单词串有错!\n");
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
char prog[100], token[8], ch;//prog[100]，用来存储要处理的对象，token用来与关键字比较，ch用来存储一个字符
char* rwtab[6] = { "begin","if","then","while","do","end" };//关键字表
int syn, p, m, n, sum;
/*syn是种别码，p为prog数组的指针，m为token数组的指针，n为rwtab数组的指针，sum为词法分析器里的数字数值大小*/
int flag;//flag与判断是否end有关

void factor(void);//因式 factor
void expression(void);//表达式 expression
void yucu(void);
void term(void);//项 term
void statement(void);// 语句 statement
void parser(void);
void scaner(void);//扫描器


int main(void)
{
	p = flag = 0;
	printf("\n请输入语句以＃结束: \n");

	/*从命令行读取要处理的对象，并存储在prog[]数组中*/
	do
	{
		scanf("%c", &ch);
		//printf("\n input %c now\n",ch);
		prog[p++] = ch;
	} while (ch != '#');

	p = 0;
	scaner();//主要完成赋值种别码等词法分析功能
	parser();//调用各种递归子程序，完成语法分析的过程
	//getch();
}

/*调用各种递归子程序，完成语法分析的过程*/
void parser(void)
{
	if (syn == 1)//begin
	{
		scaner();       /*读下一个单词符号*/
		yucu();         /*调用yucu()函数；*/

		if (syn == 6)//end
		{
			scaner();
			if ((syn == 0) && (flag == 0))//出现#且flag=0
				printf("success!\n");
		}
		else
		{
			if (flag != 1) printf("没有以end结束!\n");//flag来判断是否end
			flag = 1;
		}
	}
	else
	{
		printf("没有以end结尾!\n");
		flag = 1;
	}

	return;
}

void yucu(void)
{
	statement();         /*调用函数statement();*/

	while (syn == 26)//分号
	{
		scaner();          /*读下一个单词符号*/
		if (syn != 6)
			statement();         /*调用函数statement();*/
	}

	return;
}

void statement(void)//语句
{
	if (syn == 10)
	{
		scaner();        /*读下一个单词符号*/
		if (syn == 18)
		{
			scaner();      /*读下一个单词符号*/
			expression();      /*调用函数expression();*/
		}
		else
		{
			printf(":=出错\n");
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
			printf("没有右括号");
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
			printf("没有右括号");
			flag = 1;
		}
		scaner();
		statement();

	}
	else
	{
		printf("句子错误!\n");
		flag = 1;
	}

	return;
}

void expression(void)
{
	term();

	while ((syn == 13) || (syn == 14))//+ -
	{
		scaner();             /*读下一个单词符号*/
		term();               /*调用函数term();*/
	}

	return;
}

void term(void)
{
	factor();

	while ((syn == 15) || (syn == 16))//* /
	{
		scaner();             /*读下一个单词符号*/
		factor();              /*调用函数factor(); */
	}

	return;
}

void factor(void)//因式处理函数
{
	if ((syn == 10) || (syn == 11))//标识符，数字
	{
		scaner();
	}
	else if (syn == 27)//开头是左括号（
	{
		scaner();           /*读下一个单词符号*/
		expression();        /*调用函数statement();*/

		if (syn == 28)//出现右括号）
		{
			scaner();          /*读下一个单词符号*/
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

/*主要完成赋值种别码等词法分析功能*/
void scaner(void)//扫描器，词法分析器内容
{
	sum = 0;//数字初始化为0

	for (m = 0; m < 8; m++)//初始化token
		token[m++] = NULL;

	m = 0;//m为token的指针
	ch = prog[p++];//数组指针+1

	while (ch == ' ')//遇到空格+1
		ch = prog[p++];

	if (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')))//遇到字母
	{
		while (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')) || ((ch >= '0') && (ch <= '9')))
		{
			token[m++] = ch;
			ch = prog[p++];//p+1,下次循环使用
		}
		p--;//循环跳出，要－1
		syn = 10;//10，字母开头
		token[m++] = '\0';//\0为字符串结束符

		/*判别是否为关键字*/
		for (n = 0; n < 6; n++)//n为rwtab的指针
			if (strcmp(token, rwtab[n]) == 0) // rcmp返回值为0，则两个参数大小相同
			{
				syn = n + 1;
				break;
			}
	}


	else if ((ch >= '0') && (ch <= '9'))//遇到数字
	{
		while ((ch >= '0') && (ch <= '9'))
		{
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;//回溯
		syn = 11;//11为数字
	}



	/*除数字和字母开头以外的其他符号*/
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
				p--;//回溯
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
