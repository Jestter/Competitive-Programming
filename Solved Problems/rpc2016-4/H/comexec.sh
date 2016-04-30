#!/bin/bash
g++ main.cpp -std=c++0x -o main
./main < test.in > test.out
gedit test.out
