#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node *next;
};
template <class T>
class Stack
{
private:
	Node<T> *stackTop;

public:
	Stack();
	~Stack();
	void push(const T &);
	T pop();
	T top();
	bool isEmpty();
	void printStack() const;
};

template <class T>

Stack<T>::Stack()
{
	stackTop = NULL;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return stackTop == NULL;
}
template <class T>
void Stack<T>::push(const T &e)
{
	Node<T> *addedNode = new Node<T>;
	assert(addedNode);
	addedNode->data = e;
	addedNode->next = stackTop;
	stackTop = addedNode;
}
template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
		return 0;
	assert(stackTop);
	T e = stackTop->data;
	Node<T> *delNode = stackTop;
	stackTop = stackTop->next;
	delete delNode;
	return e;
}
template <class T>
T Stack<T>::top()
{
	return stackTop->data;
}
template <class T>
Stack<T>::~Stack()
{
	for (Node<T> *p; !isEmpty();)
	{
		p = stackTop->next;
		delete stackTop;
		stackTop = p;
	}
}
template <class T>
class Queue
{
private:
	Stack<T> s1;
	Stack<T> s2;

public:
	void enqueue(T elem);
	T dequeue();
};

template <class T>
void Queue<T>::enqueue(T elem)
{
	while (!s2.isEmpty())
		s1.push(s2.pop());
	s1.push(elem);
}

template <class T>
T Queue<T>::dequeue()
{
	while (!s1.isEmpty())
		s2.push(s1.pop());

	if (s2.isEmpty())
		cout << "Queue is empty" << endl;

	return s2.pop();
}


int main()
{
	Queue<int> q1;
	q1.enqueue(15);
	q1.enqueue(20);
	q1.enqueue(30);

	cout << "Dequeued: " << q1.dequeue() << endl; // 15
	cout << "Dequeued: " << q1.dequeue() << endl; // 20

	q1.enqueue(100);
	q1.enqueue(90);

	cout << "Dequeued: " << q1.dequeue() << endl; // 30
	cout << "Dequeued: " << q1.dequeue() << endl; // 100
	return 0;
}