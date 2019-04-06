#pragma once
#include "elem.h"

class stack
{
	size_t *size;
	size_t *r_size;
	elem *head;
public:
	explicit stack(size_t s);
	stack(void);
	stack(const stack &myStack);
	~stack(void);
	size_t getSize(void) const;
	elem *getHead(void) const;
	void fill(void);
	float pop(void);
	void push(elem *newElem = new elem(0));
	void clear(void);
	stack &operator = (const stack &op2);
	stack  operator - (void) const;
	stack  operator - (const float &op2) const;
	stack  operator - (const stack &op2) const;
	stack &operator -=(const float &op2);
	stack &operator -=(const stack &op2);
	stack operator + (const float &op2) const;
	stack operator + (const stack &op2) const;
	friend stack &operator +=(stack &op1, const float &op2);
	friend stack &operator +=(stack &op1, const stack &op2);
	friend stack  operator * (const stack &op1,const float &op2);
	friend stack &operator *=(stack &op1,const float &op2);
	friend stack  operator / (const stack &op1, const float &op2);
	friend stack &operator /=(stack &op1, const float &op2);
	friend ostream &operator <<(ostream &stream, stack &myStack);
	friend istream &operator >>(istream &stream, stack &myStack);
};

