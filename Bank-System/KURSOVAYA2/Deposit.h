#pragma once
#include "Account.h"

class Deposit : public Account
{
	int percent;
public:
	explicit Deposit(const string &username = "", double balance = 0, int percent = 5);

	int getPercent() const;
	void setPercent(int percent);

	friend void updateBalance(Deposit* deposit);

	friend void operator >> (istream & is, Deposit & tmp);
	friend void operator << (ostream & os, Deposit & tmp);
	~Deposit() {};
};

