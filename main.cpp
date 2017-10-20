#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
static bool fail= false;
struct complex_t 
{
	float real;
	float imag;
};

void add (complex_t & comp , float &t1,float &t2)
{

	comp.real += t1;
	comp.imag += t2;
}

void sub(complex_t & comp, float &t1, float &t2)
{
	comp.real = t1 - comp.real;
	comp.imag = t2 - comp.imag;
}

void mul(complex_t & comp, float &t1, float &t2)
{
	float t = comp.real;
	comp.real = (t1 * comp.real - t2*comp.imag);
	comp.imag = (t2 *t + t1* comp.imag);
}

void div(complex_t & comp, float &t1, float &t2)
{
	float t = comp.real;
	comp.real = ((t1*comp.real+t2*comp.imag) / (comp.real*comp.real+comp.imag*comp.imag));
	comp.imag = ( (t2*t-t1*comp.imag) / (t*t+ comp.imag*comp.imag) );
}

void read(complex_t & comp)
{
	string str;
	char op;
	getline(cin, str);
	istringstream stream(str);
	bool pr=true;
	// first number
	if (stream >> op && op == '(' &&
		stream >> comp.real &&
		stream >> op && op == ',' &&
		stream >> comp.imag &&
		stream >> op && op == ')') {
	}
	else {
		cout << "An error has occured while reading input data";
		pr = false;
		fail = true;
		//end of first
	}
	while (stream >> op && pr)
	{
		char oper = op; float t1, t2; t1 = comp.real; t2 = comp.imag;
		if (stream >> op && op == '(' &&
			stream >> comp.real &&
			stream >> op && op == ',' &&
			stream >> comp.imag &&
			stream >> op && op == ')')
		{
			switch (oper)
			{
			case '+':
				add(comp, t1, t2);
				break;
			case'-':
				sub(comp, t1, t2);
				break;
			case '*':
				mul(comp, t1, t2);
				break;
			case'/':
				div(comp, t1, t2);
				break;
			default:
				cout << "wrong operator";
				fail = true;
				break;
			}
		}
		else 
		{
			cout << "An error has occured while reading input data";
			fail = true;
			break;
		}
	}
	//cout << "wrong operator";
}

void write(complex_t comp)
{
	cout << endl;
	cout << "(" << comp.real << ", " << comp.imag << ")";
}

int main()
{
	complex_t comp;
	read(comp);
	if(!fail) write(comp);
	system("pause");
    return 0;
}
