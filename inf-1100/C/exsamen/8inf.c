#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "8inf.h"

#include "inc/lexer_preprocessor.h"



char **program;

struct stack {
  char* arr[MAXWORDS];
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
  if (stack->top_index <= -1){
    return 1;
  }
  else {
    return 0;
  }
}

char *pop(Stack *stack){
  if (is_empty(stack)){
    printf("Stack underflow\n");
    return NULL;
  }
  char *top = stack->arr[stack->top_index];
  stack->top_index = stack->top_index - 1;
  return top;
}

void push(Stack *stack, char *value){
  printf("%s", value);
  if (is_full(stack)){
    printf("Stack overflow\n");
    return;
  }

  stack->top_index = stack->top_index + 1;
  stack->arr[stack->top_index] = value;
}

char *top(Stack *stack){
  return stack->arr[stack->top_index];
}

void dup(Stack *stack){
  char *top_value = top(stack);
  push(stack, top_value);
}


void swap(Stack *stack){
  char *a;
  char *b;
  char *buffer;

  b = stack->arr[stack->top_index];
  a = stack->arr[stack->top_index - 1];

  buffer = b;
  b = a;
  a = buffer;
}

// 8inf functions

void sum(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char value[100];
  sprintf(value, "%d", (a+b));

  push(stack, value);

} // pops two numbers from the stack and pushes the sum

void differance(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char value[100];
  sprintf(value, "%d", (a-b));

  push(stack, value);
} // pops two nummbers from stack and pushes the diferance

void multible(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char value[100];
  sprintf(value, "%d", (a*b));

  push(stack, value);
}   // pops two numbers from stack and pushes the multible

void quotient(Stack *stack){
  float b = atoi(pop(stack));
  float a = atoi(pop(stack));
  char value[100];
  sprintf(value, "%f", (a/b));

  push(stack, value);
}    // pops two numbers from stack and pushes the quotient

void modulus(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char value[100];
  sprintf(value, "%d", (a%b));

  push(stack, value);
}    // pops two numbers from stack and pushes the modelus

void is_equal(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char result[3];

  if (a == b){
    sprintf(result, "%d", 1);
  } else{
      sprintf(result, "%d", 0);
  }

  push(stack, result);
  
}    // pops two numbers from stack and pushes 1 if equal and 0 if not

void is_greater_than(Stack *stack){
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char result[3];

  if (a >= b){
    sprintf(result, "%d", 1);
  } else{
      sprintf(result, "%d", 0);
  }
  push(stack, result);
}     // pops two numbers from stack and pushes 1 if greater than and 0 if not



int main(int argc, char **argv) {

  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }
  Stack *stack = malloc(sizeof(Stack));
  initialize(stack);

  // program is an array of strings; the end of the program is signified by a
  // NULL pointer.
  program = load_program(argv[1]);

  // prints out the words in the program array; uncomment to get an idea of how
  // the program is stored in memory.
  for (char **pc = program; *pc != NULL; pc++) {

    //printf("program[%i]: %s\n", (int) (pc - program), *pc);
    if (*pc[0] != '.'){ // if the line is an integer
      char *string = *pc; 
      int length = strlen(string);

      if (*pc[0] == '~'){
        memmove(string, string+1, length-2);
        string[length-2] ='\0';
      }

      push(stack, string);
    }

    else if (*pc[0] == '.'){
      if (strcmp(*pc, ".+") == 0){
        sum(stack);
      }

      else if (strcmp(*pc, ".-") == 0) {
        differance(stack);
      }

      else if (strcmp(*pc, ".*") == 0) {
        multible(stack);
      }

      else if (strcmp(*pc, "./") == 0) {
        quotient(stack);
      }

      else if (strcmp(*pc, ".mod") == 0){
        modulus(stack);
      }

      else if (strcmp(*pc, ".=?") == 0) {
        is_equal(stack);
      }

      else if (strcmp(*pc, ".>?") == 0) {
        is_greater_than(stack);
      }

      else if (strcmp(*pc, ".print") == 0) {
        printf("%s", pop(stack));
      }
      
      else if (strcmp(*pc, ".newline") == 0){
        printf("\n");
      }
    }


  }


  return 0;
}
