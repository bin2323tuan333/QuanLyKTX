#pragma once


template<typename Value>
class ListNode
{
public:
	Value value;
	ListNode<Value>* next;
	ListNode();
	ListNode(const Value&);
	~ListNode();

	ListNode<Value>* getNext();
};

template<typename Value>
class LinkedList
{
private:
	ListNode<Value>* head;
	ListNode<Value>* tail;
	int size;
public:
	LinkedList();
	LinkedList(const LinkedList<Value>&);
	LinkedList<Value>& operator=(const LinkedList<Value>&);
	~LinkedList();

	bool isEmpty();
	int getSize();
	void clear();
	Value* getAt(int);
	ListNode<Value>* getHead();
	

	void add(const Value&);
	bool remove(const Value&);
	Value* search(const Value&);
};



template<typename Value>
ListNode<Value>::ListNode()
	:next(nullptr)
{
}
template<typename Value>
ListNode<Value>::ListNode(const Value& value)
	: value(value), next(nullptr)
{
}
template<typename Value>
ListNode<Value>::~ListNode()
{
}

template<typename Value>
ListNode<Value>* ListNode<Value>::getNext()
{
	return this->next;
}

template<typename Value>
LinkedList<Value>::LinkedList()
	:head(nullptr), tail(nullptr), size(0)
{
}
template<typename Value>
LinkedList<Value>::LinkedList(const LinkedList<Value>& other)
{
	this->head = this->tail = nullptr;
	this->size = 0;
	ListNode<Value>* current = other.head;
	while (current != nullptr) 
	{
		this->add(current->value);
		current = current->next;
	}
}

template<typename Value>
LinkedList<Value>& LinkedList<Value>::operator=(const LinkedList<Value>& other)
{
	if (this == &other)
		return *this;

	this->clear();
	this->head = this->tail = nullptr;
	this->size = 0;
	ListNode<Value>* current = other.head;
	while (current != nullptr) {
		this->Add(current->value);
		current = current->next;
	}

	return *this;
}
template<typename Value>
LinkedList<Value>::~LinkedList()
{
	this->clear();
}

template<typename Value>
bool LinkedList<Value>::isEmpty()
{
	return this->head == nullptr;
}
template<typename Value>
int LinkedList<Value>::getSize()
{
	return this->size;
}
template<typename Value>
void LinkedList<Value>::clear()
{
	ListNode<Value>* current = this->head;
	while (current != nullptr)
	{
		ListNode<Value>* nodeToDelete = current;
		current = current->next;
		delete nodeToDelete;
	}
	this->head = this->tail = nullptr;
	this->size = 0;
}

template<typename Value>
void LinkedList<Value>::add(const Value& value)
{
	ListNode<Value>* newNode = new ListNode<Value>(value);

	if (this->isEmpty())
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		this->tail->next = newNode;
		this->tail = newNode;
	}
	this->size++;
}

template<typename Value>
Value* LinkedList<Value>::search(const Value& val)
{
	ListNode<Value>* current = this->head;
	while (current != nullptr)
	{
		if (current->value == val)
			return &(current->value);
		current = current->next;
	}
	return nullptr;
}

template<typename Value>
bool LinkedList<Value>::remove(const Value& value)
{
	ListNode<Value>* current = this->head;
	ListNode<Value>* previous = nullptr;

	while (current != nullptr && current->value != value)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr) return false;
	if (previous == nullptr)
	{
		this->head = current->next;
		if (this->head == nullptr) this->tail = nullptr;
	}
	else
	{
		previous->next = current->next;
		if (previous->next == nullptr)
			this->tail = previous;
	}
	(this->size)--;
	delete current;
	return true;
}

template<typename Value>
Value* LinkedList<Value>::getAt(int index)
{
	if (index < 0 || index >= this->size)
		return nullptr;
	ListNode<Value>* current = this->head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return &(current->value);
}

template<typename Value>
ListNode<Value>* LinkedList<Value>::getHead()
{
	return this->head;
}