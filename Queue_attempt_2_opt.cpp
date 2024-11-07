#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
    Node *back; // Pointer to the previous node
};

template <class T>
class Stack
{
private:
    Node<T> *stackTop;
    Node<T> *stackBottom;

public:
    Stack();
    ~Stack();
    void push(const T &);
    T pop();
    T top();
    bool isEmpty();
};

template <class T>
Stack<T>::Stack()
{
    stackTop = nullptr;
    stackBottom = nullptr;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return stackTop == nullptr;
}

template <class T>
void Stack<T>::push(const T &e)
{
    Node<T> *addedNode = new Node<T>;
    assert(addedNode); 
    addedNode->data = e;
    addedNode->next = nullptr;
    addedNode->back = nullptr;

    if (this->isEmpty()) //stack is empty
    {
        stackTop = addedNode;    
        stackBottom = addedNode;
    }
    else
    {
        addedNode->next = stackBottom; 
        stackBottom->back = addedNode; 
        stackBottom = addedNode;     
    }
}

template <class T>
T Stack<T>::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty" << endl;
        return T();  
    }

    T e = stackTop->data;
    Node<T> *delNode = stackTop;

    if (stackTop == stackBottom) // Only 1 node
    {
        stackTop = nullptr;
        stackBottom = nullptr;
    }
    else
    {
        stackTop = stackTop->back;
        if (stackTop) {
            stackTop->next = nullptr;
        }
    }

    delete delNode;             
    return e;                   
}

template <class T>
T Stack<T>::top()
{
    if (!isEmpty())
    {
        return stackTop->data;
    }
    cout << "Stack is empty" << endl;
    return T(); 
}

template <class T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template <class T>
class Queue
{
private:
    Stack<T> s1;

public:
    void enqueue(T elem);
    T dequeue();
    bool isEmpty();
};

template <class T>
void Queue<T>::enqueue(T elem)
{
    s1.push(elem);
}

template <class T>
T Queue<T>::dequeue()
{
    if (!s1.isEmpty()) {
        return s1.pop();
    }
    cout << "Queue is empty" << endl;
    return T(); 
}

template <class T>
bool Queue<T>::isEmpty()
{
    return s1.isEmpty();
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
