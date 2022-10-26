#include "Node.h"

template<class K, class V>
Node<K, V>::Node(unsigned long k)
{
}

template<class K, class V>
Node<K, V>::Node(unsigned long k, K Key, V Value)
{
}

template<class K, class V>
Node<K, V>::~Node()
{
	if (next != nullptr)
		delete next;
}

template<class K, class V>
void Node<K, V>::operator=(V Value)
{
	this->Value = Value;
}
