#include "8inf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/lexer_preprocessor.h"

char **program;

struct stack {
  char *arr[MAXWORDS];
  int top_index;
};

// Stack functions

void initialize(Stack *stack) { stack->top_index = -1; }

int is_full(Stack *stack) {
  if (stack->top_index == (MAXWORDS - 1)) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty(Stack *stack) {
  if (stack->top_index <= -1) {
    return 1;
  } else {
    return 0;
  }
}

char *top(Stack *stack) { return stack->arr[stack->top_index]; }

char *pop(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack underflow\n");

    return NULL;
  }
  char *top_value = top(stack);            // get the vaule
  stack->top_index = stack->top_index - 1; // moves the index down one
  return top_value;
}

void push(Stack *stack, char *value) {
  if (is_full(stack)) {
    printf("Stack overflow\n");
    return;
  }
  //  moves the index up one and adds value to the stack
  stack->top_index = stack->top_index + 1;
  stack->arr[stack->top_index] = value;
}

// duplicates the top value
void dup(Stack *stack) {
  char *top_value = top(stack);
  push(stack, top_value);
}

//  swaps the two top values
void swap(Stack *stack) {
  char *a = pop(stack);
  char *b = pop(stack);

  push(stack, a);
  push(stack, b);
}

// 8inf functions

void sum(Stack *stack) { // pops two numbers from the stack and pushes the sum
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));

  char buffer[500];
  // for loop to work this buffer needs to be big enough, i have not found a
  // better way of doing this other than guessing. there is no guarantee this
  // will work for all 8inf programs

  sprintf(buffer, "%d", (a + b));
  push(stack, buffer);
}

void differance(
    Stack *stack) { // pops two nummbers from stack and pushes the diferance
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));

  char buffer[100];
  sprintf(buffer, "%d", (a - b));

  push(stack, buffer);
}

void multible(
    Stack *stack) { // pops two numbers from stack and pushes the multible
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char buffer[100];
  sprintf(buffer, "%d", (a * b));

  push(stack, buffer);
}

void quotient(
    Stack *stack) { // pops two numbers from stack and pushes the quotient
  float b = atoi(pop(stack));
  float a = atoi(pop(stack));
  char buffer[100];
  sprintf(buffer, "%f", (a / b));

  push(stack, buffer);
}

void modulus(
    Stack *stack) { // pops two numbers from stack and pushes the modelus
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char buffer[100];
  sprintf(buffer, "%d", (a % b));

  push(stack, buffer);
}

void is_equal(Stack *stack) { // pops two numbers from stack and pushes 1 if
                              // equal and 0 if not
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char buffer[100];

  if (a == b) {
    sprintf(buffer, "%d", 1);
  } else {
    sprintf(buffer, "%d", 0);
  }

  push(stack, buffer);
}

void is_greater_than(Stack *stack) { // pops two numbers from stack and pushes 1
                                     // if greater than and 0 if not
  int b = atoi(pop(stack));
  int a = atoi(pop(stack));
  char buffer[100]; // for some reason if i put the buffer any less than 41 it
                    // wont work

  if (a > b) {
    sprintf(buffer, "%d", 1);
  } else {
    sprintf(buffer, "%d", 0);
  }
  push(stack, buffer);
}

char **cjump(Stack *stack,
             char **program) { // pops two numbers. if the second number is not
                               // `0` the program jumps by the first number
  int first = atoi(pop(stack));
  int second = atoi(pop(stack));

  if (second != 0) {
    // handles the jumping
    program = program + first;

    // since the for loop plusses one every round we need to counteract that
    program--;
  }
  return program;
}

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }

  // creates the stack
  Stack *stack = malloc(sizeof(Stack));
  initialize(stack);

  program = load_program(argv[1]);

  // loops though the program
  for (char **pc = program; *pc != NULL; pc++) {

    if (*pc[0] != '.') { // if the line is an integer
      char *string = *pc;
      int length = strlen(string);

      if (*pc[0] == '~') {
        // removes the ~ from the string
        memmove(string, string + 1, length - 2);
        string[length - 2] = '\0';
      }

      push(stack, string);
    }

    // if soup for handeling the operatos
    else if (*pc[0] == '.') {
      if (strcmp(*pc, ".+") == 0) {
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

      else if (strcmp(*pc, ".mod") == 0) {
        modulus(stack);
      }

      else if (strcmp(*pc, ".dup") == 0) {
        dup(stack);
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

      else if (strcmp(*pc, ".swap") == 0) {
        swap(stack);
      }

      else if (strcmp(*pc, ".newline") == 0) {
        printf("\n");
      }

      else if (strcmp(*pc, ".cjump") == 0) {
        pc = cjump(stack, pc);
      } else {
        printf("Unknow operator\n");
      }
    }
  }

  return 0;
}
