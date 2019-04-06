#pragma once
#include <iostream>

using std::ostream;

class myLong
{
	long *value;
public:
	myLong(long a);
	myLong(void);
	myLong(const myLong &a);
	~myLong(void);
	myLong &operator --(int);
	myLong &operator --(void);
	long operator !(void) const;
	friend myLong &operator ++(myLong &op, int);
	friend myLong &operator ++(myLong &op);
	friend ostream &operator <<(ostream &stream, myLong &a);
};

