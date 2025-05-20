#!/bin/bash

# This is makefile for poor people :D
clang++ -std=c++17 -o main main.cpp
clang++ -std=c++17 -o test1 tests/TestMat2dMath.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main
clang++ -std=c++17 -o test2 tests/TestMat2d.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main
clang++ -std=c++17 -o test3 tests/TestFilters.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main

./test1
./test2
./test3

rm test1 test2 test3