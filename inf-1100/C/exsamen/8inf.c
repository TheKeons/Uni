#include "inc/8inf.h"
#include "inc/lexer_preprocessor.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **program;

typedef enum { INT_TYPE, STRING_TYPE } DataType;

struct Stack_Element {
  DataType type; // type data

  union {
    int Integer;
    char *String;
  } data;
};

struct stack {
  int top_index;
  stack_element_t arr[MAXWORDS];
};

// Stack functions
int is_full(Stack *stack) { return (stack->top_index == (MAXWORDS - 1)); }

int is_empty(Stack *stack) { return (stack->top_index <= -1); }

stack_element_t pop(Stack *stack) {
  if (is_empty(stack)) {
    // error handling
    fprintf(stderr, "Stack Underflow: file: %s line: %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  } else {
    stack_element_t top_value = stack->arr[stack->top_index]; // get the vaule
    stack->top_index = stack->top_index - 1; // moves the index down one

    return top_value;
  }
}

void push(Stack *stack, stack_element_t value) {
  if (is_full(stack)) {
    // error handling
    fprintf(stderr, "Stack Overflow: file: %s line: %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }

  //  moves the index up one and adds value to the stack
  stack->top_index = stack->top_index + 1;
  stack->arr[stack->top_index] = value;
}

// duplicates the top value
void dup(Stack *stack) {
  stack_element_t top_value = stack->arr[stack->top_index];
  push(stack, top_value);
}

//  swaps the two top values
void swap(Stack *stack) {
  stack_element_t a = pop(stack);
  stack_element_t b = pop(stack);

  push(stack, a);
  push(stack, b);
}

// 8inf functions

void sum(Stack *stack) { // pops two numbers from the stack and pushes the sum
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  stack_element_t result = {.type = INT_TYPE,
                            .data.Integer = (a.data.Integer + b.data.Integer)};
  push(stack, result);
}

void differance(
    Stack *stack) { // pops two nummbers from stack and pushes the diferance
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  stack_element_t result = {.type = INT_TYPE,
                            .data.Integer = (a.data.Integer - b.data.Integer)};
  push(stack, result);
}

void multible(
    Stack *stack) { // pops two numbers from stack and pushes the multible
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  stack_element_t result = {.type = INT_TYPE,
                            .data.Integer = a.data.Integer * b.data.Integer};
  push(stack, result);
}

void quotient(
    Stack *stack) { // pops two numbers from stack and pushes the quotient
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  if (b.data.Integer != 0) {
    stack_element_t result = {
        .type = INT_TYPE, .data.Integer = (a.data.Integer / b.data.Integer)};
    push(stack, result);
  } else {
    printf("Divison by zero");
    return;
  }
}

void modulus(
    Stack *stack) { // pops two numbers from stack and pushes the modelus
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  if (b.data.Integer != 0) {
    stack_element_t result = {
        .type = INT_TYPE, .data.Integer = (a.data.Integer % b.data.Integer)};
    push(stack, result);
  } else {
    printf("Divison by zero");
    return;
  }
}

void is_equal(Stack *stack) { // pops two numbers from stack and pushes 1 if
                              // equal and 0 if not
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  if (a.data.Integer == b.data.Integer) {
    stack_element_t result = {.type = INT_TYPE, .data.Integer = 1};
    push(stack, result);
  } else {
    stack_element_t result = {.type = INT_TYPE, .data.Integer = 0};
    push(stack, result);
  }
}

void is_greater_than(Stack *stack) { // pops two numbers from stack and pushes 1
                                     // if greater than and 0 if not
  stack_element_t b = pop(stack);
  stack_element_t a = pop(stack);

  if (a.data.Integer > b.data.Integer) {
    stack_element_t result = {.type = INT_TYPE, .data.Integer = 1};
    push(stack, result);
  } else {
    stack_element_t result = {.type = INT_TYPE, .data.Integer = 0};
    push(stack, result);
  }
}

char **cjump(Stack *stack,
             char **program) { // pops two numbers. if the second number is not
                               // `0` the program jumps by the first number
  int first = pop(stack).data.Integer;
  int second = pop(stack).data.Integer;

  if (second != 0) {
    // handles the jumping
    program = program + first;

    // since the for loop plusses one every round we need to counteract that
    program--;
  }
  return program;
}

int is_valid_number(char *string) {
  if (string == NULL || *string == '\0') {
    return 0;
  }

  if (*string == '-') {
    string++;
  }

  while (*string) {
    if (!isdigit(*string)) {
      return 0;
    }
    string++;
  }

  return 1;
}

void interpret(Stack *stack, char **program) {
  for (char **pc = program; *pc != NULL; pc++) {
    if (*pc[0] != '.') { // if the line is an integer
      char *string = *pc;
      int length = strlen(string);

      if (*pc[0] == '~') {
        // removes the ~ from the string
        memmove(string, string + 1, length - 2);
        string[length - 2] = '\0';

        stack_element_t result = {.type = STRING_TYPE, .data.String = string};
        push(stack, result);
      }

      else if (is_valid_number(string)) { // if string is purely numerical

        stack_element_t number = {.type = INT_TYPE, .data.Integer = atoi(string)};
        push(stack, number);
      }

      else {
        // error handling incase pc is not a valid number
        fprintf(stderr, "%s is not a number: file: %s line: %d\n", *pc, __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
      }
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
        stack_element_t top_value = pop(stack);

        // Checks the type of the top value and prints the value
        if (top_value.type == STRING_TYPE) {
          printf("%s", top_value.data.String);
        } else {
          printf("%d", top_value.data.Integer);
        }
      }

      else if (strcmp(*pc, ".swap") == 0) {
        swap(stack);
      }

      else if (strcmp(*pc, ".newline") == 0) {
        printf("\n");
      }

      else if (strcmp(*pc, ".cjump") == 0) {
        pc = cjump(stack, pc);
      } 
      
      else {
        printf("%s Unknow operator\n", *pc);
      }
    }
  }
}

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }

  // creates the stack
  Stack *stack = malloc(sizeof(Stack));
  stack->top_index = -1;

  program = load_program(argv[1]);

  interpret(stack, program);
  
  free(stack);
  stack = NULL; // to avoid a dangling pointer
  return 0;
}
