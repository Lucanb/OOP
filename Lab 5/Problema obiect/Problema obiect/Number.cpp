#include "Number.h"
#include<iostream>
#include<string.h>
using namespace std;

Number::Number(const char* val, int base)
{
	this->valoare = new char[strlen(val)];
	memcpy(this->valoare, val, strlen(val) + 1);
	this->baza = base;
	EsteNeg = valoare[0] == '-';
}
Number::~Number()
{
}
Number::Number(const Number& n)
{
	baza = n.baza;
	valoare = n.valoare;
	this->EsteNeg = n.EsteNeg;
	// delete n;
}
Number::Number(const Number&& n)
{
	this->baza = n.baza;
	valoare = n.valoare;
	EsteNeg = n.EsteNeg;
}
Number::Number(const int n)
{
	baza = 10;
	valoare = toString(n);
	EsteNeg = (n < 0);
}
Number operator+ (const Number& x, const Number& y)
{
	Number a = x;
	Number b = y;
	int maxBaza = a.GetBase() > b.GetBase() ? a.GetBase() : b.GetBase();
	long long n = a.GetBaseTen();
	n += b.GetBaseTen();
	char* c = toString(n);
	Number newN(c, 10);
	newN.SwitchBase(maxBaza);
	return newN;
}
Number operator- (const Number& x, const Number& y)
{
	Number a = x;
	Number b = y;
	int maxBaza = a.GetBase() > b.GetBase() ? a.GetBase() : b.GetBase();
	long long n = a.GetBaseTen();
	n -= b.GetBaseTen();
	char* c = toString(n);
	Number newN(c, 10);
	newN.SwitchBase(maxBaza);
	return newN;
}
bool Number :: operator> (Number& n)
{
	long long a = GetBaseTen();
	long long b = n.GetBaseTen();
	return a > b;
}
void Number :: operator= (const char* s)
{
	Number a(s, 10);
	*this = a;
}
void Number ::operator= (const Number& n)
{
	baza = n.baza;
	valoare = n.valoare;
	EsteNeg = n.EsteNeg;
}
void Number::operator=(int n)
{
	Number a(toString(n), 10);
	a.SwitchBase(baza);
	* this = a;
}

void Number ::operator+= (Number& n)
{
	long long a = GetBaseTen();
	a += n.GetBaseTen();
	bool b = a < 0;
	toString(a);
	valoare = toString(a);
	EsteNeg = b;
	SwitchBase(baza);
}

void Number ::operator-- ()
{
	valoare++;
}

void Number ::operator-- (int)
{
	valoare[strlen(valoare) - 1] = '\n';
}

void Number::SwitchBase(int newBase)
{
	long long n = convertToBaseTen(valoare, baza);
	char* p = convertToBase(n, newBase);
	valoare = p;
	baza = newBase;
}
void Number::Print()
{
	for (int i = 0; valoare[i] != '\0'; i++)
		std::cout << valoare[i];
	std::cout << '/n';
}
int  Number::GetDigitsCount() // returns the number of digits for the current number
{
	return strlen(valoare) - (EsteNeg ? 1 : 0);
}
int  Number::GetBase()
{
	return baza;
}// returns the current base
long long Number::convertToBaseTen(char* s, int base)
{
	long long n=0, k = 1;
	for (int i = strlen(valoare) - 1; i >= (int)EsteNeg; i--)
	{
		n += normaliseDigit(s[i]) * k;
		k *= base;
	}
	return n;
}
char Number::operator[](int i)
{
	return valoare[i];
}
char* Number::convertToBase(long long n, int base)
{
	char* c = new char[50];
	int i = 0;
	while (n != 0)
	{
		int a = n % base;
		c[i++] = formalizeDigit(a);
		n /= base;
	}
	if (EsteNeg)
	{
		c[i++] = '-';
	}
	c[i] = '\0';
	for (int j = 0; j < i / 2; j++)
	{
		char aux = c[j];
		c[j] = c[i - j - 1];
		c[i - j - 1] = aux;
	}
	return c;
}
int Number::normaliseDigit(char c)
{
	return c >= 'A' ? c - 'A' + 10 : c - '0';
}
char Number::formalizeDigit(int n)
{
	return n >= 10 ? 'A' + (n - 10) : '0' + n;
}
char* toString(long long n)
{
	char* c = new char[50];
	int i = 0;
	bool a = false;
	if (n < 0)
	{
		n = -n;
		a = true;
	}
	while (n != 0)
	{
		int b = n % 10;
		c[i++] = '0' + b;
		n /= 10;
	}
	if (a)
	{
		c[i++] = '-';
	}
	c[i] = '\0';
	for (int j = 0; j <= i / 2; j++)
	{
		char aux = c[j];
		c[j] = c[i - j - 1];
		c[i - j - 1] = aux;
	}
	return c;
}

void copyString(char*a, char*b)
{
	b = new char[strlen(a)];
	for (int i = 0; a[i] != '\n'; i++)
		b[i] = a[i];
}
long long Number::GetBaseTen()
{
	long long n = convertToBaseTen(valoare, baza);
	return Number::EsteNeg ? -n : n;
}