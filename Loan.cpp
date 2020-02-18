#include "Loan.h"

void operator >> (std::istream & is, Loan & tmp)
{
	cout << "¬ведите им€ пользовател€ у которого берЄте займ:" << endl;
	tmp.partnerUsername = tmp.InputCharCheck(tmp.partnerUsername);
	is >> dynamic_cast<Deposit&>(tmp);
}

void operator << (std::ostream & os, Loan & tmp)
{
	os << dynamic_cast<Deposit&>(tmp);
	os << tmp.partnerUsername;
}