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
	cout << "====== SWING ���Ǳ� ======" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. �غ���" << endl;
	cout << "5. ���" << endl;
	cout << endl;
}

void VendingMachine::Remenu()
{
	cout << "====== SWING ���Ǳ� ======" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. " << name << " : " << price << "��" << endl;
	cout << "5. ���" << endl;
}

string VendingMachine::getName()
{
	cout << "�߰��� ���� �̸��� �Է����ּ��� : ";
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
	cout << "�� �ݾ� :" << v1 << endl;
	cout << "���� �Է��ϼ��� : ";

	while (1) 
	{
		cin >> cash;
		change = cash - v1;

		if (cash == v1)
		{
			cout << "�Ž��� ���� �����ϴ�.";
			break;
		}
		else if (cash < v1)
		{
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ���. : ";
		}
		else if (cash > v1)
		{
			if (change % 100 == 0)
			{
				cout << "�Ž��� ���Դϴ�." << endl;
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500/100 << "��" << endl;
				break;
			}
			else
			{
				cout << "�Ž������� 100���� 500���� �����մϴ�." << endl;
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500 / 100 << "��" << endl;
				break;
			}
		}
	}
	cout << "�ȳ���������." << endl;
}

int main()
{
	
	VendingMachine Drink;
	VendingMachine *p = &Drink;

	string addname;
	double addprice;

	Drink.menu();

	p->setName(Drink.getName());

	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> addprice;
	p->setPrice(addprice);
	cout << endl;
	
	int num, qty;

	do
	{
		Drink.Remenu();
		cout << endl;
		cout << "��ȣ�� �������ּ��� : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> qty;
			p->setTotal(qty * 1500);
			break;

		case 2:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> qty;
			p->setTotal(qty * 900);
			break;

		case 3:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> qty;
			p->setTotal(qty * 2000);
			break;

		case 4:
			cout << "������ ������ �Է����ּ��� : ";
			cin >> qty;
			p->setTotal(qty * Drink.getPrice());
			break;
		}
	} while (num != 5);

	cout << endl;
	cout << "��� ���Դϴ�. ��ٷ��ּ��� . . ." << endl;
	Drink.purchase(Drink.getTotal());
}
