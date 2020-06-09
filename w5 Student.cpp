#include <iostream>
using namespace std;

#include "Student.h"

void Student::addPhone()  
{
	cout << "-- swing 전화번호부 --" << endl;
	cout << "이름을 입력해 주세요 >>";
	cin >> name;
	cout << "전화번호를 입력해 주세요 >>";
	cin >> phone_num;
}

void Student::editPhone()   
{
	string n_name;  
	cout << "이름을 입력해 주세요 >>";

	do   
	{
		cin >> n_name;
		if (name != n_name)  
		{
			cout << "연락처가 존재하지 않습니다. 다시 입력해주세요. >>";
		}
	} while (name != n_name);

	cout << "변경할 전화번호를 입력해 주세요 >>";
	cin >> phone_num;
}

string Student::getPnum()   
{
	return phone_num;
}

string Student::getName()   
{
	return name;
}