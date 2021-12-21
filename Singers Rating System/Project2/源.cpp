#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 10
int l;
struct people    				//定义歌手结构体 
{
	int num;
	char name[20];
	int score[10];
	float aver;  				//平均分 
	int total;   				//总分 
}a[n];
void input()   					//输入歌手的信息 
{
	printf("请输入歌手人数(注意歌手人数小于10):");				//输入歌手人数 
	scanf("%d", &l);
	while (1)													//考虑不同人数的情况 
	{
		if (l >= 10 || l <= 0)
		{
			printf("歌手人数输入错误,请重新输入(注意歌手人数小于10)："
			);
			scanf("%d", &l);
		}
		else break;
	}
	int i;
	for (i = 0; i < l; i++)
	{
		printf("请输入第%d个选手的信息", i + 1);
		printf("\n");
		printf("编号：");
		scanf("%d", &a[i].num);
		printf("姓名：");
		scanf("%s", a[i].name);
	}
}
void dafen()  										// 评委打分 
{
	void average(struct people a[]);
	int i, j;
	for (i = 0; i < l; i++)								//双层循环，外层控制歌手人数，内层控制分数 
	{
		printf("第%d位歌手：", i + 1);
		printf("\n");
		for (j = 0; j < 10; j++)
		{
			printf("请输入第%d位评委的打分：", j + 1);
			scanf("%d", &a[i].score[j]);
			while (1)
			{
				if (a[i].score[j] > 100)
				{
					printf("请输入小于100的打分:");
					scanf("%d", &a[i].score[j]);
				}
				else break;
			}
		}
	}
	average(a);
}
void average(struct people a[])						//去掉最高分和最低分算平均分						
{
	int i, add, j, max, min;
	for (i = 0; i < l; i++)
	{
		add = 0;
		max = min = a[i].score[0];
		for (j = 0; j < 10; j++)
		{
			add += a[i].score[j];
			if (a[i].score[j] >= max)
				max = a[i].score[j];     					//筛选出最高分 
			else if (a[i].score[j] < min)
				min = a[i].score[j]; 						//筛选出最低分 
		}
		a[i].total = add;
		a[i].aver = (add - max - min) / 8.0; 				//求出平均成绩 
	}
}
void sort(struct people a[])     					//根据平均分排序 
{
	printf("排序后结果:");
	printf("\n");
	int i, j;
	struct people t;								//转换变量为结构体类型数据 
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2 - i; j++)
		{
			if (a[j].aver < a[j + 1].aver)
			{
				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
		}
	for (i = 0; i < l; i++)								//打印出排序后的结果 
		printf("%d\t%s\t%.2lf\t%d\n", a[i].num, a[i].name, a[i].aver, a[i].total);
}
void search(struct people a[]) 						//查询歌手信息 
{
	char b[20];
	int m;
	printf("请输入要查询歌手编号和姓名:");
	scanf("%d%s", &m, b);
	int i, j, flag = 1;
	for (i = 0; i < l; i++)
	{
		if (strcmp(a[i].name, b) == 0 && m == a[i].num)  				//输出歌手信息 
		{
			printf("该歌手成绩是:");
			for (j = 0; j < 10; j++)
			{
				printf("%4d", a[i].score[j]);
			}
			printf("\n");
			printf("该歌手总成绩是:%d\n", a[i].total);
			printf("该歌手平均成绩是:%.2lf\n", a[i].aver);
			flag = 0;
			break;
		}
	}
	if (flag)    									//考虑错误情况 
		printf("未找到该歌手\n");
}
void inist(struct people a[])  						//插入新增歌手信息 
{
	int i, max, min;
	l = l + 1;
	printf("请输入选手编号:");  					//输入新增歌手的基本信息 
	scanf("%d", &a[l - 1].num);
	printf("请输入选手姓名:");
	scanf("%s", a[l - 1].name);
	for (i = 0; i < 10; i++)								//为新增选手打分 
	{
		printf("请输入第%d位评委的打分:", i + 1);
		scanf("%d", &a[l - 1].score[i]);
	}
	max = min = a[l - 1].score[0];
	a[l - 1].total = 0;
	for (i = 0; i < 10; i++)								//加上新增选手后从新进行排序 
	{
		a[l - 1].total += a[l - 1].score[i];
		if (a[l - 1].score[i] >= max)
			max = a[l - 1].score[i];
		else if (a[l - 1].score[i] < min)
			min = a[l - 1].score[i];
	}
	a[l - 1].aver = (a[l - 1].total - min - max) / 8.0;			//平均分 
}
void wenjian(struct people a[]) 					//将歌手数据写入系统文件 
{
	FILE* fp;
	int i;
	if ((fp = fopen("D:\\歌手比赛数据.txt", "w")) == NULL)
	{
		printf("无法打开次文件");
		exit(0);
	}
	for (i = 0; i < l; i++)
	{
		fprintf(fp, "%d\t%s\t%.2lf\t%d\n", a[i].num, a[i].name, a[i].aver, a[i].total);
	}
	fclose(fp);
	printf("歌手数据已写入系统文件\n");
}
void show()     									//输出菜单 
{
	int k;
	char i[10];
	do {												//循环以便进行多种操作 

		printf("\t1.输入歌手信息\n");
		printf("\t2.输入评委打分\n");
		printf("\t3.按成绩排序\n");
		printf("\t4.按姓名查找\n");
		printf("\t5.插入选手数据\n");
		printf("\t6.写入数据文件\n");
		printf("\t7.退出系统\n");

		printf("****************************************");
		printf("\n");
		printf("请选择(1-7):");
		scanf("%d", &k);
		while (1)
		{
			if (k > 7 || k <= 0)									//其他情况 
			{
				printf("输入错误！！！请重新输入:");
				scanf("%d", &k);
			}
			else break;
		}
		switch (k)										//菜单的主要结构 
		{
		case 1:input(); break;
		case 2:dafen(); break;
		case 3:sort(a); break;
		case 4:search(a); break;
		case 5:inist(a); break;
		case 6:wenjian(a); break;

		}
		if (k != 7)
		{
			printf("如果继续，输入任意，如果退出，请输入0：");
			scanf("%s", i);
			if (i == 0)
				k = 7;
			printf("\n");
		}
	} while (k != 7);
}
int main()     										//主函数 
{
	printf("---------------------------------------\n");
	printf("\t欢迎使用歌手评分系统\n");
	printf("---------------------------------------\n");
	show();
}

