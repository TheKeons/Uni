#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "8inf.h"

#include "inc/lexer_preprocessor.h"



char **program;

struct stack {
  int arr[MAXWORDS];
  int top_index;
};


// Stack functions

void initialize(Stack *stack){
  stack->top_index = -1;
}

int is_full(Stack *stack){
  if (stack->top_index == (MAXWORDS-1)){
    return 1;
  }
  else {
    return 0;
  }
}

int is_empty(Stack *stack){
  if (stack->top_index == -1){
    return 1;
  }
  else {
    return 0;
  }
}

int pop(Stack *stack){
  if (is_empty(stack)){
    printf("Stack underflow");
    return -1;
  }
  int top = stack->arr[stack->top_index];
  stack->top_index = stack->top_index - 1;
  return top;
}

void push(Stack *stack, int value){
  if (is_full(stack)){
    printf("Stack overflow");
    return;
  }

  stack->top_index++;
  stack->arr[stack->top_index] = value;
}

int top(Stack *stack){
  return stack->arr[stack->top_index];
}

void dup(Stack *stack){
  int top_int = top(stack);
  push(stack, top_int);
}


void swap(Stack *stack){
  int a;
  int b;
  int buffer;

  b = stack->arr[stack->top_index];
  a = stack->arr[stack->top_index - 1];

  buffer = b;
  b = a;
  a = buffer;
}
// 8inf functions





int main(int argc, char **argv) {

  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }

  // program is an array of strings; the end of the program is signified by a
  // NULL pointer.
  program = load_program(argv[1]);
  char *string_buffer;
  int a;
  int b;


  // prints out the words in the program array; uncomment to get an idea of how
  // the program is stored in memory.
  for (char **pc = program; *pc != NULL; pc++) {

    //printf("program[%i]: %s\n", (int) (pc - program), *pc);
    if (*pc[0] == '~'){
      string_buffer = *pc;
    }

    else if (*pc[0] == '.'){

      //implement said operators and call functions here
    }

    else { // if the line is an integer
        if (*(pc + 1)[0] != '~' && *(pc + 1)[0] != '.'){
          b = **pc - '0';
          a = **(pc + 1) - '0';
          
        }
    }
  }

  printf("\n%d, %d\n", a, b);

  return 0;
}
