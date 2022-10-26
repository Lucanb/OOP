#pragma once
#include"Node.h"
template<class K,class V>
class List
{
	Node<K, V>* root;
	Node<K, V>* head;
	int Lung;
	List();
	void add(Node<K, V>* nod);
	~List();
};
