#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include <Windows.h>
#include<string>
using namespace std;
class Goods
{
public:
	static Goods* beg;
	Goods* next = NULL;
	static void ShowList()
	{
		Goods* p = beg;
		while (p)
		{
			p->show();
			p = p->next;
		}
	}
	Goods()
	{
		name1 = new char[81];
	}
	Goods(const char* name, float coast1)
	{
		name1 = new char[strlen(name) + 1];
		strcpy(name1, name);
		coast = coast1;
	}
	virtual ~Goods()
	{
		delete[] name1;
	}
	virtual void show() = 0;
	virtual void input() = 0;
protected:
	char* name1;
	float coast;
};
Goods* Goods::beg = NULL;
class Toy :public Goods
{
protected:
	string material;
public:
	Toy() : Goods() {}
	Toy(const char* name, float coast1, string material, bool AddToList = false) :Goods(name, coast1)
	{
		if (AddToList)
		{
			Goods* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
	}
	void show()
	{
		cout << "\nКласс: Игрушки";
		cout << "\nИмя: " << name1;
		cout << "\nСтоимость:" << coast;
		cout << "\nМатериал:" << material;
		cout << "\n";
	}
	void input()
	{
		cout << "\nНазвание игрушки: ";
		cin >> name1;
		cout << "\nСтоимость :";
		cin >> coast;
		cout << "\n Материал: ";
		cin >> material;
		cout << "\n";
	}
};
class Product :public Goods
{
protected:
	int shelflife;
public:
	Product() : Goods() {}
	Product(const char* name, float coast1, int shelflife, bool AddToList = false) :Goods(name, coast1)
	{
		if (AddToList)
		{
			Goods* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
	}
	void show()
	{
		cout << "\nКласс: Продукт";
		cout << "\nНазвание продукта: " << name1;
		cout << "\nСтоимость:" << coast;
		cout << "\nСрок годности:" << shelflife;
		cout << "\n";
	}
	void input()
	{
		cout << "\nНазвание продукта: ";
		cin >> name1;
		cout << "\nСтоимость :";
		cin >> coast;
		cout << "\nСрок Годности :";
		cin >> shelflife;
		cout << "\n";
	}
};
class Milkproduct :public Product 
{
protected:
	int fat;
public:
	Milkproduct() : Product() {}
	Milkproduct(const char* name, float coast1, int fat, int shelflife, bool AddToList = false) :Product(name, coast1, shelflife, AddToList)
	{
		if (AddToList)
		{
			Goods* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
	}
	void show()
	{
		cout << "\nКласс: Молочный продукт";
		cout << "\nНазвание молочного продукта: " << name1;
		cout << "\nСтоимость:" << coast;
		cout << "\nЖирность:" << fat;
		cout << "\nСрок Годности:" << shelflife;
		cout << "\n";
	}
	void input()
	{
		cout << "\nНазвание продукта: ";
		cin >> name1;
		cout << "\nСтоимость :";
		cin >> coast;
		cout << "\nЖирность :";
		cin >> fat;
		cout << "\nСрок годности :";
		cin >> shelflife;
		cout << "\n";
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Toy* x1;
	Product* x2;
	Milkproduct* x3;
	x1 = new Toy;
	x2 = new Product;
	x3 = new Milkproduct;
	x1->input();
	x2->input();
	x3->input();
	cout << "---------------------------------\n";
	Goods::beg = x1;
	x1->next = x2;
	x2->next = x3;
	Milkproduct* x4 = new Milkproduct("Сыр Российский", 30, 15, true);
	Goods::ShowList();
	return 0;
}
