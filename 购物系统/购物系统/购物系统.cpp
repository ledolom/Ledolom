#include<iostream>
#include<string>
#include<windows.h>
#include<vector>
#include<conio.h>
#include<fstream>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;
class Commodity//��Ʒ��
{
public:

	string num;//��Ʒ���
	string name;//��Ʒ����
	string origin;//���� 
	int howMany;//����
	int onePrize;//����
};
class DailyCommodity :public Commodity//����Ʒ��
{
public:
};
class FoodCommodity :public Commodity//ʳƷ��
{
public:
	int date;//�����ڣ���λ��
};
class EleCommodity :public Commodity//������
{
public:
	string color;//��ɫ
};
class User//�û�
{
public:
	string num;//���
	string password;//���
	string name;//����
	string tel;//�绰
	int WX;//΢�����
	int ZFB;//֧�������
};
class Order//����
{
public:
	string commodityNum;//��Ʒ���
	string commodityName;//��Ʒ��
	int buyMany;//��������
	int payMonet;//֧�����
	string userNum;//�û����
	string payWay;//֧����ʽ
};
//����
vector<User> u;
User user, nu;
vector<DailyCommodity> da;
DailyCommodity nd;
vector<FoodCommodity> fo;
FoodCommodity nf;
vector<EleCommodity> el;
EleCommodity ne;
vector<Order> o;
//�������� 
void init();//�����ļ�
void outit();//�����ļ�

void start();//��ʼ
void login();//��¼����
void sign();//ע�����

void adminBegin();//����Ա��ʼ����
void commodityAdd();//�����Ʒ
void commodityShow();//��ʾ��Ʒ
void commodityChange();//�޸���Ʒ�����ͼ۸�

void userBegin();//�û���ʼ����
void informationChange();//������Ϣ�޸�

void orderBegin();//������ʼ����
void orderShow();//��ʾ����
void orderDel();//ɾ������
void orderFind();//��ѯ����

void buyThing();//������Ʒ
void init()//�����ļ�
{
	User uu;
	ifstream in1("user.txt", ios::in);
	while (!in1.eof())
	{
		in1 >> uu.num >> uu.name >> uu.password >> uu.tel >> uu.WX >> uu.ZFB;
		u.push_back(uu);
	}
	in1.close();

	Order oo;
	ifstream in2("order.txt", ios::in);
	while (!in2.eof())
	{
		in2 >> oo.commodityNum >> oo.commodityName >> oo.userNum >> oo.buyMany >> oo.payWay >> oo.payMonet;
		o.push_back(oo);
	}
	in2.close();

	DailyCommodity dd;
	ifstream in3("dailyCommodity.txt", ios::in);
	while (!in3.eof())
	{
		in3 >> dd.num >> dd.name >> dd.origin >> dd.howMany >> dd.onePrize;
		da.push_back(dd);
	}
	in3.close();

	FoodCommodity ff;
	ifstream in4("foodCommodity.txt", ios::in);
	while (!in4.eof())
	{
		in4 >> ff.num >> ff.name >> ff.origin >> ff.howMany >> ff.onePrize >> ff.date;
		fo.push_back(ff);
	}
	in4.close();

	EleCommodity ee;
	ifstream in5("eleCommodity.txt", ios::in);
	while (!in5.eof())
	{
		in5 >> ee.num >> ee.name >> ee.origin >> ee.howMany >> ee.onePrize >> ee.color;
		el.push_back(ee);
	}
	in5.close();
}
void outit()//�����ļ�
{
	int i;
	ofstream out1("user.txt", ios::out);
	for (i = 0; i < u.size(); i++)
	{
		if (user.num == u[i].num)
		{
			out1 << user.num << " " << user.name << " " << user.password << " " << user.tel << " " << user.WX << " " << user.ZFB;
		}
		else
		{
			out1 << u[i].num << " " << u[i].name << " " << u[i].password << " " << u[i].tel << " " << u[i].WX << " " << u[i].ZFB;
		}
		if (i != u.size() - 1)
		{
			out1 << endl;
		}
	}
	out1.close();

	ofstream out2("order.txt", ios::out);
	for (i = 0; i < o.size(); i++)
	{
		out2 << o[i].commodityNum << " " << o[i].commodityName << " " << o[i].userNum << " " << o[i].buyMany << " " << o[i].payWay << " " << o[i].payMonet;
		if (i != o.size() - 1)
		{
			out2 << endl;
		}
	}
	out2.close();

	ofstream out3("dailyCommodity.txt", ios::out);
	for (i = 0; i < da.size(); i++)
	{
		out3 << da[i].num << " " << da[i].name << " " << da[i].origin << " " << da[i].howMany << " " << da[i].onePrize;
		if (i != da.size() - 1)
		{
			out3 << endl;
		}
	}
	out3.close();

	ofstream out4("foodCommodity.txt", ios::out);
	for (i = 0; i < fo.size(); i++)
	{
		out4 << fo[i].num << " " << fo[i].name << " " << fo[i].origin << " " << fo[i].howMany << " " << fo[i].onePrize << " " << fo[i].date;
		if (i != fo.size() - 1)
		{
			out4 << endl;
		}
	}
	out4.close();

	ofstream out5("eleCommodity.txt", ios::out);
	for (i = 0; i < el.size(); i++)
	{
		out5 << el[i].num << " " << el[i].name << " " << el[i].origin << " " << el[i].howMany << " " << el[i].onePrize << " " << el[i].color;
		if (i != el.size() - 1)
		{
			out5 << endl;
		}
	}
	out5.close();
}
void start()//��ʼ
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ����ϵͳ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       1��¼                         " << endl;
	cout << "                                                     " << endl;
	cout << "                       2ע��                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:login(); break;
	case 2:sign(); break;
	default:start(); break;
	}
}
void login()//��¼����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ��¼����                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "���������ı�ţ�"; cin >> user.num;
	cout << "�������������룺"; cin >> user.password;
	if (user.num == "01" && user.password == "123456")
	{
		adminBegin();
	}
	else
	{
		for (i = 0; i < u.size(); i++)
		{
			if (u[i].num == user.num && u[i].password == user.password)
			{
				break;
			}
		}
		if (i < u.size())
		{
			user = u[i];
			userBegin();
		}
		else
		{
			cout << "�˺��������" << endl;
			cout << "�������������" << endl;
			getch();
			start();
		}
	}
}
void sign()//ע��
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ע�����                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "���������ı�ţ�"; cin >> nu.num;
	if (nu.num == "000")
	{
		cout << "��Ų����ã�" << endl;
		cout << "�������������" << endl;
		getch();
		start();
	}
	for (i = 0; i < u.size(); i++)
	{
		if (u[i].num == nu.num)
		{
			cout << "����Ѿ����ڣ�" << endl;
			cout << "�������������" << endl;
			getch();
			start();
		}
	}
	cout << "����������������"; cin >> nu.name;
	cout << "�������������룺"; cin >> nu.password;
	cout << "���������ĵ绰��"; cin >> nu.tel;
	nu.WX = nu.ZFB = 0;
	u.push_back(nu);
	cout << "ע��ɹ���" << endl;
	cout << "�������������" << endl;
	getch();
	start();
}

void adminBegin()//����Ա��ʼ����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ����ϵͳ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1�����Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2��ʾ��Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3�޸���Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0�˳�                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:commodityAdd(); break;
	case 2:commodityShow(); break;
	case 3:commodityChange(); break;
	case 0:cout << "��л����ʹ��" << endl; outit(); break;
	default:adminBegin(); break;
	}
}
void commodityAdd()//�����Ʒ
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      �����Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1����Ʒ                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2ʳƷ��                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3�ҵ���                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0����                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n, i;
	cin >> n;
	if (n == 1)//����Ʒ
	{
		DailyCommodity d;
		cout << "�����������Ʒ��ţ�"; cin >> d.num;
		for (i = 0; i < da.size(); i++)
		{
			if (da[i].num == d.num)
			{
				break;
			}
		}
		if (i < da.size())
		{
			cout << "������иñ���Ѵ��ڣ�" << endl;
			cout << "�������������" << endl;
			getch();
			commodityAdd();
		}
		cout << "�����������Ʒ���ƣ�"; cin >> d.name;
		cout << "�����������Ʒ���أ�"; cin >> d.origin;
		cout << "�����������Ʒ���ۣ�"; cin >> d.onePrize;
		cout << "�����������Ʒ��棺"; cin >> d.howMany;
		da.push_back(d);
		cout << "��ӳɹ���" << endl;
		cout << "�������������" << endl;
		getch();
		adminBegin();
	}
	else if (n == 2)//ʳƷ��
	{
		FoodCommodity f;
		cout << "�������ʳƷ��ţ�"; cin >> f.num;
		for (i = 0; i < fo.size(); i++)
		{
			if (fo[i].num == f.num)
			{
				break;
			}
		}
		if (i < fo.size())
		{
			cout << "������иñ���Ѵ��ڣ�" << endl;
			cout << "�������������" << endl;
			getch();
			commodityAdd();
		}
		cout << "�������ʳƷ���ƣ�"; cin >> f.name;
		cout << "�������ʳƷ���أ�"; cin >> f.origin;
		cout << "�������ʳƷ���ۣ�"; cin >> f.onePrize;
		cout << "�������ʳƷ��棺"; cin >> f.howMany;
		cout << "�������ʳƷ�����ڣ��£���"; cin >> f.date;
		fo.push_back(f);
		cout << "��ӳɹ���" << endl;
		cout << "�������������" << endl; getch();
		adminBegin();
	}
	else if (n == 3)//�ҵ��� 
	{
		EleCommodity e;
		cout << "������üҵ��ţ�"; cin >> e.num;
		for (i = 0; i < el.size(); i++)
		{
			if (el[i].num == e.num)
			{
				break;
			}
		}
		if (i < el.size())
		{
			cout << "������иñ���Ѵ��ڣ�" << endl;
			cout << "�������������" << endl; getch();
			commodityAdd();
		}
		cout << "������üҵ����ƣ�"; cin >> e.name;
		cout << "������üҵ���أ�"; cin >> e.origin;
		cout << "������üҵ絥�ۣ�"; cin >> e.onePrize;
		cout << "������üҵ��棺"; cin >> e.howMany;
		cout << "������üҵ���ɫ��"; cin >> e.color;
		el.push_back(e);
		cout << "��ӳɹ���" << endl;
		cout << "�������������" << endl;
		getch();
		adminBegin();
	}
	else if (n == 0)
	{
		adminBegin();
	}
	else
	{
		commodityAdd();
	}
}
void commodityShow()//��ʾ��Ʒ
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      �鿴��Ʒ                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	if (da.size() > 0)
	{
		cout << endl << "����Ʒ" << endl;
		cout << "���\t����\t����\t����\t���" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
	}
	if (fo.size() > 0)
	{
		cout << endl << "ʳƷ" << endl;
		cout << "���\t����\t����\t����\t���\t������" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
	}
	if (el.size() > 0)
	{
		cout << endl << "�ҵ�" << endl;
		cout << "���\t����\t����\t����\t���\t��ɫ" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
	}
	cout << "�������������" << endl;
	getch();
	adminBegin();
}
void commodityChange()//�޸���Ʒ�����ͼ۸�
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      �޸���Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1����Ʒ                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2ʳƷ��                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3�ҵ���                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0����                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n, i, m, j;
	cin >> n;
	if (n == 1)
	{
		cout << endl << "����Ʒ" << endl;
		cout << "���\t���\t����\t����\t����\t���" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << i << "\t" << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
		cout << "��ѡ��Ҫ�޸ĵ���ţ�";
		cin >> m;
		if (m >= da.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			adminBegin();
		}
		else
		{
			DailyCommodity dd;
			cout << "��������Ʒ��ţ�"; cin >> dd.num;
			for (j = 0; j < da.size(); j++)
			{
				if (da[j].num == dd.num)
				{
					break;
				}
			}
			if (j < da.size() && m != j)
			{
				cout << "����Ѵ��ڣ�" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
			else//�����޸�
			{
				cout << "��������Ʒ���ƣ�"; cin >> dd.name;
				cout << "��������Ʒ���أ�"; cin >> dd.origin;
				cout << "��������Ʒ���ۣ�"; cin >> dd.onePrize;
				cout << "��������Ʒ��棺"; cin >> dd.howMany;
				da[m] = dd;
				cout << "�޸ĳɹ���" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
		}
	}
	else if (n == 2)
	{
		cout << endl << "ʳƷ" << endl;
		cout << "���\t���\t����\t����\t����\t���\t������" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << i << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
		cout << "��ѡ��Ҫ�޸ĵ���ţ�";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			adminBegin();
		}
		else
		{
			FoodCommodity ff;
			cout << "��������Ʒ��ţ�"; cin >> ff.num;
			for (j = 0; j < fo.size(); j++)
			{
				if (fo[j].num == ff.num)
				{
					break;
				}
			}
			if (j < fo.size() && m != j)
			{
				cout << "����Ѵ��ڣ�" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
			else//�����޸�
			{
				cout << "��������Ʒ���ƣ�"; cin >> ff.name;
				cout << "��������Ʒ���ۣ�"; cin >> ff.onePrize;
				cout << "��������Ʒ���أ�"; cin >> ff.origin;
				cout << "��������Ʒ��棺"; cin >> ff.howMany;
				cout << "��������Ʒ�����ڣ�"; cin >> ff.date;
				fo[m] = ff;
				cout << "�޸ĳɹ���" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
		}
	}
	else if (n == 3)
	{
		cout << endl << "�ҵ�" << endl;
		cout << "���\t���\t����\t����\t����\t���\t��ɫ" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << i << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
		cout << "��ѡ��Ҫ�޸ĵ���ţ�";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			adminBegin();
		}
		else
		{
			EleCommodity ee;
			cout << "��������Ʒ��ţ�"; cin >> ee.num;
			for (j = 0; j < el.size(); j++)
			{
				if (el[j].num == ee.num)
				{
					break;
				}
			}
			if (j < el.size() && m != j)
			{
				cout << "����Ѵ��ڣ�" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
			else//�����޸�
			{
				cout << "��������Ʒ���ƣ�"; cin >> ee.name;
				cout << "��������Ʒ���ۣ�"; cin >> ee.onePrize;
				cout << "��������Ʒ���أ�"; cin >> ee.origin;
				cout << "��������Ʒ��棺"; cin >> ee.howMany;
				cout << "��������Ʒ��ɫ��"; cin >> ee.color;
				el[m] = ee;
				cout << "�޸ĳɹ���" << endl;
				cout << "�������������" << endl;
				getch();
				adminBegin();
			}
		}
	}
	else if (n == 0)
	{
		adminBegin();
	}
	else
	{
		commodityChange();
	}
}

void userBegin()//�û���ʼ����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ����ϵͳ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1������Ϣ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2��������                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3������Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0�˳�                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:informationChange(); break;
	case 2:orderBegin(); break;
	case 3:buyThing(); break;
	case 0:cout << "��л����ʹ��" << endl; outit(); break;
	default:userBegin(); break;
	}
}
void informationChange()//������Ϣ�޸�
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ������Ϣ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       1�޸�                         " << endl;
	cout << "                                                     " << endl;
	cout << "                       0����                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ţ�" << user.num << "������" << user.name << "���룺" << user.password << "�绰��" << user.tel << "΢����" << user.WX << "֧������" << user.ZFB << endl;
	int n, i, j;
	cout << "��ѡ��"; cin >> n;
	if (n == 1)
	{
		for (i = 0; i < u.size(); i++)
		{
			if (u[i].num == user.num)
			{
				break;
			}
		}
		User zz;
		cout << "�������ţ�"; cin >> zz.num;
		if (zz.num == "000")
		{
			cout << "��Ų����ã�" << endl;
			cout << "�������������" << endl;
			getch();
			userBegin();
		}
		else
		{
			for (j = 0; j < u.size(); j++)
			{
				if (u[j].num == zz.num)
				{
					break;
				}
			}
			if (i == j)//�����޸�
			{
				cout << "������������"; cin >> zz.name;
				cout << "���������룺"; cin >> zz.password;
				cout << "������绰��"; cin >> zz.tel;
				cout << "������΢����"; cin >> zz.WX;
				cout << "������֧������"; cin >> zz.ZFB;
				user = zz;
				cout << "�޸ĳɹ���" << endl;
				cout << "�������������" << endl;
				getch();
				userBegin();
			}
			else
			{
				cout << "����Ѵ��ڣ�" << endl;
				cout << "�������������" << endl;
				getch();
				userBegin();
			}
		}
	}
	else if (n == 0)
	{
		userBegin();
	}
	else
	{
		informationChange();
	}
}
void orderBegin()//������ʼ����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ��������                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1�鿴����                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2ɾ������                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3��ѯ����                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0����                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:orderShow(); break;
	case 2:orderDel(); break;
	case 3:orderFind(); break;
	case 0:userBegin(); break;
	default:orderBegin(); break;
	}
}
void orderShow()//��ʾ����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ��ʾ����                       " << endl;
	cout << "                                                     " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "�û���ţ�\t��Ʒ��ţ�\t��Ʒ����\t����������\t֧����\t֧����ʽ��" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num)
		{
			cout << o[i].userNum << "\t\t" << o[i].commodityNum << "\t\t" << o[i].commodityName << "\t\t" << o[i].buyMany << "\t\t" << o[i].payMonet << "\t\t" << o[i].payWay << endl;
		}
	}
	cout << "�������������" << endl;
	getch();
	orderBegin();
}
void orderDel()//ɾ������
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ɾ������                       " << endl;
	cout << "*****************************************************" << endl;
	int i, n;
	cout << "���\t�û���ţ�\t��Ʒ��ţ�\t��Ʒ����\t����������\t֧����\t֧����ʽ��" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num)
		{
			cout << i << "\t\t" << o[i].userNum << "\t\t" << o[i].commodityNum << "\t\t" << o[i].commodityName << "\t\t" << o[i].buyMany << "\t\t" << o[i].payMonet << "\t\t" << o[i].payWay << endl;
		}
	}
	cout << "������Ҫɾ���Ķ�����ţ�";
	cin >> n;
	if (o[n].userNum == user.num)
	{
		o.erase(o.begin() + n);
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	cout << "�������������" << endl;
	getch();
	orderBegin();
}
void orderFind()//��ѯ����
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ��ѯ����                       " << endl;
	cout << "*****************************************************" << endl;
	string num;
	int i;
	cout << "������Ҫ��ѯ����Ʒ��ţ�";
	cin >> num;
	cout << "�û���ţ�\t��Ʒ��ţ�\t��Ʒ����\t����������\t֧����\t֧����ʽ��" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num && o[i].commodityNum == num)
		{
			cout << o[i].userNum << "\t" << o[i].commodityNum << "\t" << o[i].commodityName << "\t" << o[i].buyMany << "\t" << o[i].payMonet << "\t" << o[i].payWay << endl;
		}
	}
	cout << "�������������" << endl;
	getch();
	orderBegin();
}
void buyThing()//������Ʒ
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      ������Ʒ                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1����Ʒ                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2ʳƷ��                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3�ҵ���                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0����                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "��ѡ��";
	int n, i, m;
	cin >> n;
	if (n == 1)
	{
		cout << endl << "����Ʒ" << endl;
		cout << "���\t���\t����\t����\t����\t���" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << i << "\t" << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
		cout << "��ѡ��Ҫ�������ţ�";
		cin >> m;
		if (m >= da.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "������Ҫ�����������";
			int sum;
			cin >> sum;
			if (sum > da[m].howMany)
			{
				cout << "��治�㣡" << endl;
				cout << "�������������" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "��ѡ��֧����ʽ��1΢��/2֧��������"; cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * da[m].onePrize)
					{
						user.WX = user.WX - sum * (da[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "΢��";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * da[m].onePrize;
						newOeder.commodityNum = da[m].num;
						newOeder.commodityName = da[m].name;
						da[m].howMany = da[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "΢�����㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * da[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (da[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "֧����";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * da[m].onePrize;
						newOeder.commodityNum = da[m].num;
						newOeder.commodityName = da[m].name;
						da[m].howMany = da[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "֧�������㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else
				{
					buyThing();
				}
			}
		}
	}
	else if (n == 2)
	{
		cout << endl << "ʳƷ" << endl;
		cout << "���\t����\t����\t����\t���\t������" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
		cout << "��ѡ��Ҫ�������ţ�";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "������Ҫ�����������";
			int sum;
			cin >> sum;
			if (sum > fo[m].howMany)
			{
				cout << "��治�㣡" << endl;
				cout << "�������������" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "��ѡ��֧����ʽ��1΢��/2֧��������";
				cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * fo[m].onePrize)
					{
						user.WX = user.WX - sum * (fo[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "΢��";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * fo[m].onePrize;
						newOeder.commodityNum = fo[m].num;
						newOeder.commodityName = fo[m].name;
						fo[m].howMany = fo[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "΢�����㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * fo[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (fo[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "֧����";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * fo[m].onePrize;
						newOeder.commodityNum = fo[m].num;
						newOeder.commodityName = fo[m].name;
						fo[m].howMany = fo[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "֧�������㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else
				{
					buyThing();
				}
			}
		}
	}
	else if (n == 3)
	{
		cout << endl << "�ҵ�" << endl;
		cout << "���\t����\t����\t����\t���\t��ɫ" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
		cout << "��ѡ��Ҫ�������ţ�";
		cin >> m;
		if (m >= el.size())
		{
			cout << "�������" << endl;
			cout << "�������������" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "������Ҫ�����������";
			int sum;
			cin >> sum;
			if (sum > el[m].howMany)
			{
				cout << "��治�㣡" << endl;
				cout << "�������������" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "��ѡ��֧����ʽ��1΢��/2֧��������"; cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * el[m].onePrize)
					{
						user.WX = user.WX - sum * (el[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "΢��";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * el[m].onePrize;
						newOeder.commodityNum = el[m].num;
						newOeder.commodityName = el[m].name;
						el[m].howMany = el[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "΢�����㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * el[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (el[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "֧����";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * el[m].onePrize;
						newOeder.commodityNum = el[m].num;
						newOeder.commodityName = el[m].name;
						el[m].howMany = el[m].howMany - sum;
						o.push_back(newOeder);
						cout << "����ɹ���" << endl;
					}
					else
					{
						cout << "֧�������㣬���ֵ��" << endl;
					}
					cout << "�������������" << endl;
					getch();
					userBegin();
				}
				else
				{
					buyThing();
				}
			}
		}
	}
	else if (n == 0)
	{
		userBegin();
	}
	else
	{
		buyThing();
	}
}
int main()
{
	init();
	start();
	return 0;
}
