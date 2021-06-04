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
class Commodity//商品类
{
public:

	string num;//商品编号
	string name;//商品名称
	string origin;//产地 
	int howMany;//数量
	int onePrize;//单价
};
class DailyCommodity :public Commodity//日用品类
{
public:
};
class FoodCommodity :public Commodity//食品类
{
public:
	int date;//保质期，单位月
};
class EleCommodity :public Commodity//电器类
{
public:
	string color;//颜色
};
class User//用户
{
public:
	string num;//编号
	string password;//编号
	string name;//姓名
	string tel;//电话
	int WX;//微信余额
	int ZFB;//支付宝余额
};
class Order//订单
{
public:
	string commodityNum;//商品编号
	string commodityName;//商品名
	int buyMany;//购买数量
	int payMonet;//支付金额
	string userNum;//用户编号
	string payWay;//支付方式
};
//容器
vector<User> u;
User user, nu;
vector<DailyCommodity> da;
DailyCommodity nd;
vector<FoodCommodity> fo;
FoodCommodity nf;
vector<EleCommodity> el;
EleCommodity ne;
vector<Order> o;
//函数声明 
void init();//读入文件
void outit();//读出文件

void start();//开始
void login();//登录界面
void sign();//注册界面

void adminBegin();//管理员开始界面
void commodityAdd();//添加商品
void commodityShow();//显示商品
void commodityChange();//修改商品数量和价格

void userBegin();//用户开始界面
void informationChange();//个人信息修改

void orderBegin();//订单开始界面
void orderShow();//显示订单
void orderDel();//删除订单
void orderFind();//查询订单

void buyThing();//购买商品
void init()//读入文件
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
void outit()//读出文件
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
void start()//开始
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      购物系统                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       1登录                         " << endl;
	cout << "                                                     " << endl;
	cout << "                       2注册                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:login(); break;
	case 2:sign(); break;
	default:start(); break;
	}
}
void login()//登录界面
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      登录界面                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "请输入您的编号："; cin >> user.num;
	cout << "请输入您的密码："; cin >> user.password;
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
			cout << "账号密码错误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			start();
		}
	}
}
void sign()//注册
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      注册界面                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "请输入您的编号："; cin >> nu.num;
	if (nu.num == "000")
	{
		cout << "编号不可用！" << endl;
		cout << "按任意键继续！" << endl;
		getch();
		start();
	}
	for (i = 0; i < u.size(); i++)
	{
		if (u[i].num == nu.num)
		{
			cout << "编号已经存在！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			start();
		}
	}
	cout << "请输入您的姓名："; cin >> nu.name;
	cout << "请输入您的密码："; cin >> nu.password;
	cout << "请输入您的电话："; cin >> nu.tel;
	nu.WX = nu.ZFB = 0;
	u.push_back(nu);
	cout << "注册成功！" << endl;
	cout << "按任意键继续！" << endl;
	getch();
	start();
}

void adminBegin()//管理员开始界面
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      购物系统                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1添加商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2显示商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3修改商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0退出                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:commodityAdd(); break;
	case 2:commodityShow(); break;
	case 3:commodityChange(); break;
	case 0:cout << "感谢您的使用" << endl; outit(); break;
	default:adminBegin(); break;
	}
}
void commodityAdd()//添加商品
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      添加商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1日用品                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2食品类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3家电类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0返回                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n, i;
	cin >> n;
	if (n == 1)//日用品
	{
		DailyCommodity d;
		cout << "请输入该日用品编号："; cin >> d.num;
		for (i = 0; i < da.size(); i++)
		{
			if (da[i].num == d.num)
			{
				break;
			}
		}
		if (i < da.size())
		{
			cout << "该类别中该编号已存在！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			commodityAdd();
		}
		cout << "请输入该日用品名称："; cin >> d.name;
		cout << "请输入该日用品产地："; cin >> d.origin;
		cout << "请输入该日用品单价："; cin >> d.onePrize;
		cout << "请输入该日用品库存："; cin >> d.howMany;
		da.push_back(d);
		cout << "添加成功！" << endl;
		cout << "按任意键继续！" << endl;
		getch();
		adminBegin();
	}
	else if (n == 2)//食品类
	{
		FoodCommodity f;
		cout << "请输入该食品编号："; cin >> f.num;
		for (i = 0; i < fo.size(); i++)
		{
			if (fo[i].num == f.num)
			{
				break;
			}
		}
		if (i < fo.size())
		{
			cout << "该类别中该编号已存在！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			commodityAdd();
		}
		cout << "请输入该食品名称："; cin >> f.name;
		cout << "请输入该食品产地："; cin >> f.origin;
		cout << "请输入该食品单价："; cin >> f.onePrize;
		cout << "请输入该食品库存："; cin >> f.howMany;
		cout << "请输入该食品保质期（月）："; cin >> f.date;
		fo.push_back(f);
		cout << "添加成功！" << endl;
		cout << "按任意键继续！" << endl; getch();
		adminBegin();
	}
	else if (n == 3)//家电类 
	{
		EleCommodity e;
		cout << "请输入该家电编号："; cin >> e.num;
		for (i = 0; i < el.size(); i++)
		{
			if (el[i].num == e.num)
			{
				break;
			}
		}
		if (i < el.size())
		{
			cout << "该类别中该编号已存在！" << endl;
			cout << "按任意键继续！" << endl; getch();
			commodityAdd();
		}
		cout << "请输入该家电名称："; cin >> e.name;
		cout << "请输入该家电产地："; cin >> e.origin;
		cout << "请输入该家电单价："; cin >> e.onePrize;
		cout << "请输入该家电库存："; cin >> e.howMany;
		cout << "请输入该家电颜色："; cin >> e.color;
		el.push_back(e);
		cout << "添加成功！" << endl;
		cout << "按任意键继续！" << endl;
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
void commodityShow()//显示商品
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      查看商品                       " << endl;
	cout << "*****************************************************" << endl;
	int i;
	if (da.size() > 0)
	{
		cout << endl << "日用品" << endl;
		cout << "编号\t名称\t产地\t单价\t库存" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
	}
	if (fo.size() > 0)
	{
		cout << endl << "食品" << endl;
		cout << "编号\t名称\t产地\t单价\t库存\t保质期" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
	}
	if (el.size() > 0)
	{
		cout << endl << "家电" << endl;
		cout << "编号\t名称\t产地\t单价\t库存\t颜色" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
	}
	cout << "按任意键继续！" << endl;
	getch();
	adminBegin();
}
void commodityChange()//修改商品数量和价格
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      修改商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1日用品                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2食品类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3家电类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0返回                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n, i, m, j;
	cin >> n;
	if (n == 1)
	{
		cout << endl << "日用品" << endl;
		cout << "序号\t编号\t名称\t产地\t单价\t库存" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << i << "\t" << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
		cout << "请选择要修改的序号：";
		cin >> m;
		if (m >= da.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			adminBegin();
		}
		else
		{
			DailyCommodity dd;
			cout << "请输入商品编号："; cin >> dd.num;
			for (j = 0; j < da.size(); j++)
			{
				if (da[j].num == dd.num)
				{
					break;
				}
			}
			if (j < da.size() && m != j)
			{
				cout << "编号已存在！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				adminBegin();
			}
			else//可以修改
			{
				cout << "请输入商品名称："; cin >> dd.name;
				cout << "请输入商品产地："; cin >> dd.origin;
				cout << "请输入商品单价："; cin >> dd.onePrize;
				cout << "请输入商品库存："; cin >> dd.howMany;
				da[m] = dd;
				cout << "修改成功！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				adminBegin();
			}
		}
	}
	else if (n == 2)
	{
		cout << endl << "食品" << endl;
		cout << "序号\t编号\t名称\t产地\t单价\t库存\t保质期" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << i << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
		cout << "请选择要修改的序号：";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			adminBegin();
		}
		else
		{
			FoodCommodity ff;
			cout << "请输入商品编号："; cin >> ff.num;
			for (j = 0; j < fo.size(); j++)
			{
				if (fo[j].num == ff.num)
				{
					break;
				}
			}
			if (j < fo.size() && m != j)
			{
				cout << "编号已存在！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				adminBegin();
			}
			else//可以修改
			{
				cout << "请输入商品名称："; cin >> ff.name;
				cout << "请输入商品单价："; cin >> ff.onePrize;
				cout << "请输入商品产地："; cin >> ff.origin;
				cout << "请输入商品库存："; cin >> ff.howMany;
				cout << "请输入商品保质期："; cin >> ff.date;
				fo[m] = ff;
				cout << "修改成功！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				adminBegin();
			}
		}
	}
	else if (n == 3)
	{
		cout << endl << "家电" << endl;
		cout << "序号\t编号\t名称\t产地\t单价\t库存\t颜色" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << i << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
		cout << "请选择要修改的序号：";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			adminBegin();
		}
		else
		{
			EleCommodity ee;
			cout << "请输入商品编号："; cin >> ee.num;
			for (j = 0; j < el.size(); j++)
			{
				if (el[j].num == ee.num)
				{
					break;
				}
			}
			if (j < el.size() && m != j)
			{
				cout << "编号已存在！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				adminBegin();
			}
			else//可以修改
			{
				cout << "请输入商品名称："; cin >> ee.name;
				cout << "请输入商品单价："; cin >> ee.onePrize;
				cout << "请输入商品产地："; cin >> ee.origin;
				cout << "请输入商品库存："; cin >> ee.howMany;
				cout << "请输入商品颜色："; cin >> ee.color;
				el[m] = ee;
				cout << "修改成功！" << endl;
				cout << "按任意键继续！" << endl;
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

void userBegin()//用户开始界面
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      购物系统                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1个人信息                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2订单管理                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3购买商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0退出                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:informationChange(); break;
	case 2:orderBegin(); break;
	case 3:buyThing(); break;
	case 0:cout << "感谢您的使用" << endl; outit(); break;
	default:userBegin(); break;
	}
}
void informationChange()//个人信息修改
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      个人信息                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       1修改                         " << endl;
	cout << "                                                     " << endl;
	cout << "                       0返回                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "编号：" << user.num << "姓名：" << user.name << "密码：" << user.password << "电话：" << user.tel << "微信余额：" << user.WX << "支付宝余额：" << user.ZFB << endl;
	int n, i, j;
	cout << "请选择："; cin >> n;
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
		cout << "请输入编号："; cin >> zz.num;
		if (zz.num == "000")
		{
			cout << "编号不可用！" << endl;
			cout << "按任意键继续！" << endl;
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
			if (i == j)//可以修改
			{
				cout << "请输入姓名："; cin >> zz.name;
				cout << "请输入密码："; cin >> zz.password;
				cout << "请输入电话："; cin >> zz.tel;
				cout << "请输入微信余额："; cin >> zz.WX;
				cout << "请输入支付宝余额："; cin >> zz.ZFB;
				user = zz;
				cout << "修改成功！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				userBegin();
			}
			else
			{
				cout << "编号已存在！" << endl;
				cout << "按任意键继续！" << endl;
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
void orderBegin()//订单开始界面
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      订单界面                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     1查看订单                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     2删除订单                       " << endl;
	cout << "                                                     " << endl;
	cout << "                     3查询订单                       " << endl;
	cout << "                                                     " << endl;
	cout << "                       0返回                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
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
void orderShow()//显示订单
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      显示订单                       " << endl;
	cout << "                                                     " << endl;
	cout << "*****************************************************" << endl;
	int i;
	cout << "用户编号：\t商品编号：\t商品名：\t购买数量：\t支付金额：\t支付方式：" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num)
		{
			cout << o[i].userNum << "\t\t" << o[i].commodityNum << "\t\t" << o[i].commodityName << "\t\t" << o[i].buyMany << "\t\t" << o[i].payMonet << "\t\t" << o[i].payWay << endl;
		}
	}
	cout << "按任意键继续！" << endl;
	getch();
	orderBegin();
}
void orderDel()//删除订单
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      删除订单                       " << endl;
	cout << "*****************************************************" << endl;
	int i, n;
	cout << "序号\t用户编号：\t商品编号：\t商品名：\t购买数量：\t支付金额：\t支付方式：" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num)
		{
			cout << i << "\t\t" << o[i].userNum << "\t\t" << o[i].commodityNum << "\t\t" << o[i].commodityName << "\t\t" << o[i].buyMany << "\t\t" << o[i].payMonet << "\t\t" << o[i].payWay << endl;
		}
	}
	cout << "请输入要删除的订单序号：";
	cin >> n;
	if (o[n].userNum == user.num)
	{
		o.erase(o.begin() + n);
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "序号有误！" << endl;
	}
	cout << "按任意键继续！" << endl;
	getch();
	orderBegin();
}
void orderFind()//查询订单
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      查询订单                       " << endl;
	cout << "*****************************************************" << endl;
	string num;
	int i;
	cout << "请输入要查询的商品编号：";
	cin >> num;
	cout << "用户编号：\t商品编号：\t商品名：\t购买数量：\t支付金额：\t支付方式：" << endl;
	for (i = 0; i < o.size(); i++)
	{
		if (o[i].userNum == user.num && o[i].commodityNum == num)
		{
			cout << o[i].userNum << "\t" << o[i].commodityNum << "\t" << o[i].commodityName << "\t" << o[i].buyMany << "\t" << o[i].payMonet << "\t" << o[i].payWay << endl;
		}
	}
	cout << "按任意键继续！" << endl;
	getch();
	orderBegin();
}
void buyThing()//购买商品
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "                      购买商品                       " << endl;
	cout << "                                                     " << endl;
	cout << "                      1日用品                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      2食品类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                      3家电类                        " << endl;
	cout << "                                                     " << endl;
	cout << "                       0返回                         " << endl;
	cout << "*****************************************************" << endl;
	cout << "请选择：";
	int n, i, m;
	cin >> n;
	if (n == 1)
	{
		cout << endl << "日用品" << endl;
		cout << "序号\t编号\t名称\t产地\t单价\t库存" << endl;
		for (i = 0; i < da.size(); i++)
		{
			cout << i << "\t" << da[i].num << "\t" << da[i].name << "\t" << da[i].origin << "\t" << da[i].onePrize << "\t" << da[i].howMany << endl;
		}
		cout << "请选择要购买的序号：";
		cin >> m;
		if (m >= da.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "请输入要购买的数量：";
			int sum;
			cin >> sum;
			if (sum > da[m].howMany)
			{
				cout << "库存不足！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "请选择支付方式（1微信/2支付宝）："; cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * da[m].onePrize)
					{
						user.WX = user.WX - sum * (da[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "微信";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * da[m].onePrize;
						newOeder.commodityNum = da[m].num;
						newOeder.commodityName = da[m].name;
						da[m].howMany = da[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "微信余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * da[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (da[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "支付宝";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * da[m].onePrize;
						newOeder.commodityNum = da[m].num;
						newOeder.commodityName = da[m].name;
						da[m].howMany = da[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "支付宝余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
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
		cout << endl << "食品" << endl;
		cout << "编号\t名称\t产地\t单价\t库存\t保质期" << endl;
		for (i = 0; i < fo.size(); i++)
		{
			cout << fo[i].num << "\t" << fo[i].name << "\t" << fo[i].origin << "\t" << fo[i].onePrize << "\t" << fo[i].howMany << "\t" << fo[i].date << endl;
		}
		cout << "请选择要购买的序号：";
		cin >> m;
		if (m >= fo.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "请输入要购买的数量：";
			int sum;
			cin >> sum;
			if (sum > fo[m].howMany)
			{
				cout << "库存不足！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "请选择支付方式（1微信/2支付宝）：";
				cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * fo[m].onePrize)
					{
						user.WX = user.WX - sum * (fo[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "微信";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * fo[m].onePrize;
						newOeder.commodityNum = fo[m].num;
						newOeder.commodityName = fo[m].name;
						fo[m].howMany = fo[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "微信余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * fo[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (fo[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "支付宝";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * fo[m].onePrize;
						newOeder.commodityNum = fo[m].num;
						newOeder.commodityName = fo[m].name;
						fo[m].howMany = fo[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "支付宝余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
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
		cout << endl << "家电" << endl;
		cout << "编号\t名称\t产地\t单价\t库存\t颜色" << endl;
		for (i = 0; i < el.size(); i++)
		{
			cout << el[i].num << "\t" << el[i].name << "\t" << el[i].origin << "\t" << el[i].onePrize << "\t" << el[i].howMany << "\t" << el[i].color << endl;
		}
		cout << "请选择要购买的序号：";
		cin >> m;
		if (m >= el.size())
		{
			cout << "序号有误！" << endl;
			cout << "按任意键继续！" << endl;
			getch();
			userBegin();
		}
		else
		{
			cout << "请输入要购买的数量：";
			int sum;
			cin >> sum;
			if (sum > el[m].howMany)
			{
				cout << "库存不足！" << endl;
				cout << "按任意键继续！" << endl;
				getch();
				userBegin();
			}
			else
			{
				int choose;
				Order newOeder;
				cout << "请选择支付方式（1微信/2支付宝）："; cin >> choose;
				if (choose == 1)
				{
					if (user.WX >= sum * el[m].onePrize)
					{
						user.WX = user.WX - sum * (el[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "微信";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * el[m].onePrize;
						newOeder.commodityNum = el[m].num;
						newOeder.commodityName = el[m].name;
						el[m].howMany = el[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "微信余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
					getch();
					userBegin();
				}
				else if (choose == 2)
				{
					if (user.ZFB >= sum * el[m].onePrize)
					{
						user.ZFB = user.ZFB - sum * (el[m].onePrize);
						newOeder.userNum = user.num;
						newOeder.payWay = "支付宝";
						newOeder.buyMany = sum;
						newOeder.payMonet = sum * el[m].onePrize;
						newOeder.commodityNum = el[m].num;
						newOeder.commodityName = el[m].name;
						el[m].howMany = el[m].howMany - sum;
						o.push_back(newOeder);
						cout << "购买成功！" << endl;
					}
					else
					{
						cout << "支付宝余额不足，请充值！" << endl;
					}
					cout << "按任意键继续！" << endl;
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
