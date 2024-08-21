# Push_swap

## Introduction

This project, part of the 42 curriculum, is designed to enhance your understanding of sorting algorithms, data structures, and algorithmic complexity. The goal of the **Push_swap** project is to sort a stack of integers using a limited set of operations, all while striving to minimize the number of moves required.

## Project Overview

**Push_swap** provides you with two stacks, **A** and **B**. Initially, all the integers are placed in stack **A**, and stack **B** is empty. Your task is to sort all the integers in ascending order in stack **A** using a predefined set of operations:

- **sa**: swap the first two elements at the top of stack **A**.
- **sb**: swap the first two elements at the top of stack **B**.
- **ss**: perform `sa` and `sb` simultaneously.
- **pa**: push the top element of stack **B** onto stack **A**.
- **pb**: push the top element of stack **A** onto stack **B**.
- **ra**: rotate stack **A** upward (the first element becomes the last).
- **rb**: rotate stack **B** upward (the first element becomes the last).
- **rr**: perform `ra` and `rb` simultaneously.
- **rra**: reverse rotate stack **A** downward (the last element becomes the first).
- **rrb**: reverse rotate stack **B** downward (the last element becomes the first).
- **rrr**: perform `rra` and `rrb` simultaneously.

## Algorithmic Approach

To achieve an efficient solution, I implemented an algorithm that divides stack A into several chunks. The approach can be summarized as follows:

    Chunk Division: The stack A is divided into multiple chunks, each representing a range of values. The goal is to handle smaller, more manageable portions of the stack at a time.

    Push to Stack B: The algorithm iterates through stack A, pushing elements belonging to the first chunk into stack B. This process is repeated for each subsequent chunk until all elements have been moved to stack B.

    Sorting and Returning to Stack A: Once all elements are in stack B, the algorithm pushes them back into stack A in a manner that ensures they are sorted. The elements are pushed back in order, starting with the last chunk and ending with the first, resulting in a fully sorted stack A.

This chunk-based approach effectively reduces the problem's complexity by breaking it down into smaller parts, allowing for efficient management of operations and ensuring that the final stack A is sorted with minimal moves.

to get the 100/100 there're few more optimisations.
## Concepts Covered

### 1. **Sorting Algorithms**
   - Understanding and implementing sorting algorithms, particularly Quick Sort.
   - Adapting a general sorting algorithm to a specific problem with constraints.

### 2. **Data Structures**
   - Efficient manipulation of stacks (LIFO - Last In, First Out structure).
   - Understanding and managing stack operations like push, pop, and swap.

### 3. **Algorithmic Complexity**
   - Analyzing and optimizing the number of operations.
   - Striving to achieve a solution that works within the constraints of O(n log n) complexity, where possible.

### 4. **Problem Solving**
   - Developing an approach to solve a problem with minimal steps.
   - Adapting known algorithms to fit specific, constrained environments.

## Score: 100/100

I received a perfect score of **100/100** on this project, reflecting the efficiency, correctness, and optimization of my algorithm.

## How to Use

To test the Push_swap program, you can compile it and run it with a list of integers. The program will output the sequence of operations required to sort the stack.

```bash
$ make
$ ./push_swap 4 67 3 87 23
```

You can verify the output using the checker provided by the project or by analyzing the sequence of operations.
