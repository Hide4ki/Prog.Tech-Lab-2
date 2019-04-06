#pragma once

#include <iostream>

using std::ostream;

class myException
{
	const char *textEx;
public:
	explicit myException(const char *a);
	myException(void);
	myException(const myException &e);
	~myException(void);
	friend ostream &operator<< (ostream &stream, const myException &a);
};
