#include "elem.h"
#include "myException.h"

elem::elem(float x):value(new float(x))
{
	linkToNext = 0;
}

elem::elem(void):value(new float(0))
{
	linkToNext = 0;
}

elem::elem(const elem &myElem)
{
	value = new float(*myElem.value);
	linkToNext = myElem.linkToNext;
}

elem::~elem(void)
{
	delete value;
}

void elem::setLink(elem *next)
{
	linkToNext = next;
}

void elem::setValue(float v)
{
	*value = v;
}

elem *elem::getLink(void) const
{
	return linkToNext;
}

float elem::getValue(void) const
{
	return *value;
}

ostream &operator << (ostream &stream, const elem &myElem)
{
	stream << *myElem.value << endl;
	return stream;
}

elem &elem::operator = (const float &op2)
{
	*value = op2;
	return *this;
}

elem &elem::operator = (const elem &op2)
{
	linkToNext = 0;
	*value = *op2.value;
	return *this;
}

elem elem::operator - (void) const
{
	return elem(-*value);
}

elem elem::operator - (const float &op2) const
{
	return elem(*value - op2);
}

elem &elem::operator -=(const float &op2)
{
	*value -= op2;
	return *this;
}

elem elem::operator - (const elem &op2) const
{
	return elem(*value - op2.getValue());
}

elem &elem::operator -=(const elem &op2)
{
	*value -= op2.getValue();
	return *this;
}

elem elem::operator + (const float &op2) const
{
	return elem(*value + op2);
}

elem &elem::operator +=(const float &op2)
{
	*value += op2;
	return *this;
} 

elem elem::operator + (const elem &op2) const
{
	return elem(*value + op2.getValue());
}

elem &elem::operator +=(const elem &op2)
{
	*value += op2.getValue();
	return *this;
} 

elem elem::operator * (const float &op2) const
{
	return elem(*value * op2);
} 

elem &elem::operator *=(const float &op2)
{
	*value *= op2;
	return *this;
}

elem elem::operator * (const elem &op2) const
{
	return elem(*value * op2.getValue());
} 

elem &elem::operator *=(const elem &op2)
{
	*value *= op2.getValue();
	return *this;
}

elem elem::operator / (const float &op2) const
{
	if(op2 == 0)
		throw myException("Try division of zero");
	return elem(*value / op2);
}

elem &elem::operator /=(const float &op2)
{
	if(op2 == 0)
		throw myException("Try division of zero");
	*value /= op2;
	return *this;
}

elem elem::operator / (const elem &op2) const
{
	if(op2.getValue() == 0)
		throw myException("Try division of zero");
	return elem(*value / op2.getValue());
}

elem &elem::operator /=(const elem &op2)
{
	if(op2.getValue() == 0)
		throw myException("Try division of zero");
	*value /= op2.getValue();
	return *this;
}