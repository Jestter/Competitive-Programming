#!/bin/bash
g++ main.cpp -o main
./main < test.in > test.out
subl test.out
