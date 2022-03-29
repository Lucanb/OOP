#pragma once

class Number
{
	char* valoare;
	int baza;
	bool EsteNeg;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
 
	Number(const Number& n);
	Number(const Number&& n);
	Number(const int n);
	// add operators and copy/move constructor

	char operator[] (int i); //
	
	friend Number operator+ (const Number& x,const Number& y);
	friend Number operator- (const Number& x,const Number& y);

	bool operator> (Number& n);
	void operator= (const char*);
	void operator= (const Number& n);
	void operator= (int n);
	void operator+= (Number& n);
	void operator-- ();
	void operator-- (int);


	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

	long long GetBaseTen();
	private :
		long long convertToBaseTen(char* s, int base);
		char* convertToBase(long long n, int base);
		int normaliseDigit(char c);
		char formalizeDigit(int n);
};

char* toString(long long);
void copyString(char*, char*);
