
# Source files that all algorithms use
SRC=main.c timer.c common.c
SRC:=$(patsubst %.c,src/%.c, $(SRC))

INCLUDE=include/

CFLAGS:= -O0 -Wall -Wextra -g

LDFLAGS:=-DLOG_LEVEL=0

.PHONY=all
.PHONY=dirs
.PHONY=clean

# Run all these commands when we only type "make" in the terminal
all: dirs bin/bubble_sort bin/selection_sort bin/insertion_sort

# Use bubble_sort.c as the sorting algorithm
bin/bubble_sort: src/bubble_sort.c $(SRC) Makefile
	gcc $(CFLAGS) -o $@ $< $(SRC) -I$(INCLUDE) $(LDFLAGS)

# Use selection_sort.c as the sorting algorithm
bin/selection_sort: src/selection_sort.c $(SRC) Makefile
	gcc $(CFLAGS) -o $@ $< $(SRC) -I$(INCLUDE) $(LDFLAGS)

# Use insertion_sort.c as the sorting algorithm
bin/insertion_sort: src/insertion_sort.c $(SRC) Makefile
	gcc $(CFLAGS) -o $@ $< $(SRC) -I$(INCLUDE) $(LDFLAGS)

# Create data directory if it doesn't exist
dirs:
	mkdir -p data
	mkdir -p bin

# Clean up the executables and the data files
clean:
	rm -f data/* bin/*
