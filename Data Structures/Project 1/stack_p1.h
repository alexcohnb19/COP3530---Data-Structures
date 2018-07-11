/* stack_p1_h */

//
//  stack_p1.h
//
//
//  Created by Resch,Cheryl on 5/30/18.
//
#ifndef stack_p1_h
#define stack_p1_h
template <typename T>
class stack_p1{
	private:
		struct node{
			T value;
			node* prev;
		};

		node* top;
	public:
		stack_p1();
		bool isEmpty();
		T pop();
		void push(T item);
		T peek();
};
#endif /* stack_p1_h */
