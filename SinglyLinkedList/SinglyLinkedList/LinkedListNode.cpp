#include "LinkedListNode.h"

// here the implicit copy consturctor would do, 
// but we'll still write it. It is important to have the
// copied object and rhs of the assignment as const ref
// because C++ won't allow to pass a temporary unnamed 
// object as a non const referece parameter. 
template<typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode<T>& copy)
{
	data = copy.data;
	next = copy.next;
}

// another option for = is to pass by value for exception 
// safety, but this is a complicated subject
template<typename T>
LinkedListNode<T>& LinkedListNode<T>::operator=(const LinkedListNode<T>& rhs)
{
	data = rhs.data;
	next = rhs.next;
	return *this;
}

template class LinkedListNode<int>;