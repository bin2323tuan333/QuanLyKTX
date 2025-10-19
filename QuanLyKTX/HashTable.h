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