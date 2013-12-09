#include <assert.h>
#include <iostream>

#include "SinglyLinkedListOperations.h"

void testInsertInfront();
void testFind();
void testDeleteElement();
void testClear();

template <typename T>
void printList(LinkedListNode<T>* const head);

int main(){
	// Main will run some "unit tests"
	testInsertInfront();
	testFind();
	testDeleteElement();
	testClear();
	system ("pause");
	return 0;
}

// 2->3; insert 1 in front; obtain 1->2->3
void testInsertInfront(){
	std::cout << "Running testInsertInfront:" << std::endl;
	LinkedListNode<int> node1 = LinkedListNode<int>(1);
	LinkedListNode<int> node2 = LinkedListNode<int>(2);
	LinkedListNode<int> node3 = LinkedListNode<int>(3);
	node2.setNext(&node3);
	node3.setNext(NULL);
	// print the initial state
	LinkedListNode<int>* head = &node2;
	std::cout << "Initial list:" << std::endl;
	printList(head);
	// insert
	head = &SinglyLinkedListOperations<int>::insertInFront(head, 1); // now head will be the new head
	// print the final state
	std::cout << "Final list:" << std::endl;
	printList(head);
}

// 1->2->3; find(1) success; find(4) failure
void testFind(){
	std::cout << "\nRunning testFind: " << std::endl;
	LinkedListNode<int> node1 = LinkedListNode<int>(1);
	LinkedListNode<int> node2 = LinkedListNode<int>(2);
	LinkedListNode<int> node3 = LinkedListNode<int>(3);
	node1.setNext(&node2);
	node2.setNext(&node3);
	node3.setNext(NULL);
	LinkedListNode<int>* head = &node1;
	int searchKey2 = 4;
	try {
		LinkedListNode<int> node = SinglyLinkedListOperations<int>::find(head, 1);
		std::cout << "found 1 in the list!" << std::endl;
		LinkedListNode<int> node2 = SinglyLinkedListOperations<int>::find(head, 4);
	} catch (std::invalid_argument) {
		std::cout << "rerun the test with a proper head" << std::endl;
	} catch (SinglyLinkedListOperations<int>::NodeNotFound e) {
		std::cout << "node with data \'" << searchKey2 << "\' not in the list!" << std::endl;
	}
}

// 
void testDeleteElement(){

}

// 
void testClear(){

}

// helpers for printing
template <typename T>
void printList(LinkedListNode<T>* const head) {
	assert(head && "Head cannot be NULL");
	const LinkedListNode<T>* current = head;
	while(current) {
		std::cout << current->getData() << "|";
		current = current->getNext();
	}
	std::cout << std::endl;
}

template void printList<int>(LinkedListNode<int>* const head);