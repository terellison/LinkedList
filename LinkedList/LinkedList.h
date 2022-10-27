#include "ILinkedList.h"
#include "Node.h"
#include <iostream>
template <typename T>
class LinkedList : ILinkedList<T>
{
public:

	LinkedList<T>::LinkedList()
	{
		this->head = this->tail = NULL;
		this->count = 0;
	}
	// Inherited via ILinkedList
	virtual T getFirst() override
	{
		return this->head->element;
	}
	virtual T getLast() override
	{
		return this->tail->element;
	}
	virtual void print() override
	{
		Node<T>* temp = this->head;
		std::cout << std::endl;
		while (temp != NULL)
		{
			std::cout << temp->element << " ";
		}
	}
	virtual bool isEmpty() override
	{
		return this->head == NULL;
	}
	virtual void insert(const T& value) override
	{
		Node<T>* temp = new Node<T>();
		temp->element = value;

		if (this->head == NULL)
		{
			this->head = this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			this->tail = temp;
		}

		++this->count;
	}
	virtual void insertBefore(const T& value, const T& whereToInsert) override
	{
	}
	virtual void insertAfter(const T& value, const T& whereToInsert) override
	{
	}
	virtual size_t size() override
	{
		return this->count;
	}
	virtual bool contains(const T& value) override
	{
		Node<T>* temp = this->head;

		while (temp != NULL)
		{
			if (temp->element == value)
			{
				return true;
			}
		}

		return false;
	}
	virtual T*& toArray() override
	{
		T* value = new T[this->count];

		Node<T>* temp = this->head;

		for (size_t i = 0; i < this->count && temp != NULL; ++i)
		{
			value[i] = temp->element;
			temp = temp->next;
		}

		return value;
	}
	virtual ILinkedList<T>& reverse() override
	{
		// TODO: insert return statement here
	}
	virtual void operator=(const ILinkedList<T>& other) override
	{
	}

private:
	Node<T>* head;
	Node<T>* tail;
	size_t count;
};