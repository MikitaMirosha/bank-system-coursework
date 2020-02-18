#pragma once
#include "List.h"
#include "Loan.h"
#include "Deposit.h"
#include "Account.h"
#include "MoneyTransfer.h"
#include <fstream>

template <class F>
class File
{
public:
	File() {};
	~File() {};
	static void FileOpenAccount(List<F> &tmp, const char *file);
	static void FileSaveAccount(List<F> &tmp, const char *file);
	static void FileOpenDeposit(List<F> &tmp, const char *file);
	static void FileSaveDeposit(List<F> &tmp, const char *file);
	static void FileOpenLoan(List<F> &tmp, const char *file);
	static void FileSaveLoan(List<F> &tmp, const char *file);
	static void FileOpenMoneyTransfer(List<F> &tmp, const char *file);
	static void FileSaveMoneyTransfer(List<F> &tmp, const char *file, string username);
};


template <class F>
void File<F>::FileOpenAccount(List <F> &tmp, const char *file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		string name;
		double balance;
		in >> name >> balance;
		if (!in || name == "-1") break;
		F obj(name, balance);
		tmp.push_tail(obj);
	}
	in.close();
}

template <class F>
void File<F>::FileSaveAccount(List <F> &tmp, const char *file)
{
	ofstream on;
	on.open(file, ios_base::out | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		on << tmp[i].getUsername() << " " << tmp[i].getBalance() << endl;
	}
	on << "-1";
	on.close();
}

template <class F>
void File<F>::FileOpenDeposit(List <F> &tmp, const char *file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		string name;
		double balance;
		int percent;
		in >> name >> balance >> percent;
		if (!in || name == "-1") break;
		F obj(name, balance, percent);
		tmp.push_tail(obj);
	}
	in.close();
}

template <class F>
void File<F>::FileSaveDeposit(List <F> &tmp, const char *file)
{
	ofstream on;
	on.open(file, ios_base::out | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		on << tmp[i].getUsername() << " " << tmp[i].getBalance() << " " << tmp[i].getPercent() << endl;
	}
	on << "-1";
	on.close();
}

template <class F>
void File<F>::FileOpenLoan(List <F> &tmp, const char *file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		string name, partner;
		double balance;
		int percent;
		in >> name >> balance >> percent >> partner;
		if (!in || name == "-1") break;
		F obj(name, balance, percent, partner);
		tmp.push_tail(obj);
	}
	in.close();
}

template <class F>
void File<F>::FileSaveLoan(List <F> &tmp, const char *file)
{
	ofstream on;
	on.open(file, ios_base::out | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		on << tmp[i].getUsername() << " " << tmp[i].getBalance() << " " << tmp[i].getPercent() << 
			" " << tmp[i].getPartnerUsername() << endl;
	}
	on << "-1";
	on.close();
}

template <class F>
void File<F>::FileOpenMoneyTransfer(List <F> &tmp, const char *file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		string name;
		double balance;
		string partner;
		in >> name >> balance >> partner;
		if (!in || name == "-1") break;
		F obj(name, balance, partner);
		tmp.push_tail(obj);
		in.get();
	}
	in.close();
}

template <class F>
void File<F>::FileSaveMoneyTransfer(List <F> &tmp, const char *file, string username)
{
	ofstream on;
	on.open(file, ios_base::out | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		on << username << " " << tmp[i].getBalance() << " " << tmp[i].getPartnerUsername() << endl;
	}
	on << "-1";
	on.close();
}