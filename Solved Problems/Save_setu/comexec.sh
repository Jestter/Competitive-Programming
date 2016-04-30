#!/bin/bash
g++ main.cpp -std=c++0x -o main
time ./main < file.in > file.out
gedit file.out
