#include<stdio.h>
#include "stack.h"

int main(){
	Stack myStack;
	init(&myStack);
	
	//push elements onto the stack
	push(&mystack, 10);
	push(&mystack, 20);
	push(&mystack, 30);
	
	// pop elements from the stack and print them
	while(!is_empty(&myStack)) {
		int item =pop(&myStack);
		printf("%d",item);
	
	}
	return 0;
}
