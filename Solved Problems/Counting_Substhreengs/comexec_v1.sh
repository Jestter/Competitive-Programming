#!/bin/bash
g++ main_v1.cpp -std=c++0x -o main_v1
time ./main_v1 < file.in > file.out
gedit file.out
