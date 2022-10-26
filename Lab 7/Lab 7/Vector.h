#pragma once

template<class T>
class Vector
{
	T v[100];
	int Last_Pos;
public:
	int GetLast();
	void Push(T);
	int Pop();
	void GetElement(int x);
	void Delete(int x);
	void Insert(int x,int val);
	void Sort(bool (*fun)(T&, T&));
	int FirstIndexOf(T&, bool (*function)(T&, T&) = nullptr);
};
//Mai am;
