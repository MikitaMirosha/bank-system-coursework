#include <iostream>
#include <fstream>
#include <thread>
#include "Windows.h"
#include "Interface.h"
using namespace std;

int main() 
{
	system("color 70");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List<Deposit> depositList;
	File<Deposit>::FileOpenDeposit(depositList, "deposit.txt");
	for (int i = 0; i < depositList.size(); i++) 
	{
		thread* Thr = new thread(updateBalance, &depositList[i]);
		Thr->detach();
	}

	List<Loan> loanList;
	File<Loan>::FileOpenLoan(loanList, "loan.txt");
	for (int i = 0; i < loanList.size(); i++) 
	{
		thread* Thr = new thread(updateBalance, &loanList[i]);
		Thr->detach();
	}

	while (true) 
	{
		cout << "Вас приветствует банковская система!" << endl;
		cout << "Для входа введите имя пользователя или введите '0' для выхода: " << endl;
		List<Account> AccountList;
		File<Account>::FileOpenAccount(AccountList, "account.txt");
		Account user;
		string username;
		rewind(stdin);
		cin >> username; 
		if (username == "0") break;
		user = AccountList.getUser(username);
		Interface<int>::menu(user, depositList, loanList, AccountList);
		File<Account>::FileSaveAccount(AccountList, "account.txt");
	}
	File<Deposit>::FileSaveDeposit(depositList, "deposit.txt");
	File<Loan>::FileSaveLoan(loanList, "loan.txt");
	return 0;
}