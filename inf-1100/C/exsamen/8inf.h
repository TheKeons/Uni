#ifndef INF_H_
#define INF_H_

struct stack;
typedef struct stack Stack;


// stack operations

int pop(Stack *stack); // returns the top of stack and removes it from stack

void push(Stack *stack, int value); // adds to top of stack

int top(Stack *stack);  // returns value on tho of stack

void print_top(Stack *stack);

void dup(Stack *stack); // pushes a duplicate of the top of the stack

void swap(Stack *stack);    // swaps the two top numbers of stakk

int is_full(Stack *stack);  // is the stack full

int is_empty(Stack *stack); // is the stack full


// 8INF operations



#endif 