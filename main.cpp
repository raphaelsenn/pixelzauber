#include "./Mat2d.hpp"
#include <iostream>
#include <cstdio>


int main() {
  Mat2d<int> img(3, 3); 
  Mat2d<int> img2(img); 
  printf("Hello \n"); 
  return 0;  

}