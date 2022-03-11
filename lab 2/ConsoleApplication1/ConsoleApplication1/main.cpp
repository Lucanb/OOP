// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"GlobalFunctions.h";
int main()
{
    Luca a;
    char s[101];
    a.Init();
    a.setnume("Ion");
    a.setmath(6);
    a.seteng(7);
    a.sethist(9);
    a.print();
   std::cout << '\n';
    a.getnume(s);
   std :: cout << s;
   //s-ul nu l afiseaza!!!!
}