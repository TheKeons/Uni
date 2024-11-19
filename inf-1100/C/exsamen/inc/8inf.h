#ifndef INF_H_
#define INF_H_

struct stack;
typedef struct stack Stack;

struct Stack_Element;
typedef struct Stack_Element stack_element_t;


// stack operations

stack_element_t pop(Stack *stack); // returns the top of stack and removes it from stack

void push(Stack *stack, stack_element_t value); // adds to top of stack

void dup(Stack *stack); // pushes a duplicate of the top of the stack

void swap(Stack *stack);    // swaps the two top numbers of stakk

int is_full(Stack *stack);  // is the stack full

int is_empty(Stack *stack); // is the stack full


// 8INF operations

void sum(Stack *stack); // pops two numbers from the stack and pushes the sum

void differance(Stack *stack); // pops two nummbers from stack and pushes the diferance

void multible(Stack *stack);    // pops two numbers from stack and pushes the multible

void quotient(Stack *stack);    // pops two numbers from stack and pushes the quotient

void modulus(Stack *stack);     // pops two numbers from stack and pushes the modelus

void is_equal(Stack *stack);    // pops two numbers from stack and pushes 1 if equal and 0 if not

void is_greater_than(Stack *stack);     // pops two numbers from stack and pushes 1 if greater than and 0 if not

char **cjump(Stack *stack, char** program); // pops two numbers. if the second number is not `0` the program jumps by the first number.

// misc

int is_valid_number(char *string);  // checks if a stirng is purely numerical

#endif 