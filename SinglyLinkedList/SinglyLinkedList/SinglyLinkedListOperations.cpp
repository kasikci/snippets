#include "SinglyLinkedListOperations.h"

template<typename T>
LinkedListNode<T>& SinglyLinkedListOperations<T>::insertInFront(LinkedListNode<T>* oldHead, const T& data) {
		LinkedListNode<T>* newHead = new LinkedListNode<T>(data);
		newHead->setNext(oldHead);
		return *newHead;
}

template<typename T>
LinkedListNode<T>& SinglyLinkedListOperations<T>::find(LinkedListNode<T>* head, const T& data){
	if(!head)
		throw std::invalid_argument("The head pointer can't be null");
	LinkedListNode<T>* iterator = head;
	while(iterator) {
		if(data == iterator->getData())
			return *iterator;
		iterator = iterator->getNext();
	}
	throw NodeNotFound();
}

template<typename T>
bool SinglyLinkedListOperations<T>::deleteElement(LinkedListNode<T>*& head, const T& data) {
	if(!head)
		throw std::invalid_argument("The head pointer can't be null");
	// if the item is the head, remove it and update the head
	LinkedListNode<T>* current = head;
	if(current->getData() == data) {
		head = current->getNext();
		delete current;
		return true;
	}
	// if not, iterate until you find the item, remember the previous item 
	do {
		LinkedListNode<T>* previous = current;
		current = current->getNext();
		if(current->getData() == data) {
			previous->setNext(current->getNext());
			delete current;
			return true;
		}
	} while(current);
	return false;
}

template<typename T>
void SinglyLinkedListOperations<T>::clear(LinkedListNode<T>*& head) {
	if(!head)
		throw std::invalid_argument("The head pointer can't be null");
	LinkedListNode<T>* current = head;	
	while(current) {
		LinkedListNode<T>* next = head->getNext();
		delete current;
		current = next;
	}
	// it is helpful to set the head to null
	head = NULL;
}

// Template class instantitations
template class SinglyLinkedListOperations<int>;