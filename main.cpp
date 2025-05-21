#include "./src/Mat2d.hpp"
// #include "./src/ImgPGM.hpp"
#include "./src/Filters.hpp"

#include <iostream>
#include <cstdio>
#include <string>

int main() {
  Mat2d<int> img(3, 3); 
  Mat2d<int> img2(img);
  // ImgPGM imgm; 
  Mat2d<int> ones = Mat2d<int>::ones(2, 2);
  Mat2d<int> norm = Mat2d<int>::normal(0.0, 1.0, 2, 2);

  Mat2d<int> lena;
  lena.readPGM("lena.pgm");
  printf("Opened lena.pgm\n");

  Mat2d<int> kernel = Mat2d<int>({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}});
  // Mat2d<int> kernel = Mat2d<int>({{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}});
  Mat2d<int> lena_edges = applyFilter(lena, kernel);
  printf("Applied filter to lena.pgm\n");
  Mat2d<int> res(lena_edges);
  Mat2d<int> res2 = res.clip(0, res.maxVal());
  
  res2.writePGM("lena_mod.pgm");
  printf("Written lena_mod.pgm\n");
  return 0;  

}