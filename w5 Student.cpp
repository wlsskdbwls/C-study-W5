#include <iostream>
using namespace std;

#include "Student.h"

void Student::addPhone()  
{
	cout << "-- swing ��ȭ��ȣ�� --" << endl;
	cout << "�̸��� �Է��� �ּ��� >>";
	cin >> name;
	cout << "��ȭ��ȣ�� �Է��� �ּ��� >>";
	cin >> phone_num;
}

void Student::editPhone()   
{
	string n_name;  
	cout << "�̸��� �Է��� �ּ��� >>";

	do   
	{
		cin >> n_name;
		if (name != n_name)  
		{
			cout << "����ó�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���. >>";
		}
	} while (name != n_name);

	cout << "������ ��ȭ��ȣ�� �Է��� �ּ��� >>";
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