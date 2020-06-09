#include <iostream>
#include<string>
using namespace std;

class VendingMachine
{
private:
	string name;  // 음료 이름
	int price; // 음료 가격
	int total =0;  // 총 음료 값(초기화)

public:
	VendingMachine() {};  // 생성자
	void purchase(double v1);  // 구매 과정
	void menu();   // 기존 메뉴
	void Remenu();   // 음료가 추가된 메뉴
	string getName();   // 음료 이름 반환
	double getPrice();   // 음료 가격 반환
	double getTotal();   // 총 음료 값 반환
	void setName(string n);   // 음료 이름 수정
	void setPrice(int p);   // 음료 가격 수정
	void setTotal(int t);   // 총 음료 값 수정
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

string VendingMachine::getName()   // 추가할 음료수 이름을 입력하는데 사용
{
	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >> name;
	return name;
}

double VendingMachine::getPrice()   // 추가할 음료수 가격을 입력하는데 사용(main 함수에서 사용해야 하므로 price만 반환하도록)
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
	int cash, change;   // cash- 지폐, change- 거스름돈
	cout << "총 금액 :" << v1 << endl;
	cout << "지폐를 입력하세요 : ";

	while (1) 
	{
		cin >> cash;
		change = cash - v1;

		if (change == 0)   // 지불한 돈 = 총 금액
		{
			cout << "거스름 돈이 없습니다.";
			break;
		}
		else if (change < 0)   // 지불한 돈 < 총 금액 
		{
			cout << "금액이 부족합니다. 다시 넣어주세요. : ";
		}
		else if (change > 0)   // 지불한 돈 > 총 금액 
		{
			if (change % 100 == 0)  // 거스름 돈이 100원과 500원으로만 나올 경우
			{
				cout << "거스름 돈입니다." << endl;
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500/100 << "개" << endl;
				break;
			}
			else   // 거스름 돈이 100원과 500원으로만 나오지 않는 경우(10원 단위가 있는 경우)
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
	
	VendingMachine Drink;   // VendingMachine에 Drink라는 객체를 생성
	VendingMachine *p = &Drink;   // 객체 Drink를 가리키는 포인터 변수 p를 선언

	string addname;   // 추가한 음료의 이름
	double addprice;   //추가한 음료의 가격
 
	Drink.menu();   // 기존 메뉴 출력

	p->setName(Drink.getName());   // 추가할 음료수 이름을 매개변수로 받아 수정

	cout << "판매할 가격을 입력하세요 : ";
	cin >> addprice;
	p->setPrice(addprice);   // 추가할 음료수 가격을 매개변수로 받아 수정
	cout << endl;
	
	int num, qty;   // num- 메뉴 번호, qty- 수량

	do
	{
		Drink.Remenu();   // 음료가 추가된 메뉴 출력
		cout << endl;
		cout << "번호를 선택해주세요 : ";
		cin >> num;

		switch (num)
		{
		case 1:  // 코카콜라
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 1500);
			break;

		case 2:  // 비타500
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 900);
			break;

		case 3:  // 파워에이드
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * 2000);
			break;

		case 4:  // 추가한 
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> qty;
			p->setTotal(qty * Drink.getPrice());
			break;
		}
	} while (num != 5);   // 5번을 누를 때까지 반복

	cout << endl;
	cout << "계산 중입니다. 기다려주세요 . . ." << endl;
	Drink.purchase(Drink.getTotal());   // 총 가격을 매개변수로 받아 purchase함수 호출

}
