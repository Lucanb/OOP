// Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

using namespace std;
int operator"" _Kelvin(long double x)
{
    x = x+273,5;
    return x;
}
int operator"" _Fahrenheit(long double x)
{
    x = x+ 33, 8;
    return x;
}
int main()
{
 
        float a = 300.00_Kelvin;//dar eu vreau 300
        float b = 120.00_Fahrenheit;//dar eu vreau 300
        std::cout << a << ' ' << b;

        Vector<int> k{};
}
