#pragma once
#include <iomanip>
#include "Account.h"
#include "ListException.h"

using namespace std;

const string &Account::getUsername() const
{
	return username;
}

void operator << (std::ostream & os, Account & tmp)
{
	os << setw(15) << tmp.username << setw(12) << tmp.balance;
}

void operator >> (std::istream & is, Account &tmp)
{
	tmp.username = tmp.InputCharCheck(tmp.username);
}

bool Account::CheckCorrect(string input, bool fl) throw (InputException)
{
	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		if (input[i] < 'A' || input[i] > 'Z')
		{
			if (input[i] < 'a' || input[i] > 'z')
			{
				if (input[i] < '0' || input[i] > '9')
				{
					fl = false;
					throw InputException(1);
				}
			}
		}
	}
	if (len > 20)
	{
		fl = false;
		throw InputException(3);
	}
	if (input[0] >= '0' && input[0] <= '9')
	{
		fl = false;
		throw InputException(2);
	}
	return fl;
}

string Account::InputCharCheck(string input)
{
	bool fl = true;
	do
	{
		try
		{
			Account tmp;
			fflush(stdin);
			cin.sync();
			cin.clear();
			cin >> input;
			tmp.CheckCorrect(input, fl);
		}
		catch (InputException e)
		{

			e.ErrorText();
			cin.clear();
			cin.sync();
			InputCharCheck(input);
		}
		fflush(stdin);
	} while (!fl);
	return input;
}

bool CheckMoney(double money)
{
	try
	{
		if (money < 0) 
			throw InputException(5);
	}
	catch (InputException e)
	{
		e.ErrorText();
		return true;
	}
	return false;
}

int CheckInput(double input1, double input2)
{
	bool flag = true;
	int tmp = 0;
	do
	{
		try
		{
			cin.sync();
			cin.clear();
			rewind(stdin);
			cin >> tmp;
			flag = true;
			if (!cin || cin.peek() != '\n')
			{
				flag = false;
				throw InputException(4);
			}
			if (tmp < input1 || tmp > input2)
			{
				flag = false;
				throw 5;
			}
		}
		catch (InputException e)
		{
			e.ErrorText();
			cin.sync();
			cin.clear();
			rewind(stdin);
		}
		catch (...)
		{
			cin.sync();
			cin.clear();
			rewind(stdin);
			cout << "¬ведите число в интервале от " << input1 << " до " << input2 << endl;
		}
	} while (!flag);
	return tmp;
}

bool CheckList(double num)
{
	try
	{
		if (!num) throw ListException(1);
	}
	catch (ListException e)
	{
		e.ErrorText();
		return true;
	}
	return false;
}
