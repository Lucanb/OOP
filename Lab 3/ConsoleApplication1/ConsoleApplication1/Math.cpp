#include "Math.h"
#include <cstdarg>
#include<cstring>
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
//
int Math :: Add(int count,...)
{
	int result = 0;
	std::va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}

static char* Add(const char* a, const char* b)
{
	return strcat(a, b);
}