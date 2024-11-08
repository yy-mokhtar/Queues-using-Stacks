# README: Assignment 2 - Stacks and Queues (CSAI – 230)
## Overview
This repository contains the solution for Assignment 2 in CSAI - 230 (Fall 2024). The assignment involves implementing a Queue ADT (Abstract Data Type) using two different approaches with Stack ADTs. The task is split into two attempts:

1. The first attempt uses the provided linked-list-based Stack implementation without modifications, achieving a working Queue ADT.
2. The second attempt enhances the Stack implementation to optimize performance, while still using only the push and pop methods of the Stack ADT.

The goal of the assignment is to demonstrate a deep understanding of Stacks and Queues, as well as to analyze and optimize the performance of the Queue ADT using Big-O notation.

### Source Code:
https://github.com/yy-mokhtar/Queues-using-Stacks 

# Project Structure

Queues/

Queue_attempt_1.cpp        
Queue_attempt_2.cpp        
Makefile                      
README.md                

# Requirements
GNU C/C++ Compiler (GCC)
Linux environment (recommended to use a Docker container)
Docker (optional, for reproducibility)

# How to Compile and Run
Compilation using Makefile:
Open a terminal and navigate to the Queues directory.

## To compile the project, use the following command:

make - This will compile both the Queue_attempt_1.cpp and Queue_attempt_2.cpp files, creating the corresponding executables Queue_attempt_1 and Queue_attempt_2.

# Running the Program:
After compiling, you can run the first attempt (using original Stack implementation) by executing (on bash or powershell):
./Queue_attempt_1

Similarly, to run the second attempt (with the optimized Stack implementation), execute (on bash or powershell):
./Queue_attempt_2

# Dependencies:
No external libraries are required for this project apart from the standard C++ library.
