/*********************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER: Jeremy Torossian
LOGON ID:   z1821996
DUE DATE:   10/26/17

FUNCTION:   This program tests the functionality of the Stack class.
**********************************************************************/

#include <iostream>
#include "Stack.h"

#include <iostream>
#include "Stack.h"

using namespace std;
using std::cout;
using std::endl;

//prototype
void evaluateExpressions();
bool isOperator(const string &);
int main()
{

	cout << "Testing default constructor\n\n";

	Stack s1;

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing push()\n\n";

	for (int i = 10; i < 80; i += 10)
		s1.push(i);

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	for (int i = 15; i < 85; i += 10)
		s1.push(i);

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing copy constructor()\n\n";

	Stack s2 = s1;

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing top()\n\n";

	cout << "Top item of s1: " << s1.top() << endl << endl;

	cout << "Testing pop()\n\nTop item of s1: ";

	while (!s1.empty())
	{
		cout << s1.top() << ' ';
		s1.pop();
	}

	cout << endl << endl;
	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing assignment operator\n\n";

	Stack s3;

	s3 = s2;

	cout << "s2 (size " << s2.size() << "): " << s2 << endl;
	cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;

	cout << "Testing clear()\n\n";

	s2.clear();

	cout << "s2: " << s2 << endl;
	cout << "s2 size: " << s2.size() << ", capacity: " << s2.capacity() << endl;
	cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "s3: " << s3 << endl;
	cout << "s3 size: " << s3.size() << ", capacity: " << s3.capacity() << endl;
	cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing assignment to self and swap\n\n";

	s3 = s3;
	s2 = s3;
	s3.clear();

	cout << "s2 (size " << s2.size() << "): " << s2 << endl;
	cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;

	cout << "Testing chained assignment\n\n";

	Stack s4;

	s4 = s3 = s2;

	cout << "s2 (size " << s2.size() << "): " << s2 << endl;
	cout << "s3 (size " << s3.size() << "): " << s3 << endl;
	cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;

	Stack s5 = s4;

	cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;

	cout << "Testing write version of subscript operator\n\n";

	for (size_t i = 0; i < s5.size(); ++i)
		s5[i] += 5;

	cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;

	cout << "Testing read version of subscript operator\n\nv5: ";

	for (size_t i = 0; i < s5.size(); ++i)
		cout << s5[i] << ' ';
	cout << endl << endl;

	cout << "Testing const correctness\n\n";

	const Stack& r4 = s4;

	cout << "s4: " << r4 << endl;
	cout << "s4 size: " << r4.size() << ", capacity: " << r4.capacity() << endl;
	cout << "s4 is " << ((r4.empty()) ? "empty\n" : "not empty\n");
	cout << "Top item of s4: " << r4.top() << endl;
	cout << "Element 2 of s4: " << r4[2] << endl << endl;

	s1 = r4;

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
	cout << endl;


	cout << "Testing equality operator\n\n";

	cout << "s1 and s4 are " << ((s1 == s4) ? "equal\n" : "not equal\n");
	cout << "s5 and s4 are " << ((s5 == s4) ? "equal\n" : "not equal\n");
	s1.pop();
	cout << "s1 and s4 are now " << ((s1 == s4) ? "equal\n" : "not equal\n");
	cout << endl;

	s1.clear();

	cout << "s1: " << s1 << endl;
	cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
	cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");

	cout << "\n" <<  "Evaluating Expression" << endl;

	evaluateExpressions();

	return 0;
}

void evaluateExpressions()
{
	Stack s6;
	ifstream inFile;
	bool MachoMan;
	int operand;
	int a;
	int b;
	int c;
	int answer;

	inFile.open("expressions.txt");

	//Checks if file was able to open
	if (!inFile)
	{
		cerr << "Unable to open expressions file\n";
		exit(1);
	}
	string temparray;
	//Reads through file
	while(inFile >> temparray)
	{
	MachoMan = isOperator(temparray);
		//If string is Operand it gets put through this loop
		if(MachoMan == false)
		{
			operand = stoi(temparray); //Converts string to int
                       	s6.push(operand); //Pushs operand to stack
		}

		if(MachoMan == true)
                {
			if(temparray == "=")//If string is equal to '='
                	{
			answer = s6.top();//Collects the answer
			s6.pop();//Pops answer off the stack
			cout << "The answer to the equation is: " << answer << endl;
			s6.clear();//Clears Stack for expression
			}
				else
				{
				a = s6.top();//Collects first operand
				s6.pop();//Pops first operand off the stack
				b = s6.top();//Collects second operand
				s6.pop();//Pops second operand off the stack
				}
				if(temparray == "+")//If operator is equal to '+'
				{
				c = b + a;
				s6.push(c);//Pushes answer to stack
				}
				if(temparray == "-")//If operator is equal to '-'
				{
				c = b - a;
                                s6.push(c);//Pushes answer to stack
				}
				if(temparray == "/")//If operator is equal to '/'
				{
				c = b / a;
                                s6.push(c);//Pushes answer to stack
				}
				if(temparray == "*")//If operator is equal to '*'
				{
				c = b * a;
				s6.push(c);//Pushes answer to stack
				}
                }

	}
	inFile.close();
}

bool isOperator(const string & test)
{
	if(test == "+" || test == "-" || test == "*" || test == "/" || test == "=")//If test is equal to +, -, *, /, or =. It returns "true"
	{
	return true;
	}
	else //If test is equal to anything else, it returns false
	{
	return false;
	}
}

