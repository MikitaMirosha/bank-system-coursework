#include <iostream>
#include "ListException.h"
using namespace std;

void ListException::ErrorText()
{
	switch (error)
	{
	case 1:
	{
			  cout << "Ошибка 2.1:" << endl;
			  cout << "Список пуст!" << endl;
			  break;
	}
	}
}