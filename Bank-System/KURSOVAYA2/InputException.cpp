#include <iostream>
#include "InputException.h"
using namespace std;

void InputException::ErrorText()
{
	switch (error)
	{
	case 2:
		cout << "Ошибка 1.2" << endl;
		cout << "Имя пользователя не может начинаться с цифры!" << endl << endl;
		break;
	case 3:
		cout << "Ошибка 1.3" << endl;
		cout << "Превышен лимит по вводу символов!" << endl;
		cout << "Максимально допустимое значение - 20 символов." << endl << endl;
		break;
	case 4:
		cout << "Ошибка 1.4" << endl;
		cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!" << endl << endl;
		break;
	case 5:
		cout << "Ошибка 1.5" << endl;
		cout << "Невозможно совершить операцию!" << endl;
		cout << "Баланс пользователя не может быть отрицательным" << endl;
		break;
	default:
		cout << "Ошибка ввода" << endl;
		cout << "Повторите ввод" << endl;
		break;
	}
}
