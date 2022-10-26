#include "Vector.h"
#include <iostream>
template<class T>
int Vector<T>::GetLast()
{
	return Last_Pos;
}

template<class T>
void Vector<T>::Push(T x)
{
	if (x >= 0 && x < GetLast())
	{
		v[Last_Pos] = x;
		Last_Pos++;
	}
	else
		std::cout << "Erorr!";
}

template<class T>
int Vector<T>::Pop()
{
	if (GetLast() > 0)
	{
		int a = v[GetLast() - 1];
		v[GetLast() - 1] = v[GetLast()];
		Last_Pos--;
		return a;
	}
	else
		return -1;
}

template<class T>
void Vector<T>::GetElement(int x)
{
	if (x >= 0 && x < GetLast())
		return v[x];
	else
		std::cout << "Eroare";
}

template<class T>
void Vector<T>::Delete(int x)
{
	if (x >= 0 && x < GetLast())
	{
		for (int i = GetLast(); i > x; i--)
			v[i - 1] = v[i];
	}
	else
		std::cout << "Eroare";
}

template<class T>
void Vector<T>::Insert(int x, int val)
{
	if (x >= 0 && x < GetLast())
	{
		for (int i = GetLast(); i >= x; i--)
			v[i] = v[i - 1];
		v[x] = val;
	}
	else
		std::cout << "Eroare";
}

template<class T>
void Vector<T>::Sort(bool (*function)(T&, T&))
{

	for (int i = 0; i < GetLast() - 1; i++) {
		for (int j = 0; j < GetLast() - i - 1; j++) {
			if (function == nullptr) {
				if (v[j] < v[j + 1] == false) {
					T aux = v[j];
					v[j] = v[j + 1];
					v[j + 1] = aux;
				}
			}
			else {
				bool r = function(v[j], v[j + 1]);
				if (!r) {
					T aux = v[j];
					v[j] = v[j + 1];
					v[j + 1] = aux;
				}

			}
		}
	}
}
template<class T>
int Vector<T>::FirstIndexOf(T& a, bool(*function)(T&, T&))
{
	for (int i = 0; i < GetLast(); i++) {
		if (function == nullptr) {
			if (a == v[i]) {
				return i;
			}
		}
		else {
			bool b = function(v[i], a);

			if (b) {
				return i;
			}
		}
	}
	return -1;
}
