#include <iostream>
#include "InputException.h"
using namespace std;

void InputException::ErrorText()
{
	switch (error)
	{
	case 2:
		cout << "������ 1.2" << endl;
		cout << "��� ������������ �� ����� ���������� � �����!" << endl << endl;
		break;
	case 3:
		cout << "������ 1.3" << endl;
		cout << "�������� ����� �� ����� ��������!" << endl;
		cout << "����������� ���������� �������� - 20 ��������." << endl << endl;
		break;
	case 4:
		cout << "������ 1.4" << endl;
		cout << "�� ����� ������� ������ ����� ���� �������� ������ �� ����� �����!" << endl << endl;
		break;
	case 5:
		cout << "������ 1.5" << endl;
		cout << "���������� ��������� ��������!" << endl;
		cout << "������ ������������ �� ����� ���� �������������" << endl;
		break;
	default:
		cout << "������ �����" << endl;
		cout << "��������� ����" << endl;
		break;
	}
}
