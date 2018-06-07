Alex Campos & Natalia Alvarez
cssc 1196 & cssc1193
cssc 1196 has the assignment
CS 570 Summer 2018
Assignment #1
README

Program Description:
"Four “card players” will run, each in their own thread, simultaneously but asynchronously with each other. Each card player shall write the specified text message to one, common shared resource, a file named STACK.txt. When writing to this file, the thread needs to prevent the data from getting corrupted by the other card player’s threads; to implement this, each card player’s thread shall use an appropriate IPC mechanism/algorithm."

Program contains the following files:

a1.h -- header
a1.c -- main source
makefile -- makefile
STACK.txt -- output file

To build and run: 
make run

The output is printed to STACK.txt

Lessons Learned:
Learned more about threading. 
Learned to do error checking for thread creation and joining.

