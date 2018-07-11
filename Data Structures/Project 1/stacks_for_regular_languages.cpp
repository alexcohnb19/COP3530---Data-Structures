#include<iostream>
#include "stack_p1.cpp"
#include "stacks_for_regular_languages.h"
#include <string.h>
	
	//L2 Needs to check for NON A or B
	//L3 Needs to Check for single instances
	
	//L1
	bool stacks_for_regular_languages::L1 (char* inputString){
		stack_p1<char> stk;//Declare Stack
		
		int n = strlen(inputString); //Length of inputString
		
		for(int i = 0; i < n; i++){
			if(stk.isEmpty()){
				stk.push(inputString[i]);//Decides the first Char
			}else if(stk.peek() == inputString[i]){
				stk.push(inputString[i]);
			}else{
				stk.pop();
			}
		}

		if(stk.isEmpty()){
			return true;
		}else{
			return false;
		}
	}
	
	//L2
	bool stacks_for_regular_languages::L2 (char* inputString){
		stack_p1<char> stk;//Declare Stack
		
		int n = strlen(inputString); //Length of inputString
		bool isB = false;
		
		for(int i = 0; i < n; i++){
			if((inputString[i] != 'A') || (inputString[i] != 'B')){
				return false;
			}else if(isB && inputString[i] == 'A'){//A appears after a B
				return false;
			}else if(!isB && inputString[i] == 'B'){//First Instance of B && isB = TRUE
				isB = true;
				stk.pop();
			}else if(!isB && inputString[i] == 'A'){//Adding A
				stk.push(inputString[i]);
			}else{								//Pops B
				if(!stk.isEmpty()){
					stk.pop();
				}else{
					return false;
				}
			}
		}
		if(stk.isEmpty()){//Returns True if #A's == #B's
			return true;
		}else{
			return false;
		}
	}

	//L3
	bool stacks_for_regular_languages::L3(char* inputString){
		stack_p1<char> stk1;
		stack_p1<char> stk2;
		stack_p1<char> stkCompare;//Used to make sure m == n
		
		int pos;
		int n =  strlen(inputString);//Length of inputString
		bool isB = false;
		
		for(pos = 0; pos < n; pos++){
			if((inputString[i] != 'A') || (inputString[i] != 'B')){
				return false;
			}else if((inputString[pos] == 'A') && isB){//Repeat Condition
				break;
			}else if(!isB && inputString[pos] == 'B'){//B Section && isB = True
				isB = true;
				stk1.push(inputString[pos]);
				if(!stkCompare.isEmpty()){
					stkCompare.pop();
				}else{
					return false;
				}
			}else if(!isB && inputString[pos] == 'A'){//A Section
				stk1.push(inputString[pos]);
				stkCompare.push(inputString[pos]);
			}else{									//B Section Cont.
				stk1.push(inputString[pos]);
				if(!stkCompare.isEmpty()){
					stkCompare.pop();
				}else{
					return false;
				}
			}
		}
		
		while(!stk1.isEmpty()){//Reverses the Template
			stk2.push(stk1.pop());
		}
		stk1 = stk2;
		
		for(pos; pos < n; pos++){//Compares the rest of the string to the template
			if(stk1.isEmpty()){
				stk1 = stk2;
			}
			
			if(stk1.pop() != inputString[pos]){
				return false;
			}
		}
		
		if(stkCompare.isEmpty() && stk1.isEmpty()){
			return true;
		}else{
			return false;
		}
	}
	
	//L4
	bool stacks_for_regular_languages::L4 (char* inputString){
		stack_p1<char> stk1;
		stack_p1<char> stk2;
		
		int pos;
		int n =  strlen(inputString);
		bool isB = false;
		
		for(pos = 0; pos < n; pos++){//Creates the Template
			if((inputString[pos] == 'A') && isB){//Stops adding to template when an A appears after B
				break;
			}else if(!isB && inputString[pos] == 'B'){//First Instance of B
				isB = true;
				stk1.push(inputString[pos]);
			}else if(!isB && inputString[pos] == 'A'){//Adds A
				stk1.push(inputString[pos]);
			}else{										//Pops B
				stk1.push(inputString[pos]);
			}
		}
		
		while(!stk1.isEmpty()){
			stk2.push(stk1.pop());
		}
		stk1 = stk2;
		
		for(pos; pos < n; pos++){
			if(stk1.isEmpty()){
				stk1 = stk2;
			}
			
			if(stk1.pop() != inputString[pos]){
				return false;
			}
		}
		
		if(stk1.isEmpty()){
			return true;
		}else{
			return false;
		}	
	}
	
	
