#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 10
int l;
struct people    				//������ֽṹ�� 
{
	int num;
	char name[20];
	int score[10];
	float aver;  				//ƽ���� 
	int total;   				//�ܷ� 
}a[n];
void input()   					//������ֵ���Ϣ 
{
	printf("�������������(ע���������С��10):");				//����������� 
	scanf("%d", &l);
	while (1)													//���ǲ�ͬ��������� 
	{
		if (l >= 10 || l <= 0)
		{
			printf("���������������,����������(ע���������С��10)��"
			);
			scanf("%d", &l);
		}
		else break;
	}
	int i;
	for (i = 0; i < l; i++)
	{
		printf("�������%d��ѡ�ֵ���Ϣ", i + 1);
		printf("\n");
		printf("��ţ�");
		scanf("%d", &a[i].num);
		printf("������");
		scanf("%s", a[i].name);
	}
}
void dafen()  										// ��ί��� 
{
	void average(struct people a[]);
	int i, j;
	for (i = 0; i < l; i++)								//˫��ѭ���������Ƹ����������ڲ���Ʒ��� 
	{
		printf("��%dλ���֣�", i + 1);
		printf("\n");
		for (j = 0; j < 10; j++)
		{
			printf("�������%dλ��ί�Ĵ�֣�", j + 1);
			scanf("%d", &a[i].score[j]);
			while (1)
			{
				if (a[i].score[j] > 100)
				{
					printf("������С��100�Ĵ��:");
					scanf("%d", &a[i].score[j]);
				}
				else break;
			}
		}
	}
	average(a);
}
void average(struct people a[])						//ȥ����߷ֺ���ͷ���ƽ����						
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
				max = a[i].score[j];     					//ɸѡ����߷� 
			else if (a[i].score[j] < min)
				min = a[i].score[j]; 						//ɸѡ����ͷ� 
		}
		a[i].total = add;
		a[i].aver = (add - max - min) / 8.0; 				//���ƽ���ɼ� 
	}
}
void sort(struct people a[])     					//����ƽ�������� 
{
	printf("�������:");
	printf("\n");
	int i, j;
	struct people t;								//ת������Ϊ�ṹ���������� 
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2 - i; j++)
		{
			if (a[j].aver < a[j + 1].aver)
			{
				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
		}
	for (i = 0; i < l; i++)								//��ӡ�������Ľ�� 
		printf("%d\t%s\t%.2lf\t%d\n", a[i].num, a[i].name, a[i].aver, a[i].total);
}
void search(struct people a[]) 						//��ѯ������Ϣ 
{
	char b[20];
	int m;
	printf("������Ҫ��ѯ���ֱ�ź�����:");
	scanf("%d%s", &m, b);
	int i, j, flag = 1;
	for (i = 0; i < l; i++)
	{
		if (strcmp(a[i].name, b) == 0 && m == a[i].num)  				//���������Ϣ 
		{
			printf("�ø��ֳɼ���:");
			for (j = 0; j < 10; j++)
			{
				printf("%4d", a[i].score[j]);
			}
			printf("\n");
			printf("�ø����ܳɼ���:%d\n", a[i].total);
			printf("�ø���ƽ���ɼ���:%.2lf\n", a[i].aver);
			flag = 0;
			break;
		}
	}
	if (flag)    									//���Ǵ������ 
		printf("δ�ҵ��ø���\n");
}
void inist(struct people a[])  						//��������������Ϣ 
{
	int i, max, min;
	l = l + 1;
	printf("������ѡ�ֱ��:");  					//�����������ֵĻ�����Ϣ 
	scanf("%d", &a[l - 1].num);
	printf("������ѡ������:");
	scanf("%s", a[l - 1].name);
	for (i = 0; i < 10; i++)								//Ϊ����ѡ�ִ�� 
	{
		printf("�������%dλ��ί�Ĵ��:", i + 1);
		scanf("%d", &a[l - 1].score[i]);
	}
	max = min = a[l - 1].score[0];
	a[l - 1].total = 0;
	for (i = 0; i < 10; i++)								//��������ѡ�ֺ���½������� 
	{
		a[l - 1].total += a[l - 1].score[i];
		if (a[l - 1].score[i] >= max)
			max = a[l - 1].score[i];
		else if (a[l - 1].score[i] < min)
			min = a[l - 1].score[i];
	}
	a[l - 1].aver = (a[l - 1].total - min - max) / 8.0;			//ƽ���� 
}
void wenjian(struct people a[]) 					//����������д��ϵͳ�ļ� 
{
	FILE* fp;
	int i;
	if ((fp = fopen("D:\\���ֱ�������.txt", "w")) == NULL)
	{
		printf("�޷��򿪴��ļ�");
		exit(0);
	}
	for (i = 0; i < l; i++)
	{
		fprintf(fp, "%d\t%s\t%.2lf\t%d\n", a[i].num, a[i].name, a[i].aver, a[i].total);
	}
	fclose(fp);
	printf("����������д��ϵͳ�ļ�\n");
}
void show()     									//����˵� 
{
	int k;
	char i[10];
	do {												//ѭ���Ա���ж��ֲ��� 

		printf("\t1.���������Ϣ\n");
		printf("\t2.������ί���\n");
		printf("\t3.���ɼ�����\n");
		printf("\t4.����������\n");
		printf("\t5.����ѡ������\n");
		printf("\t6.д�������ļ�\n");
		printf("\t7.�˳�ϵͳ\n");

		printf("****************************************");
		printf("\n");
		printf("��ѡ��(1-7):");
		scanf("%d", &k);
		while (1)
		{
			if (k > 7 || k <= 0)									//������� 
			{
				printf("������󣡣�������������:");
				scanf("%d", &k);
			}
			else break;
		}
		switch (k)										//�˵�����Ҫ�ṹ 
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
			printf("����������������⣬����˳���������0��");
			scanf("%s", i);
			if (i == 0)
				k = 7;
			printf("\n");
		}
	} while (k != 7);
}
int main()     										//������ 
{
	printf("---------------------------------------\n");
	printf("\t��ӭʹ�ø�������ϵͳ\n");
	printf("---------------------------------------\n");
	show();
}

