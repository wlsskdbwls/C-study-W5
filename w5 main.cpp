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
		cout << endl << "1. 최신 등록 전화번호 조회" << endl;
		cout << "2. 최신 등록 전화번호 수정" << endl;
		cout << "3. 종료 >> ";
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