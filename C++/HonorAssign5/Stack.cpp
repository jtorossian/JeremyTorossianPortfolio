#include "Stack.h"
/*********************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER: Jeremy Torossian
LOGON ID:   z1821996f
DUE DATE:   10/26/17

FUNCTION:   This program tests the functionality of the Stack class.
**********************************************************************/
Stack::Stack()
{
	StackCapacity = 0;
	StackSize = 0;
	Stackarray = nullptr;
}

Stack::~Stack()
{
	delete[] Stackarray;
}

Stack::Stack(const Stack & other)
{
	{
		StackCapacity = other.StackCapacity;
		StackSize = other.StackSize;

		if (StackCapacity == 0)
			Stackarray = nullptr;
		else
			Stackarray = new int[StackCapacity];

		for (size_t i = 0; i < StackSize; ++i)
			Stackarray[i] = other.Stackarray[i];
	}
}

Stack & Stack::operator=(const Stack & other)
{
	StackCapacity = other.StackCapacity;
	StackSize = other.StackSize;
	if (this == &other)
	{
		return *this;
	}
	if (StackCapacity == 0)
		Stackarray = nullptr;
	else
		Stackarray = new int[StackCapacity];

	for (size_t i = 0; i < StackSize; ++i)
		Stackarray[i] = other.Stackarray[i];

	return *this;

}

ostream & operator<<(ostream & lhs, const Stack & rhs)
{
	for (size_t i = 0; i < rhs.StackSize; i++)
		lhs << rhs.Stackarray[i] << ' ';

	 return lhs;
}

void Stack::clear()
{
	StackSize = 0;
}

size_t Stack::size() const
{
	return StackSize;
}

size_t Stack::capacity() const
{
	return StackCapacity;
}

bool Stack::empty() const
{
	if (StackSize == 0)
		return true;
	else
		return false;
}

int Stack::top() const
{
	if (empty())
		throw;

	return Stackarray[StackSize - 1];
}

void Stack::push(int val)
{
	if (StackSize == StackCapacity)
	{
		if (StackCapacity == 0)
			reserve(1);
		else
			reserve(StackCapacity * 2);
	}

	Stackarray[StackSize] = val;
	++StackSize;
}

void Stack::pop()
{
	if (empty())
		throw;
	--StackSize;
}

void Stack::reserve(size_t n)
{

		if (n < StackSize || n == StackCapacity)
			return;

		int* tempArray = new int[n];

		for (size_t i = 0; i < StackSize; ++i)
		{
			tempArray[i] = Stackarray[i];
		}

		StackCapacity = n;
		delete[] Stackarray;
		Stackarray = tempArray;

}

int Stack::operator[](size_t index) const
{
	return Stackarray[index];
}

int & Stack::operator[](size_t index)
{
	return Stackarray[index];
}

bool Stack::operator==(const Stack & other) const
{
	if (StackSize != other.StackSize)		
	return false;

	else
		for (size_t i = 0; i < StackSize; ++i)
		{
			if (Stackarray[i] != other.Stackarray[i])
				return false;
		}
		return true;
}


