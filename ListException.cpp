#include <iostream>
#include "ListException.h"
using namespace std;

void ListException::ErrorText()
{
	switch (error)
	{
	case 1:
	{
			  cout << "������ 2.1:" << endl;
			  cout << "������ ����!" << endl;
			  break;
	}
	}
}