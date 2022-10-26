#pragma once
#include"Node.h"
template<class K, class V>
struct Data {
	K key;
	V value;
	int index;
};

template<class K,class V>
class Iterrator
{
public:
	Node<K, V>** elemente;
	int MaxLung;
	int end;
	int i = 0;
	Iterrator(int MaxLung, int end, Node<K, V>** el) : MaxLung(MaxLucng), end(end), elemente(el) {}
	Iterrator& operator++();
	Data<K, V> operator* ();
	bool operator != (const Iterrator it);

};

