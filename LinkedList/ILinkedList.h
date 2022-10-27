#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H
template <typename T>
class ILinkedList
{
public:
	virtual T getFirst() = 0;
	virtual T getLast() = 0;
	virtual void print() = 0;
	virtual bool isEmpty() = 0;
	virtual void insert(const T& value) = 0;
	virtual void insertBefore(const T& value, const T& whereToInsert) = 0;
	virtual void insertAfter(const T& value, const T& whereToInsert) = 0;
	virtual size_t size() = 0;;
	virtual bool contains(const T& value) = 0;
	virtual T*& toArray() = 0;
	virtual ILinkedList<T>& reverse() = 0;
	virtual void operator=(const ILinkedList<T>& other) = 0;
};
#endif