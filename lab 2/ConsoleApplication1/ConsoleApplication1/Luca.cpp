#include "Luca.h"
#include<cstring>
#include<iostream>
using namespace std;
void Luca::getnume(char s[101])
{
	strcpy(s, Luca::nume); ///de revizuit
}

float Luca::getmath()
{
	float x = notamath;
	return x;
}
float Luca::geteng()
{
	float x = notaeng;
	return x;
}
float Luca::gethist()
{
	float x = notahist;
	return x;
}
bool Luca::setmath(float x)
{
      if(x<=10 && x>=1)
	  {  
		  notamath = x;
		  return true;
      }
	  return false;
}
bool Luca::seteng(float x)
{
	if (x <= 10 && x >= 1)
	{
		notaeng = x;
		return true;
	}
	return false;
}
bool Luca::sethist(float x)
{
	if (x <= 10 && x >= 1)
	{
		notahist = x;
		return true;
	}
	return false;
}
float Luca::avgMedia()
{
	float x = (notaeng + notamath + notahist) / 3;
	return x;
}
void Luca::print()
{
	std::cout << geteng();
	std::cout << getmath();
	std::cout << gethist();

}
void Luca::setnume(const char s[101])
{
	strcpy(nume, s);
}
void Luca::Init()
{
	nume[14] = { '\0' };
	notamath = 0;
	notaeng = 0;
	notahist = 0;
}