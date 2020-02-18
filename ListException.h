#pragma once
#include "Exception.h"

class ListException : public Exception
{
public:
	explicit ListException(int _error = 0) : Exception(_error) {};
	void ErrorText();
	~ListException() {};
};