#include <iomanip>
#include "MoneyTransfer.h"
#include "InputException.h"

using namespace std;

void operator >> (std::istream & is, MoneyTransfer & tmp)
{
	cout << "¬ведите сумму: ";
	tmp.balance = CheckInput(0, 1000000);
}

void operator << (std::ostream & os, MoneyTransfer & tmp)
{
	os << setw(12) << tmp.balance;
}
void MoneyTransfer::operator = (const MoneyTransfer & tmp)
{
	balance = tmp.balance;
	partnerUsername = tmp.partnerUsername;
}

bool  operator== (MoneyTransfer tmp1, MoneyTransfer tmp2)
{
	return tmp1.balance == tmp2.balance && tmp1.partnerUsername == tmp2.partnerUsername;
}


const string &MoneyTransfer::getPartnerUsername() const 
{
	return partnerUsername;
}

void MoneyTransfer::setPartnerUsername(const string &partnerUsername) 
{
	MoneyTransfer::partnerUsername = partnerUsername;
}