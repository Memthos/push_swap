*This project has been created as part of the 42 curriculum by mperrine.*

## Description

`push_swap` is a project whose goal is to sort a stack of numbers using a limited set of operations and an auxiliary stack, while minimizing the total number of operations.

The program receives a list of numbers, builds **stack A**, and must output a sequence of instructions that will sort stack A in ascending order using **stack B** as support.

This implementation of `push_swap` uses **K-distribution sort**, which works by pushing elements from stack A to stack B while trying to keep the smaller numbers at the center of the stack. Then the numbers are pushed back to the stack A in ascending order. This approach achieves roughly **~580 operations for 100 numbers** and **~5050 operations for 500 numbers**.

The bonus part takes the same list of numbers as input, reads a sequence of operations from standard input, then writes `OK` if the stack is sorted or `KO` if not.


### Allowed operations

**Swap :**
- `sa` : Swap the top two elements of stack A
- `sb` : Swap the top two elements of stack B
- `ss` : Perform both `sa` and `sb` simultaneously

**Push :**
- `pa` : Pop the top element from stack B and push it onto stack A
- `pb` : Pop the top element from stack A and push it onto stack B

**Rotate :**
- `ra` : Shift all elements of stack A up by one (the first element becomes the last)
- `rb` : Shift all elements of stack B up by one (the first element becomes the last)
- `rr` : Perform both `ra` and `rb` simultaneously

**Reverse rotate :**
- `rra` : Shift all elements of stack A down by one (the last element becomes the first)
- `rrb` : Shift all elements of stack B down by one (the last element becomes the first)
- `rrr` : Perform both `rra` and `rrb` simultaneously

## Instructions

A `Makefile` is provided to compile the project.

**Build**
```bash
make
make bonus
```

**Clean**
```bash
make clean
make fclean
```

**Rebuild**
```bash
make re
```

## Usage
```bash
./push_swap <list_of_integers>
```

Example :
```bash
./push_swap 3 2 5 1 4
```

With the checker :
```
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```
or

```
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

## Resources

AI was used to check spelling errors in this readme.

The algorithm implementation is based on the following article :
[K-distribution sort applied to the push_swap problem](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376).
