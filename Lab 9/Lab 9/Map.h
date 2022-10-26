#pragma once
#include"Iterrator.h"
#include"List.h"
#include"Map.h"
#include"Node.h"
using namespace std;

template<class K,class V>
class Map
{
private:
	int Lung;
	int Cap;
	List<K, V>* container;
	Node<K, V>** Elemente;
	hash<K> GetHash;
public:
	Map();
	void Set(K, V);
	bool Get(const K& key, V& value);
	int Count();
	void Delete(const K);
	void Clear();
	bool Includes(const Map<K, V>& map);
	
	Node<K,V>& operator[] (K);
	Iterrator<K,V> begin();
	Iterrator<K,V> end();
};


