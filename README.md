*This project has been created as part of the 42 curriculum by mperrine.*

## Description

`push_swap` is an algorithmic project from the 42 curriculum.

The goal is to sort a stack of integers using a limited set of operations and an auxiliary stack, while minimizing the total number of operations.

The program receives a list of integers, builds **stack A**, and must output a sequence of instructions that will sort stack A in ascending order using **stack B** as support.

### Allowed operations

**Swap :**  
- `sa` : swap the top two elements of stack A  
- `sb` : swap the top two elements of stack B  
- `ss` : perform both `sa` and `sb` simultaneously  

**Push :**  
- `pa` : pop the top element from stack B and push it onto stack A  
- `pb` : pop the top element from stack A and push it onto stack B  

**Rotate :**  
- `ra` : shift all elements of stack A up by one (the first element becomes the last)  
- `rb` : same for stack B  
- `rr` : perform both `ra` and `rb` simultaneously  

**Reverse rotate :**  
- `rra` : shift all elements of stack A down by one (the last element becomes the first)  
- `rrb` : same for stack B  
- `rrr` : perform both `rra` and `rrb` simultaneously

This implementation uses **K-distribution sort**, commonly referred to as **butterfly sort**.

## Instructions

A `Makefile` is provided to compile the project.

**Build**
```bash
make
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

**Execution**

```bash
./push_swap <list_of_integers>
```

Example :
```bash
./push_swap 3 2 5 1 4
```

## Resources

This project was developed without the use of any AI tools.

The algorithm implementation is based on the following article :  
[K-distribution sort applied to the push_swap problem](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376).
