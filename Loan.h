#pragma once
#include "Deposit.h"

class Loan : public Deposit
{
private:
	string partnerUsername;
public:
	explicit Loan(const string &username = "", double balance = 0, int percent = 0, const string &partnerUsername = "") :
		Deposit(username, balance, percent), partnerUsername(partnerUsername) {};
	~Loan() {};

	string getPartnerUsername() const { return this->partnerUsername; }
	void setPartnerUsername(string tmp) { this->partnerUsername = tmp; }

	friend void operator >> (istream & is, Loan & tmp);
	friend void operator << (ostream & os, Loan & tmp);
};
