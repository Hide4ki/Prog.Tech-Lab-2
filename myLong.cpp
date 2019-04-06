#include "myLong.h"

myLong::myLong(long a):value(new long(a))
{
}

myLong::myLong(void):value(new long(0))
{
}

myLong::myLong(const myLong &_long)
{
	value = new long(*_long.value);
}

myLong::~myLong(void)
{
	delete value;
}

myLong &myLong::operator --(void)
{
	long a;
	std::cout << "Enter value:";
	std::cin >> a;
	*value -= a;
	return *this;
}

myLong &myLong::operator --(int)
{
	--*value;
	return *this;
}

long myLong::operator !(void) const
{
	return -*value;
}

myLong &operator ++(myLong &op)
{
	long a;
	std::cout << "Enter value:";
	std::cin >> a;
	*op.value += a;
	return op;
}

myLong &operator ++(myLong &op, int)
{
	++*op.value;
	return op;
}

ostream &operator <<(ostream &stream, myLong &a)
{
	stream << *a.value;
	return stream;
}
