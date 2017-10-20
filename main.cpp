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

complex_t add(complex_t num1	, complex_t num2)
{
	complex_t result;
	result.real = num1.real+num2.real;
	result.imag = num1.imag+num2.imag;
	return result;
}

complex_t sub(complex_t num1, complex_t num2)
{
	complex_t result;
	result.real = num1.real - num2.real;
	result.imag = num1.imag - num2.imag;
	return result;
}

complex_t mul(complex_t num1, complex_t num2)
{
	complex_t result;
	result.real = (num1.real * num2.real - num1.imag*num2.imag);
	result.imag = (num1.imag *num2.real + num1.real * num2.imag);
	return result;
}

complex_t div(complex_t num1, complex_t num2)
{
	complex_t result;
	result.real = ((num1.real*num2.real+num1.imag*num2.imag) / (num2.real*num2.real+num2.imag*num2.imag));
	result.imag = ( (num1.imag*num2.real-num1.real*num2.imag) / (num2.real*num2.real + num2.imag*num2.imag) );
	return result;
}

bool read(istringstream & stream, complex_t  & comp )
{
	char op;
	if (stream >> op && op == '(' &&
		stream >> comp.real &&
		stream >> op && op == ',' &&
		stream >> comp.imag &&
		stream >> op && op == ')') 
	{
		return true;
	}
	else {
		cout << "An error has occured while reading input data";
		fail = true;
		return false;
	}
}

void write(complex_t result)
{
	cout << endl;
	cout << "(" << result.real << ", " << result.imag << ")";
}

int main()
{
	complex_t result,num1,num2;


	string str;
	char oper;
	getline(cin, str);
	istringstream stream(str);
	if (read(stream, num1) && stream >> oper  && read(stream, num2)) {
		switch (oper)
		{
		case '+':
			result = add(num1, num2);
			break;
		case'-':
			result = sub(num1, num2);
			break;
		case '*':
			result = mul(num1, num2);
			break;
		case'/':
			result = div(num1, num2);
			break;
		default:
			cout << "wrong operator";
			fail = true;
			break;
		}
	}
	else fail = true;
	if(!fail) write(result);
	cin.get();
    return 0;
}
