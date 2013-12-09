#include "LinkedListNode.h"
#include "stdlib.h"
#include <exception>
#include <stdexcept>

template<typename T>
class SinglyLinkedListOperations {
public:
	// This is the more C++ ish way to insert in front. The return
	// value is not an error code, There is no need for an error code
	// as C++ can throw exceptions in the event of erroneous conditions
	static LinkedListNode<T>& insertInFront(LinkedListNode<T>* oldHead, const T& data);

	// Finds and returns a node with a given data element
	static LinkedListNode<T>& find(LinkedListNode<T>* head, const T& data);

	// returns true if the element is deleted. You need to pass in the reference (or pointer)
	// to the head pointer, because you may need to update the head if the head is to be deleted
	static bool deleteElement(LinkedListNode<T>*& head, const T& data);

	// clear all list elements, it is a good practice to update the head pointer to NULL
	// after clearing. Theat is why you need to pass the reference (or pointer) to head
	static void clear(LinkedListNode<T>*& head);

	// Custom exception to throw if we do not find an element in the list
	class NodeNotFound : public std::exception {
      virtual const char* what() const throw() override {
               return "Node not found in the list!";
      }
	};
};

