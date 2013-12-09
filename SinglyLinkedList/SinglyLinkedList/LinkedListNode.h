#include <iostream>

template<typename T>
class LinkedListNode
{
	public:
		LinkedListNode(T value) : data(value), next(0) {}
		
		~LinkedListNode(){}
		
		// make the getter function const, it cannot modify any 
		// attribute except mutable ones.
		LinkedListNode* getNext() const {return next;}
		
		// return a reference to not copy the whole data
		// make sure it is read-only
		const T& getData() const {return data;}
		
		void setNext(LinkedListNode* _next){next = _next;} 
		
		// setter parameter is supposed to be a const reference
		void setData(const T& _data) {data = _data;}

		// here the implicit copy consturctor would do, 
		// but we'll still write it. It is important to have the
		// copied object and rhs of the assignment as const ref
		// because C++ won't allow to pass a temporary unnamed 
		// object as a non const referece parameter. 
		LinkedListNode(const LinkedListNode& copy);

		// another option for = is to pass by value for exception 
		// safety, but this is a complicated subject
		LinkedListNode& operator=(const LinkedListNode& rhs);

	private:
		T data;
		LinkedListNode* next;
};