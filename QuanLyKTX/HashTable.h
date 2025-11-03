#pragma once
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_CAPACITY = 101;

template <typename Key, typename Value>
class HashNode
{
public:
    Key key;
    Value value;
    HashNode<Key, Value>* next;

    HashNode(const Key&, const Value&);
    ~HashNode();
};


template <typename Key, typename Value>
class HashTable {
private:
    HashNode<Key, Value>** table;
    int capacity;

    int hashFunction(const Key&);
public:
    HashTable(int = DEFAULT_CAPACITY);
    ~HashTable();

    void insert(const Key&, const Value&);
    Value* search(const Key&);
    void remove(const Key&);
};


#include "HashTable.h"
#include <iostream>



template <typename Key, typename Value>
HashNode<Key, Value>::HashNode(const Key& key, const Value& value)
	:key(key), value(value), next(nullptr)
{
}
template <typename Key, typename Value>
HashNode<Key, Value>::~HashNode()
{

}

template <typename Key, typename Value>
int HashTable<Key, Value>::hashFunction(const Key& key)
{
	return abs(int(key)) % this->capacity;
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(int size)
	: capacity(size)
{
	this->table = new HashNode<Key, Value>*[this->capacity];
	for (int i = 0; i < this->capacity; ++i)
		this->table[i] = nullptr;
}

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable()
{
	for (int i = 0; i < this->capacity; ++i)
	{
		HashNode<Key, Value>* current = this->table[i];
		HashNode<Key, Value>* nextNode;
		while (current != nullptr)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}
	delete[] this->table;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value)
{
	Value* valueNode = search(key);
	if (valueNode != nullptr)
	{
		*valueNode = value;
		return;
	}

	int index = hashFunction(key);

	HashNode<Key, Value>* temp = new HashNode<Key, Value>(key, value);
	temp->next = *(this->table + index);
	*(this->table + index) = temp;
}

template <typename Key, typename Value>
Value* HashTable<Key, Value>::search(const Key& key)
{
	int index = hashFunction(key);
	HashNode<Key, Value>* current = *(this->table + index);
	while (current != nullptr)
	{
		if (current->key == key)
			return &(current->value);
		current = current->next;
	}
	return nullptr;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::remove(const Key& key)
{
	int index = hashFunction(key);
	HashNode<Key, Value>* current = *(this->table + index);
	HashNode<Key, Value>* previous = nullptr;
	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (previous == nullptr)
			{
				this->table[index] = current->next;
			}
			else
			{
				previous->next = current->next;
			}
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
}