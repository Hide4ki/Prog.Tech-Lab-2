#pragma once
#include <iostream>

using namespace std;

class elem
{
	float *value;
	elem *linkToNext;
public:
	explicit elem(float x);
	elem(void);
	elem(const elem &myElem);
	~elem(void);
	void setLink(elem *next = 0);
	void setValue(float v = 10);
	elem *getLink(void) const;
	float getValue(void) const;
	friend ostream &operator << (ostream &stream,const elem &myElem);
	elem &operator = (const elem &op2);
	elem &operator = (const float &op2);
	elem operator - (void) const;
	elem operator - (const float &op2) const;
	elem operator - (const elem &op2) const;
	elem &operator -=(const float &op2);
	elem &operator -=(const elem &op2);
	elem operator + (const float &op2) const;
	elem &operator +=(const float &op2);
	elem operator + (const elem &op2) const;
	elem &operator +=(const elem &op2);
	elem operator * (const float &op2) const;
	elem &operator *=(const float &op2);
	elem operator * (const elem &op2) const;
	elem &operator *=(const elem &op2);
	elem operator / (const float &op2) const;
	elem &operator /=(const float &op2);
	elem operator / (const elem &op2) const;
	elem &operator /=(const elem &op2);
};				     

