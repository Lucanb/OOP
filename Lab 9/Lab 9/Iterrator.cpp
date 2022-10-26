#include "Iterrator.h"
template<class K, class V>
Iterrator<K,V>& Iterrator<K, V>::operator++()
{
	i++;
	return *this;
}

template<class K, class V>
Data<K, V> Iterrator<K, V>::operator*()
{
	Data<K, V>d = {
		elemente[i]->key;
	    elemente[i]->value;
		elemente[i]->k% MaxLung;

	}
	return d;
}

template<class K, class V>
bool Iterrator<K, V>::operator!=(const Iterrator it)
{
	return i < end;
}
