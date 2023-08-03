#ifndef STACK_H
#define STACK_H

// Define max size of stack
#define MAX_SIZE 100

// Structure to represent stack
typedef struct {
    int data[MAX_SIZE];
    int top;
}
    Stack;

    // function prototypes
void init(Stack* stack);
int is_empty(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack, int item); 
int pop(Stack* stack);

#endif // STACK-H