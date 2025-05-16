#include "./Mat2d.hpp"
#include "./ImgPGM.hpp"
#include <iostream>
#include <cstdio>


int main() {
  Mat2d<int> img(3, 3); 
  Mat2d<int> img2(img);
  ImgPGM imgm; 
  printf("Hello \n"); 
  return 0;  

}