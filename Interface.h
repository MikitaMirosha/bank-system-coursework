#pragma once
#include <iostream> 
#include <conio.h>
#include <fstream>
#include "List.h"
#include "File.h"
#include "Loan.h"
#include "Deposit.h"
#include "Account.h"
#include "Exception.h"
#include "ListException.h"
#include "InputException.h"

template<class T> 
class Interface
{
public:
	static void outputTransfer(T& MainUser); 
	static void showAccounts(List<Account>& list);
	static void transferTo(T& MainUser, List<T>& list);
	static void cancelTransfer(T& MainUser, List<T>& list);
	static Deposit getDeposit(List<T>& list, Account& MainUser);
	static void getLoans(List<T>& list, List<T>&loanList, Account& MainUser);
	static void putDeposit(Deposit& MainDeposit, List<Deposit>& listD, T& MainUser, List<T>& list);
	static void outDeposit(Deposit& MainDeposit, List<Deposit>& listD, T& MainUser, List<T>& list);
	static void payLoan(Account& user, List<Account>& bankBookList, List<Loan> & loanList, List<Loan> & loans);
	static void menu(Account& user, List<Deposit>& depositList, List<Loan> & loanList, List<Account>& bankBookList);
	static void deleteAccount(Account& user, List<Account>& bankBookList, List<Deposit>& depositList, List<Loan> & loanList);
	static void createLoan(Deposit& MainDeposit, Account& user, List<Account>& bankBookList, List<Loan> & loanList, List<Loan> & loans);
};

template<class T>
void Interface<T>::menu(Account& MainUser, List<Deposit>& deposit, List<Loan> & loanList, List<Account>& bankBookList)
{
	Deposit MainDeposit = Interface<Deposit>::getDeposit(deposit, MainUser);
	thread* Thr = new thread(updateBalance, &MainDeposit);
	Thr->detach();
	List<Loan> loans;
	Interface<Loan>::getLoans(loanList, loans, MainUser);
	char input;
	

	do
	{
		system("cls");
		cout << "�������� ��������, ������� ������ ���������" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "| 1. | ��������� �������� �� ��������                   |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 2. | ������� �������� � ��������                      |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 3. | ���������� ������� ������                        |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 4. | ��������� ������ �� ������ ����                  |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 5. | ���������� ����� ���� ���������                  |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 6. | �������� �������� � ��������� �������            |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 7. | ���������� ���������� � ������                   |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 8. | ����� ����                                       |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 9. | ������� ����                                     |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| s. | ���������� �������� � ���������� �������         |" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "| d. | ������� �������                                  |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		cout << "| 0. | ����� �� ���������                               |" << endl; 
		cout << "---------------------------------------------------------" << endl;
		
		switch ((input = _getch()))
		{
		case '1': // 1. ��������� �������� �� ��������
		{
				system("cls");
				Interface<Account>::putDeposit(MainDeposit, deposit, MainUser, bankBookList);
				system("pause");
				break;
		}
		case '2': // 2. ������� �������� � �������� 
		{
				system("cls");
				Interface<Account>::outDeposit(MainDeposit, deposit, MainUser, bankBookList);
				system("pause");
				break;
		}
		case '3': // 3. ���������� ������� ������
		{
				system("cls");
				cout << "-------------------------------" << endl;
				cout << "��� ������������: " << MainUser.getUsername() << endl;
				cout << "-------------------------------" << endl;
				cout << "��� ������ ����������: ";
				cout << MainDeposit;
				cout << "-------------------------------" << endl;
				system("pause");
				break;
		}
		case '4': // 4. ������� ����� �� ������ ����
		{
				system("cls");
				Interface<Account>::transferTo(MainDeposit, bankBookList);
				system("pause");
				break;
		}
		case '5': // 5. ���������� ����� ���� ���������
		{
				system("cls");
				Interface<Account>::showAccounts(bankBookList);
				system("pause");
				break;
		}
		case '6': // 6. ������ ���������� �������� � ��������� �������  
		{
				system("cls");
				Interface<Account>::cancelTransfer(MainUser, bankBookList);
				system("pause");
				break;
		}
		case '7': // 7. ����������� ���������� � ������
		{
				system("cls");
				if (loans.size() < 1) { cout << "������ ����!" << endl; }
				else { loans.output_loans(); }
				system("pause");
				break;
		}
		case '8': // 8. ����� ����
		{
				system("cls");
				Interface<Account>::createLoan(MainDeposit, MainUser, bankBookList, loanList, loans);
				system("pause");
				break;
		}
		case '9': // 9. ������� ����
		{
				system("cls");
				if (loans.size() < 1) 
				{ 
					cout << "������ ����!" << endl; 
					system("pause");
					break;
				}
				Interface<Account>::payLoan(MainUser, bankBookList, loanList, loans);
				system("pause");
				break;
		}
		case 's': // s. ���������� �������� � ��������� �������
		{
				system("cls");
				Interface<Account>::outputTransfer(MainUser);
				system("pause");
				break;
		}
		case 'd': // d. ������� �������
		{
				system("cls");
				cout << "�� ������������� ������� ������� �������? " << endl;
				cout << "1 - ��" << endl;
				cout << "2 - ���" << endl;
				int deleteAccount = CheckInput(1, 2);
				if (deleteAccount == 1)
				{
					Interface<Account>::deleteAccount(MainUser, bankBookList, deposit, loanList);
					system("pause");
					input = '0';
				}
				else
				{
					system("cls");
					cout << "������ �������� ��������." << endl;
					system("pause");
				}
				break;
		}
		case '0': 
		{
				return;
		}
		default:
		{
				system("cls");
				cout << "������� �������� �������!" << endl;
				cout << "����������, ��������� ����." << endl;
				system("pause");
				break;
		}
		}
	} while (input != '0');
}

template<class T>
void Interface<T>::putDeposit(Deposit& MainDeposit, List<Deposit>& listD, T& MainUser, List<T>& list)
{
	system("cls");
	cout << "������� ����� ��� ���������� ������ ��������: ";
	double balance = CheckInput(0, 1000000);
	MainUser.setBalance(MainUser.getBalance() + balance);
	for (int i = 0; i < list.size(); i++) 
	{
		if (list[i].getUsername() == MainUser.getUsername()) 
		{
			list[i].setBalance(MainUser.getBalance());
		}
	}
	MainDeposit.setBalance(MainDeposit.getBalance() + balance);
	for (int i = 0; i < listD.size(); i++) 
	{
		if (listD[i].getUsername() == MainUser.getUsername()) 
		{
			listD[i].setBalance(MainDeposit.getBalance());
		}
	}
	system("pause");
}

template<class T>
void Interface<T>::outDeposit(Deposit& MainDeposit, List<Deposit>& listD, T& MainUser, List<T>& list)
{
	system("cls");
	cout << MainDeposit;
	cout << "������� ����� ��� ������ ������� � ������ ��������: ";
	double balance = CheckInput(0, MainDeposit.getBalance());
	MainDeposit.setBalance(MainDeposit.getBalance() - balance);
	for (int i = 0; i < listD.size(); i++) 
	{
		if (listD[i].getUsername() == MainUser.getUsername())
		{
			listD[i].setBalance(MainDeposit.getBalance());
		}
	}
	MainUser.setBalance(MainUser.getBalance() - balance);
	for (int i = 0; i < list.size(); i++) 
	{
		if (list[i].getUsername() == MainUser.getUsername())
		{
			list[i].setBalance(MainUser.getBalance());
		}
	}
	system("pause");
}

template<class T>
void Interface<T>::transferTo(T& MainUser, List<T>& list) 
{
	system("cls");
	list.output();
	int num = CheckInput(1, list.size());
	MoneyTransfer moneyTr;
	while (true) 
	{
		cin >> moneyTr;
		if (moneyTr.getBalance() > MainUser.getBalance()) 
		{
			cout << "������������ �������!" << endl;
			continue;
		}
		else 
		{
			list[num - 1].setBalance(list[num - 1].getBalance() + moneyTr.getBalance());
			MainUser.setBalance(MainUser.getBalance() - moneyTr.getBalance());
			for (int i = 0; i < list.size(); i++) 
			{
				if (list[i].getUsername() == MainUser.getUsername()) 
				{
					list[i].setBalance(MainUser.getBalance());
				}
			}
			moneyTr.setPartnerUsername(list[num - 1].getUsername());
			moneyTr.setUsername(MainUser.getUsername());
			string text = MainUser.getUsername() + ".txt";
			const char* file = text.c_str();
			List<MoneyTransfer> listMoney;
			File<MoneyTransfer>::FileOpenMoneyTransfer(listMoney, file);
			listMoney.push_tail(moneyTr);
			File<MoneyTransfer>::FileSaveMoneyTransfer(listMoney, file, MainUser.getUsername());
			return;
		}
		break;
	}
}

template<class T>
void Interface<T>::showAccounts(List<Account>& list)
{
	list.output();
}

template<class T>
void Interface<T>::cancelTransfer(T& MainUser, List<T>& list)
{
	system("cls");
	string text = MainUser.getUsername() + ".txt";
	const char* file = text.c_str();
	List<MoneyTransfer> listMoney = List<MoneyTransfer>();
	File<MoneyTransfer>::FileOpenMoneyTransfer(listMoney, file);
	if (listMoney.size() == 0)
	{
		cout << "������ 2.1:" << endl;
		cout << "������ ����!" << endl;
		return;
	}
	MoneyTransfer last = listMoney[list.size() - 1];
	listMoney.pop_tail();
	MainUser.setBalance(MainUser.getBalance() + last.getBalance());
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getUsername() == MainUser.getUsername())
		{
			list[i].setBalance(MainUser.getBalance());
		}
		if (list[i].getUsername() == last.getPartnerUsername())
		{
			list[i].setBalance(list[i].getBalance() - last.getBalance());
		}
	}
	File<MoneyTransfer>::FileSaveMoneyTransfer(listMoney, file, MainUser.getUsername());
}

template<class T>
Deposit Interface<T>::getDeposit(List<T>& list, Account& MainUser)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getUsername() == MainUser.getUsername())
		{
			return list[i];
		}
	}
	Deposit mainDeposit;
	mainDeposit.setUsername(MainUser.getUsername());
	list.push_tail(mainDeposit);
	return mainDeposit;
}

template<class T>
void Interface<T>::getLoans(List<T>& list, List<T>& loanList, Account& MainUser)
{
	for (int i = 0; i < list.size(); i++) 
	{
		if (list[i].getUsername() == MainUser.getUsername()) 
		{
			loanList.push_tail(list[i]);
			thread* Thr = new thread(updateBalance, &loanList[i]);
			Thr->detach();
		}
	}
}

template<class T>
void Interface<T>::outputTransfer(T& MainUser) 
{
	system("cls");
	string text = MainUser.getUsername() + ".txt";
	const char* file = text.c_str();
	List<MoneyTransfer> listMoney;
	File<MoneyTransfer>::FileOpenMoneyTransfer(listMoney, file);
	if (!listMoney.size()) 
	{
		cout << "������ 2.1:" << endl;
		cout << "������ ����!" << endl;
		return;
	}
	else 
	{
		listMoney.output_loans();
	}
}

template<class T>
void Interface<T>::deleteAccount(Account& user, List<Account>& bankBookList, List<Deposit>& deposit, List<Loan> & loanList)
{
	for (int i = 0; i < bankBookList.size(); i++) 
	{
		if (bankBookList[i].getUsername() == user.getUsername()) 
		{
			if (i == 0) bankBookList.pop_head();
			else if (i == bankBookList.size() - 1) bankBookList.pop_tail();
			else bankBookList.pop(i);
			i--;
		}
	}
	for (int i = 0; i < deposit.size(); i++) 
	{
		if (deposit[i].getUsername() == user.getUsername()) 
		{
			if (i == 0) deposit.pop_head();
			else if (i == deposit.size() - 1) deposit.pop_tail();
			else deposit.pop(i);
			i--;
		}
	}
	for (int i = 0; i < loanList.size(); i++) 
	{
		if (loanList[i].getUsername() == user.getUsername()) 
		{
			for (int j = 0; j < bankBookList.size(); j++) 
			{
				if (bankBookList[i].getUsername() == loanList[i].getPartnerUsername()) 
				{
					bankBookList[i].setBalance(bankBookList[i].getBalance() + loanList[i].getBalance());
				}
			}
			if (i == 0) loanList.pop_head();
			else if (i == loanList.size() - 1) loanList.pop_tail();
			else loanList.pop(i);
			i--;
		}
	}
}

template<class T>
void Interface<T>::createLoan(Deposit& MainDeposit, Account& user, List<Account>& bankBookList, List<Loan> & loanList, List<Loan> & loans)
{
	Loan newLoan;
	cin >> newLoan;
	loanList.push_tail(newLoan);
	thread* Thr = new thread(updateBalance, &loanList[loanList.size() - 1]);
	Thr->detach();
	loans.push_tail(newLoan);
	thread* Thr2 = new thread(updateBalance, &loans[loans.size() - 1]);
	Thr2->detach();
	for (int i = 0; i < bankBookList.size(); i++) 
	{
		if (bankBookList[i].getUsername() == newLoan.getPartnerUsername()) 
		{
			bankBookList[i].setBalance(bankBookList[i].getBalance() - newLoan.getBalance());
			user.setBalance(user.getBalance() + newLoan.getBalance());
		}
		if (bankBookList[i].getUsername() == user.getUsername()) 
		{
			bankBookList[i].setBalance(bankBookList[i].getBalance() + newLoan.getBalance());
			MainDeposit.setBalance(MainDeposit.getBalance() + newLoan.getBalance());
		}
	}
}

template<class T>
void Interface<T>::payLoan(Account& user, List<Account>& bankBookList, List<Loan> & loanList, List<Loan> & loans)
{
	if (loans.size() < 1) 
	{
		throw ListException(1);
	}
	loans.output();
	cout << "�������� ���� ��� ��������: ";
	int num = CheckInput(1, loans.size());
	num--;
	cout << "������� ����� ��� �������� �����: ";
	double balance = CheckInput(0, user.getBalance());
	for (int i = 0; i < bankBookList.size(); i++) 
	{
		if (bankBookList[i].getUsername() == loans[num].getPartnerUsername()) 
		{
			if (balance < loans[num].getBalance())
			{
				bankBookList[i].setBalance(bankBookList[i].getBalance() + balance);
				user.setBalance(user.getBalance() - balance);
				for (int j = 0; j < bankBookList.size(); j++) 
				{
					if (bankBookList[j].getUsername() == user.getUsername())
					{
						bankBookList[j].setBalance(bankBookList[j].getBalance() - balance);
					}
				}
				loans[num].setBalance(loans[num].getBalance() - balance);
			}
			else if (balance == loans[num].getBalance()) 
			{
				bankBookList[i].setBalance(bankBookList[i].getBalance() + balance);
				user.setBalance(user.getBalance() - balance);
				for (int j = 0; j < bankBookList.size(); j++) 
				{
					if (bankBookList[j].getUsername() == user.getUsername()) 
					{
						bankBookList[j].setBalance(bankBookList[j].getBalance() - balance);
					}
				}
				loans[num].setBalance(0);
			}
			else 
			{
				bankBookList[i].setBalance(bankBookList[i].getBalance() + loans[num].getBalance());
				user.setBalance(user.getBalance() - loans[num].getBalance());
				for (int j = 0; j < bankBookList.size(); j++) 
				{
					if (bankBookList[j].getUsername() == user.getUsername()) 
					{
						bankBookList[j].setBalance(bankBookList[j].getBalance() - loans[num].getBalance());
					}
				}
				loans[num].setBalance(0);
			}
		}
	}
	for (int i = 0; i < loanList.size(); i++)
	{
		if (loanList[i].getBalance() == 0)
		{
			loanList.pop(i);
		}
	}
	if (loans[num].getBalance() == 0) 
	{
		loans.pop(num);
	}
}