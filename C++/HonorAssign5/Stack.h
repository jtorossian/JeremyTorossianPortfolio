#ifndef STACK_H
#define STACK_H

//*****************************************************************
// FILE:      Stack.h
// AUTHOR:    Jeremy Torossian
// LOGON ID:  z1821996
// DUE DATE:  10/26/2017
// 
// PURPOSE:   Declaration for the Stack class
//            
//*****************************************************************

#include <iostream>
#include <sys/types.h>
#include <fstream>

using namespace std;

class Stack
{
	friend ostream & operator<<(ostream &, const Stack &);
	friend istream & operator>>(istream &, Stack &);
public:
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	int top() const;
	void push(int);
	void pop();
	void reserve(size_t);
	int operator[](size_t) const;
	int& operator[](size_t);
	bool operator==(const Stack&) const;



private:
	int* Stackarray;
	unsigned int StackCapacity;
	unsigned int StackSize;
	int subscript;

};



#endif