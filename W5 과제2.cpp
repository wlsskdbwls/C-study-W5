#include <iostream>
#include<string>
using namespace std;

class VendingMachine
{
private:
	string name;
	int price;
	int total =0;

public:
	VendingMachine() {};
	void purchase(double v1);
	void menu();
	void Remenu();
	string getName();
	double getPrice();
	double getprice();
	double getTotal();
	void setName(string n);
	void setPrice(int p);
	void setTotal(int t);
};

void VendingMachine::menu()
{
	cout << "====== SWING 자판기 ======" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. 준비중" << endl;
	cout << "5. 계산" << endl;
	cout << endl;
}

void VendingMachine::Remenu()
{
	cout << "====== SWING 자판기 ======" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. " << name << " : " << price << "원" << endl;
	cout << "5. 계산" << endl;
}

string VendingMachine::getName()
{
	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >> name;
	return name;
}

double VendingMachine::getPrice()
{
	return price;
}

double VendingMachine::getTotal()
{
	return total;
}

void VendingMachine::setName(string n)
{
	name = n;
}

void VendingMachine::setPrice(int p)
{
	price = p;
}

void VendingMachine::setTotal(int t)
{
	total += t;
}

void VendingMachine::purchase(double v1)
{
	int cash, change;
	cout << "총 금액 :" << v1 << endl;
	cout << "지폐를 입력하세요 : ";

	while (1) 
	{
		cin >> cash;
		change = cash - v1;

		if (cash == v1)
		{
			cout << "거스름 돈이 없습니다.";
			break;
		}
		else if (cash < v1)
		{
			cout << "금액이 부족합니다. 다시 넣어주세요. : ";
		}
		else if (cash > v1)
		{
			if (change % 100 == 0)
			{
				cout << "거스름 돈입니다." << endl;
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500/100 << "개" << endl;
				break;
			}
			else
			{
				cout << "거스름돈은 100원과 500원만 가능합니다." << endl;
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500 / 100 << "개" << endl;
				break;
			}
		}
	}
	cout << "안녕히가세요." << endl;
}

int main()
{
	
	VendingMachine Drink;
	VendingMachine *p = &Drink;

	string addname;
	double addprice;

	Drink.menu();

	p->setName(Drink.getName());

	cout << "판매할 가격을 입력하세요 : ";
	cin >> addprice;
	p->setPrice(addprice);
	cout << endl;
	
	int num, qty;

	do
	{
		Drink.Remenu();
		cout << endl;
		cout << "번호를 선택해주세요 : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 1500);
			break;

		case 2:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 900);
			break;

		case 3:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 2000);
			break;

		case 4:
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * Drink.getPrice());
			break;
		}
	} while (num != 5);

	cout << endl;
	cout << "계산 중입니다. 기다려주세요 . . ." << endl;
	Drink.purchase(Drink.getTotal());
}
