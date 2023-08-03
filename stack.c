#include<stdio.h>
#include "stack.h"

// INITIALIZE THE STACK
void init(Stack* stack) {
    stack->top = -1;
}

// check if stack is empty
int is_empty(Stack* stack) {
    return stack->top == -1;
}

// check if stack is full
int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// push item onto stack
void push(Stack* stack, int item) {
    if (!is_full(stack)) {
        stack->top++;
        stack->data[stack->top] = item;
    } else {
        // Handle stack overflow error here(optional)
    }
}

// pop an item from stack
int pop(Stack* stack) {
    if (!is_empty(stack)) {
        int item = stack->data[stack->top];\
        stack->top--;
        return item;
    } else {
        // handle stack overflow error(opt)
        return -1; // can choose to return specific error value 
    }
}