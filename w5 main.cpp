#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

int main()
{
	Student stu;
	stu.addPhone();

	int n;
	do  
	{
		cout << endl << "1. �ֽ� ��� ��ȭ��ȣ ��ȸ" << endl;
		cout << "2. �ֽ� ��� ��ȭ��ȣ ����" << endl;
		cout << "3. ���� >> ";
		cin >> n;  

		switch (n)
		{
		case 1:  
			cout << stu.getName() << "::" << stu.getPnum() << endl;
			break;
		case 2:   
			stu.editPhone();
		}
	} while (n != 3);
}