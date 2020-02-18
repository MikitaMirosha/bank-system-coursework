#pragma once
#include "Account.h"

class MoneyTransfer : public Account
{
protected:
	string partnerUsername;
public:
	explicit MoneyTransfer(string _username = "", double _balance = 0, string partnerUsername = "")
		: Account(_username, _balance), partnerUsername(partnerUsername) {};
	~MoneyTransfer() {}

	const string &getPartnerUsername() const;
	void setPartnerUsername(const string &partnerUsername);

	friend void operator >> (istream & is, MoneyTransfer & tmp);
	friend void operator << (ostream & os, MoneyTransfer & tmp);
	friend bool operator == (MoneyTransfer tmp1, MoneyTransfer tmp2);
	void operator = (const MoneyTransfer & tmp);
};