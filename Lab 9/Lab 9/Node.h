#pragma once
template<class K,class V>
class Node
{
public:
	V Value;
	K Key;
	unsigned long keya;
	Node <K, V>* next = nullptr;
	Node(unsigned long k);
	Node(unsigned long k,K Key,V Value);
	Node(){};
	~Node();
	void operator =(V Value);
};

