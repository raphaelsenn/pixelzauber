#include "./src/Mat2d.hpp"
#include "./src/ImgPGM.hpp"
#include <iostream>
#include <cstdio>


int main() {
  Mat2d<int> img(3, 3); 
  Mat2d<int> img2(img);
  ImgPGM imgm; 
  Mat2d<int> ones = Mat2d<int>::ones(2, 2);
  Mat2d<int> norm = Mat2d<int>::normal(0.0, 1.0, 2, 2);

  printf("Hello \n"); 
  return 0;  

}