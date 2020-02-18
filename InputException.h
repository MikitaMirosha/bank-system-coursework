#pragma once
#include "Exception.h"

class InputException : public Exception
{
public:
	InputException() : Exception() {};
	InputException(int _error) : Exception(_error) {};
	void ErrorText();
	~InputException(){};
};