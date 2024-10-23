#ifndef INF_H_
#define INF_H_

struct stack;
typedef struct stack Stack;


// stack operations

char *pop(Stack *stack); // returns the top of stack and removes it from stack

void push(Stack *stack, char*value); // adds to top of stack

char *top(Stack *stack);  // returns value on tho of stack

void print_top(Stack *stack);

void dup(Stack *stack); // pushes a duplicate of the top of the stack

void swap(Stack *stack);    // swaps the two top numbers of stakk

int is_full(Stack *stack);  // is the stack full

int is_empty(Stack *stack); // is the stack full

void initialize(Stack *stack);  // initialize the stack

// 8INF operations

void sum(Stack *stack); // pops two numbers from the stack and pushes the sum

void differance(Stack *stack); // pops two nummbers from stack and pushes the diferance

void multible(Stack *stack);    // pops two numbers from stack and pushes the multible

void quotient(Stack *stack);    // pops two numbers from stack and pushes the quotient

void modulus(Stack *stack);     // pops two numbers from stack and pushes the modelus

void is_equal(Stack *stack);    // pops two numbers from stack and pushes 1 if equal and 0 if not

void is_greater_than(Stack *stack);     // pops two numbers from stack and pushes 1 if greater than and 0 if not

char **cjump(Stack *stack, char** program); // pops two numbers. if the second number is not `0` the program jumps by the first number.

#endif 