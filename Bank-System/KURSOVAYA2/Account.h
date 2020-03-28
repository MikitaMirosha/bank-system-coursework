#pragma once
#include <string>
#include "InputException.h"

using namespace std;

class Account
{
protected:
	string username;
	double balance;
public:
	explicit Account(string _username = "", double _balance = 0)
		: username(_username), balance(_balance) {};
	~Account() {};

	const string &getUsername() const;
	double getBalance() { return this->balance; }

	void setUsername(const string & tmp) { this->username = tmp; }
	void setBalance(double _balance) { this->balance = _balance; } 

	string InputCharCheck(string input);
	bool CheckCorrect(string input, bool fl) throw (InputException);

	friend void operator >> (std::istream & is, Account & tmp);
	friend void operator << (ostream & os, Account & tmp);
};

bool CheckMoney(double money);
bool CheckList(double num);
int CheckInput(double input1, double input2);