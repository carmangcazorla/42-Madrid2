*This project has been created as part of the 42 curriculum by carmenga.*

### Description
The aim of this project is to sort any amount of numbers using the minimal number of operations possible.

The program uses two stacks, stack A and stack B, and a limited set of allowed operations to sort the numbers.

The goal is to choose the most efficient algorithm, minimizing the total number of operations.

#### Allowed operations
**sa**: swap the first two elements of stack A.

**sb**: swap the first two elements of stack B.

**ss**: sa and sb at the same time.

**pa**: push the first element of stack B to stack A.

**pb**: push the first element of stack A to stack B.

**ra**: shift up all elements of stack A.

**rb**: shift up all elements of stack B.

**rr**: ra and rb at the same time.

**rra**: shift down all elements of stack A.

**rrb**: shift down all elements of stack B.

**rrr**: rra and rrb at the same time.

---

### Instructions

To compile the program, run:

make

This will generate the executable push_swap. Now you can run the program by passing the numbers as arguments.

./push_swap 2 1 3 6 5 8

The program will show the list of operations used.

If the arguments are invalid (non-numeric, duplicates or outside the range) the program will display:

Error

---

### Resources

This project was developed with the help of various online resources, including YouTube tutorials focused on linked lists in C and the radix sorting algorithm.

AI tools were used as an auxiliary resource to assist in planning the project structure and improving the understanding of certain concepts such as sorting strategies.