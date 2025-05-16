#!/bin/bash

# This is makefile for poor people :D
clang++ -o main main.cpp
clang++ -std=c++17 -o test TestMat2dMath.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lgtest -lpthread -lgtest_main