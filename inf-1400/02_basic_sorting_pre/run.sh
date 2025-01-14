#!/bin/bash

# Each execution will run a sorting algorithm with a order argument
# 0 = The array will be in random order
# -1 = The array will be in reversed order
# 1 = The array will be in sorted order
#
# Each command redirects (>) stdout (1) into the given files
# This means that anything printed to the shell using printf or fprintf(stdout)
# will be written to the file instead of to the shell.
# Anything printed to stderr (2) using fprintf(stderr) will still show up in the console, 
# and won't be redirected to the files.

# Run bubble sort with 3 types of data: random, reversed and sorted
echo "Bubble Sort"
./bin/bubble_sort 2048 0 1> data/bubble_random.data
./bin/bubble_sort 2048 -1 1> data/bubble_reversed.data
./bin/bubble_sort 2048 1 1> data/bubble_sorted.data

# Run selection sort with 3 types of data: random, reversed and sorted
echo "Selection Sort"
./bin/selection_sort 2048 0 1> data/selection_random.data
./bin/selection_sort 2048 -1 1> data/selection_reversed.data
./bin/selection_sort 2048 1 1> data/selection_sorted.data

# Run insertion sort with 3 types of data: random, reversed and sorted
echo "Insertion Sort"
./bin/insertion_sort 2048 0 1> data/insertion_random.data
./bin/insertion_sort 2048 -1 1> data/insertion_reversed.data
./bin/insertion_sort 2048 1 1> data/insertion_sorted.data