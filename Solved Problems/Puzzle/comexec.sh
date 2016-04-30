#!/bin/bash
g++ main.cpp -lm -lcrypt -O2 -std=c++11 -o main
time ./main < test.in > test.out
subl test.out
