#include "stack.h"
#include "myException.h"

stack::stack(size_t s):size(new size_t(s)),r_size(new size_t(0))
{
	head = NULL;
}

stack::stack(void):size(new size_t(10)),r_size(new size_t(0))
{
	head = NULL;
}

stack::stack(const stack &myStack)
{
	size = new size_t(*myStack.size);
	r_size = new size_t(*myStack.r_size);
	elem *tmp = myStack.head;
	elem *tmp1 = new elem;
	head = tmp1;
	elem *tmp2;
	while(tmp!=NULL)
	{
		tmp2 = tmp1;
		*tmp2 = *tmp;
		tmp1 = new elem;
		tmp2->setLink(tmp1);
		tmp = tmp->getLink();
	}
	delete tmp1;
	tmp2->setLink(NULL);
}

stack::~stack(void)
{
	clear();
	delete size;
	delete r_size;
}

void stack::fill(void)
{
	for(int i = *r_size; i<*size; i++)
		push(new elem(0));
}

void stack::clear(void)
{
	elem *tmp = head;
	elem *tmp2;
	while(tmp!=NULL)
	{
		tmp2 = tmp->getLink();
		delete tmp;
		tmp = tmp2;
	}
}

size_t stack::getSize(void)const
{
	return *r_size;
}

elem *stack::getHead(void)const
{
	return head;
}

float stack::pop(void)
{
	if(*r_size == 0)
		throw myException("stack is empty");
	elem *tmp = head->getLink();
	float result = head->getValue();
	--*r_size;
	delete head;
	head = tmp;
	return result;
}

void stack::push(elem *newElem)
{
	if(*r_size == *size)
		throw myException("Stack is full");
	elem *tmp = head;
	head = newElem;
	head->setLink(tmp);
	++*r_size;
}

stack &stack::operator = (const stack &op2)
{
	clear();
	*size = *op2.size;
	*r_size = *op2.r_size;
	elem *tmp = op2.head;
	elem *tmp1 = new elem;
	head = tmp1;
	elem *tmp2;
	while(tmp!=NULL)
	{
		tmp2 = tmp1;
		*tmp2 = *tmp;
		tmp1 = new elem;
		tmp2->setLink(tmp1);
		tmp = tmp->getLink();
	}
	delete tmp1;
	tmp2->setLink(NULL);
	return *this;
}

stack stack::operator - (void) const 
{
	stack result;
	result = *this;
	elem *tmp = result.head;
	while(tmp != NULL)
	{
		*tmp*=-1;
		tmp = tmp->getLink();
	}
	return result;
}

stack stack::operator - (const float &op2)const 
{
	stack result;
	result = *this;
	elem *tmp = result.head;
	while(tmp != NULL)
	{
		*tmp-=op2;
		tmp = tmp->getLink();
	}
	return result;
}

stack stack::operator - (const stack &op2)const 
{
	if(*r_size != *op2.r_size)
		throw myException("Stacks must be equals");
	stack result;
	result = *this;
	elem *tmp1 = result.head;
	elem *tmp2 = op2.head;
	while(tmp1 != NULL)
	{
		*tmp1 -= *tmp2;
		tmp1 = tmp1->getLink();
		tmp2 = tmp2->getLink();
	}
	return result;
}

stack &stack::operator -=(const float &op2)
{
	elem *tmp = head;
	while(tmp != NULL)
	{
		*tmp-=op2;
		tmp = tmp->getLink();
	}
	return *this;
}

stack &stack::operator -=(const stack &op2)
{
	if(*r_size != *op2.r_size)
		throw myException("Stacks must be equals");
	elem *tmp1 = head;
	elem *tmp2 = op2.head;
	while(tmp1 != NULL)
	{
		*tmp1-=*tmp2;
		tmp1 = tmp1->getLink();
		tmp2 = tmp2->getLink();
	}
	return *this;
}

stack stack::operator + (const float &op2)const 
{
	stack result;
	result = *this;
	elem *tmp = result.head;
	while(tmp != NULL)
	{
		*tmp += op2;
		tmp = tmp->getLink();
	}
	return result;
}

stack stack::operator + (const stack &op2)const 
{
	if(*r_size != *op2.r_size)
		throw myException("Stacks must be equals");
	stack result;
	result = *this;
	elem *tmp1 = result.head;
	elem *tmp2 = op2.head;
	while(tmp1 != NULL)
	{
		*tmp1 += *tmp2;
		tmp1 = tmp1->getLink();
		tmp2 = tmp2->getLink();
	}
	return result;
}

stack &operator +=(stack &op1, const float &op2)
{
	elem *tmp = op1.head;
	while(tmp != NULL)
	{
		*tmp+=op2;
		tmp = tmp->getLink();
	}
	return op1;
}

stack &operator +=(stack &op1, const stack &op2)
{
	if(*op1.r_size != *op2.r_size)
		throw myException("Stacks must be equals");
	elem *tmp1 = op1.head;
	elem *tmp2 = op2.head;
	while(tmp1 != NULL)
	{
		*tmp1 += *tmp2;
		tmp1 = tmp1->getLink();
		tmp2 = tmp2->getLink();
	}
	return op1;
}

stack operator * (const stack &op1, const float &op2) 
{
	stack result;
	result = op1;
	elem *tmp1 = result.head;
	while(tmp1 != NULL)
	{
		*tmp1 *= op2;
		tmp1 = tmp1->getLink();
	}
	return result;
}

stack &operator *=(stack &op1, const float &op2)
{
	elem *tmp = op1.head;
	while(tmp != NULL)
	{
		*tmp *= op2;
		tmp = tmp->getLink();
	}
	return op1;
}

stack operator / (const stack &op1, const float &op2) 
{
	stack result;
	result = op1;
	elem *tmp1 = result.head;
	while(tmp1 != NULL)
	{
		*tmp1 /= op2;
		tmp1 = tmp1->getLink();
	}
	return result;
}

stack &operator /=(stack &op1, const float &op2)
{
	elem *tmp = op1.head;
	while(tmp != NULL)
	{
		*tmp /= op2;
		tmp = tmp->getLink();
	}
	return op1;
}

istream &operator >>(istream &stream, stack &myStack)
{
	
	return stream;
}

ostream &operator <<(ostream &stream, stack &myStack)
{
	elem *tmp1 = myStack.head;
	while(tmp1 != NULL)
	{
		stream << *tmp1 << "\t";
		tmp1 = tmp1->getLink();
	}
	stream << endl;
	return stream;
}