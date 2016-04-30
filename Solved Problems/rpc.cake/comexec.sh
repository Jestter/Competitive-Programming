#!/bin/bash
g++ cake.cpp -std=c++0x -o cake
time ./cake < file.in > file.out
gedit file.out
