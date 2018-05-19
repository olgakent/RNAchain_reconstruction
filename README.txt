/*******************************************************************************
Author:			Olga Kent
Course:		    CSCI 393 Independent Study / Graph theory
Professor:		Christina Zamfirescu

Part 2. A program that reconstructs the RNA chain out of two sets of
fragments:
1) one set is obtained after applying the G-enzyme on the RNA chain
2) the other set is obtained after applying the UC-enzyme on another,
identical RNA chain.
*******************************************************************************/

The USB drive contains files:
- makefile
- main.cpp
- Graph.h
- Graph.cpp
- output1.txt
- output2.txt

Compiling & Executing:

In order to run and test this program properly, user must have a command-line
interface installed. Once in the proper directory of the program where all
the files reside, the makefile can be utilized to quickly compile the program by typing:

    make all

This will compile the program according to the settings already specified in the
makefile and create an executable called: RNAchain

In order to execute the program, type:

    ./RNAchain

To delete executables and object file, type:

    make clean
