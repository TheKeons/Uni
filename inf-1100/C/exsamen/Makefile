# add your source files here:
SRC := src/lexer_preprocessor.c 

# add your header files here
INC := inc/lexer_preprocessor.h 
FLAGS := -g -Wall -Wextra

8inf: 8inf.c $(SRC) $(INC)
	gcc $(FLAGS) -Iinc 8inf.c $(SRC) -o 8inf

clean:
	rm 8inf

first:
	gcc $(FLAGS) -Iinc first_implementation/first_8inf.c $(SRC) -o 8inf

.PHONY: clean
