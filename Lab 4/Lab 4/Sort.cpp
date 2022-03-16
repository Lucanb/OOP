#include "Sort.h"
#include<iostream>
#include<cstdlib>
#include <stdarg.h>

void Sort::swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}
Sort::Sort(int min, int max, int n)
{
	int dif = max - min + 1;
	this->n = n;
	v = new int[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = min + rand() % dif;
	}
}

Sort::Sort(int* v, int n)
{
	this->n = n;
	this->v = v;
}

Sort::Sort(int n, ...)
{
	va_list k;
	va_start(k, n);
	v = new int[n];
	for (int i = 1; i <= n; i++)
	{
		int a = va_arg(k, int);
		v[i-1] = a;
	}
	va_end(k);

}
 
Sort::Sort(const char* s)
{
	n = 0;
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] == ',')
			n++;
	n++;
	v = new int[n];

	int nr = 0;
	int i = 0;
	for (int j = 0; s[j] != '\0'; j++)
	{
		if (s[j] == ',')
		{
			v[i++] = nr;
			nr = 0;
			continue;
		}
		nr = nr * 10 + (s[j] - '0');

	}
	v[i++] = nr;
}

void Sort::BubbleSort(bool dec)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
	if (dec)
		back();
}

void Sort::InsertSort(bool dec)
{
	for (int i = 1; i < this->n; i++)
	{
		int aux = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > aux)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}
	if (dec)
	{
		back();
	}
}

int Sort::part(int st, int dr)
{
	int p = v[dr];
	int i = st - 1;
	for (int j = st; j <= dr - 1; j++)
		if (v[j] < p)
		{
			i++;
			swap(v[i], v[j]);
		}
	swap(v[i + 1], v[dr]);
	return i + 1;
}
void Sort::qSort(int st, int dr)
{
	if (st < dr)
	{
		int m = part(st, dr);
		qSort(st, m - 1);
		qSort(m + 1, dr);
	}
}
void Sort::QuickSort(bool dec)
{
	this->qSort(0, n - 1);
	if (dec)
	{
		back();
	}
}

//int value = ascendent ? n1 - n2 : n2 - n1;
///if (value < 0) { swap(); }

int Sort::GetElementsCount()
{
	return n;
}
int Sort::GetElementFromIndex(int i)
{
	return v[i];
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
		std::cout << GetElementFromIndex(i) << ' ';
	std::cout << '\n';
}

void Sort::back()
{
	for (int i = 0; i < n / 2; i++)
		this->swap(v[i], v[n - i + 1]);
}