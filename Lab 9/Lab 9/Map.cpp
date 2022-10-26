#include "Map.h"
template<class K, class V>
Map<K, V>::Map()
{
	Lung = 0;
	Cap = 1000;
	container = new List<K, V>[Cap];
	Elemente = new Node<K, V>[Cap];

}

template<class K, class V>
void Map<K, V>::Set(K key, V value)
{
	if (Lung + 1 > Cap)
		Resize();
	unsigned long keya = getHash(key);
	int indexKey = (int)(keya % Cap);
	Node<K, V>* NewNode = new Node<K, V>(keya, value, key);
	container[indexKey].add(NewNode);
	Lung++;
}

template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	return false;
}

template<class K, class V>
int Map<K, V>::Count()
{
	return Lung;
}

template<class K, class V>
void Map<K, V>::Delete(const K)
{
	int keya = getHash(key);
	int indexKey = rawKey % capacity;

	Node<K, V>* temp = container[indexKey].root;

	while (temp != nullptr) {
		if (temp->next != nullptr && temp->next->keya == keya) {
			temp->next = temp->next->next;
			temp->next->next = nullptr;
			delete temp->next;
			Lung--;
			return;
		}
		temp = temp->next;
	}
}
	template<class K, class V>
	void Map<K, V>::Clear()
	{
		delete[]container;
		Cap = 1000;
		container = new List<K, V >[Cap];
		Elemente = new Node<K, V>*[Cap];
		Lung = 0;
	}

	template<class K, class V>
	bool Map<K, V>::Includes(const Map<K, V>& map)
	{
		int nr = 0;
		for (auto [indexA, keyA, valueA] : m) {
			for (auto [indexB, keyB, valueB] : *this) {
				if (keyA == keyB && valueA == valueB) {
					nr++;
				}
			}
		}
		return nr == m.Count();
	}


template<class K, class V>
Node<K, V>& Map<K, V>::operator[](K)
{
	unsigned long rawKey = getHash(key);
	int indexKey = (int)(rawKey % capacity);

	// check for duplicate key
	Node<K, V>* temp = container[indexKey].root;
	while (temp != nullptr) {
		if (temp->keya == keya) {
			return *temp;
		}
		temp = temp->next;
	}

	if (Lung + 1 >= Cap) {
		Resize();
	}

	Node<K, V>* n = new Node<K, V>();
	n->rawKey = rawKey;
	n->key = key;

	container[indexKey].add(n);
	Lung++;

	return *n;
}

template<class K, class V>
Iterrator<K, V> Map<K, V>::begin()
{
	Elemente = new Node<K, V>*[Cap];

	int l = 0;
	for (int i = 0; i < Cap; i++) {
		Node<K, V>* temp = container[i].root;
		while (temp != nullptr) {
			Elemente[l++] = temp;
			temp = temp->next;
		}
	}

	Iterrator<K, V> it(Cap, Lung,Elemente);
	return it;
}

template<class K, class V>
Iterrator<K, V> Map<K, V>::end()
{
	Iterrator<K, V> it(Cap, Lung, Elemente);
	return it;
}


