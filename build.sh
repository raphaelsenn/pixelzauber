#!/bin/bash

# This is makefile for poor people :D
clang++ -o main main.cpp
clang++ -std=c++17 -o test1 TestMat2dMath.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main
clang++ -std=c++17 -o test2 TestMat2d.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main

./test1
./test2

rm test1 test2