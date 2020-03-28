#pragma once
#include <iostream>
using namespace std;

class Exception
{
protected:
	int error;
public:
	Exception() { error = 0; }
	Exception(int _error) { error = _error; }
	virtual void ErrorText() {};
	~Exception() {};
};
