// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
	int v[10] = { 5,3,6,7,8,3,2,33,54,6 };
	Sort a(10, 30, 30);
	Sort b{ new int[8]{9,5,6,3,2,8,1,4},8 };
	Sort c(v, 10);
	Sort d(6,3,8,2,6,4,2,3,5);
	Sort e("43,6,7,68,96,5,4,34,45,345,3,2,54,6,5");

	cout << "Lungime :" << a.GetElementsCount() << '\n';
	a.InsertSort();
	a.Print();
	cout << '\n';

	cout << "Lungime :" << b.GetElementsCount() << '\n';
	b.QuickSort();
	b.Print();
	cout << '\n';


	cout << "Lungime :" << c.GetElementsCount() << '\n';
	c.BubbleSort();
	c.Print();
	cout << '\n';

	cout << "Lungime :" << d.GetElementsCount() << '\n';
	d.BubbleSort(true);
	d.Print();
	cout << '\n';

	cout << "Lungime :" << e.GetElementsCount() << '\n';
	e.QuickSort(true);
	e.Print();
	cout << '\n';

	return 0;
}