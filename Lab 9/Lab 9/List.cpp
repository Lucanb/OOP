#include "List.h"

template<class K, class V>
void List<K, V>::add(Node<K, V>* nod)
{
	nod->next = nullptr;
	if (root == nullptr)
	{
		root = node;
		head = node;
		Lung++;
	}
	head->next = nod;
	head = head->next;
	Lung++;
}
template<class K, class V>
List<K, V>::List()
{
	root = nullptr;
	head = nullptr;
	Lung = 0;
}
template<class K, class V>
List<K, V>::~List()
{
	delete root;
}
