#include <iostream>
#include <thread>
#include "Windows.h"
#include "Deposit.h"

Deposit::Deposit(const string &username, double balance, int percent)
		: Account(username, balance), percent(percent) {}

int Deposit::getPercent() const 
{
	return percent;
}

void Deposit::setPercent(int percent) 
{
	Deposit::percent = percent;
}

void operator >> (std::istream & is, Deposit & tmp)
{
	cout << "Введите сумму депозита: ";
	tmp.balance = CheckInput(0, 999999);
	cout << "Введите процент депозита (1% - 10%): ";
	tmp.percent = CheckInput(1, 10);
}

void operator << (std::ostream & os, Deposit & tmp)
{
	os << tmp.balance << endl;
	cout << "-------------------------------" << endl;
	os << "Процентная ставка: " << tmp.percent << "%" << endl;
}

void updateBalance(Deposit* deposit) 
{
	while (true) 
	{
		Sleep(60000);
		deposit->balance = deposit->balance * (100 + deposit->percent) / 100;
	}
}