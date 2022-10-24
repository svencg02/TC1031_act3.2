#ifndef PRIORITY_QUEUE_1
#define PRIORITY_QUEUE_1

#include <iostream>

template <class T> class priority_queue;
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T value;
	Node<T> *prev, *next;

	friend class priority_queue<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), prev(NULL), next(NULL) {};


template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt) : value(val), prev(prev), next(nxt) {};

template <class T>
class priority_queue{
	private:
		Node<T> *head, *tail;
		int size;
	public:
		priority_queue(): head(NULL), tail(NULL), size(0){;};
		void push(int) ;
		void pop();
		int top() ;
		bool empty();
		int sizeq();
		int get_head();
		int get_tail();
		void printq(); 
};
template <class T>
bool priority_queue<T>::empty(){
	return(head == NULL);
}

template <class T>
int priority_queue<T>::sizeq(){
	return size;
}

template <class T>
int priority_queue<T>::get_head(){
	return head->value;
}

template <class T>
int priority_queue<T>::get_tail(){
	return tail->value;
}

template <class T>
void priority_queue<T>::push(int val) {
	Node<T> *nodo, *actual, *aux;
	nodo = new Node<T>(val);
	if (empty()){
		head = nodo;
		tail = nodo;
		size++;
		return;
	}

	if (val >= head->value){
		nodo->next = head;
		head->prev = nodo;
		head = nodo;
		size++;
		return;
	}

	if (val <= tail->value){
		nodo->prev = tail;
		tail->next = nodo;
		tail = nodo;
		size++;
		return;
	}

	actual = head;

	while (actual != NULL)
	{
		if (actual->value <= val)
		{
			break;	
		}
		actual = actual->next;
	}
	aux = actual->prev;
	nodo->next = actual;
	nodo->prev = aux;
	aux->next = nodo;
	actual->prev = nodo;
	size++;
};

template <class T>
void priority_queue<T>::pop(){
	head = head->next;	
}

template <class T>

int priority_queue<T>::top() {
	return head->value;
}

template <class T>
void priority_queue<T>::printq(){
	Node<T> *p;
	p = head;
	while (p->next != NULL)
	{
		std::cout << p->value << std::endl; 
		p = p->next;
	}

	
}


#endif