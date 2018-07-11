#include "stack_p1.h"

using namespace std;

template <typename T>
stack_p1<T>::stack_p1(){
	top = NULL;
}

template <typename T>
bool stack_p1<T>::isEmpty(){
	if(top == NULL){
		return true;
	}else{
		return false;
	}
}

template <typename T>
T stack_p1<T>::pop(){
	if(!isEmpty()) {
		node* n = new node;
		T temp = top->value;

		n = top;
		top = n->prev;
		delete n;
		return temp;
	}
	else {
		throw std::runtime_error("stack_p1<T>.pop(): Popping empty stack");
	}
}

template <typename T>
void stack_p1<T>::push(T item){
	node* n = new node;
	n->value = item;
	n->prev = NULL;

	if(top == NULL){
		top = n;
	}
	else {
		n->prev = top;
		top = n;
	}
}

template <typename T>
T stack_p1<T>::peek(){
	if(!isEmpty()){
		return top->value;
	}else{
		throw std::runtime_error("stack_p1<T>.peek(): Peeking Empty Stack");
	}
	
}
