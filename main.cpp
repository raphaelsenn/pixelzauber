#include "./src/Mat2d.hpp"
// #include "./src/ImgPGM.hpp"
#include "./src/Filters.hpp"

#include <iostream>
#include <cstdio>
#include <string>


void lena_examples() {
  // loading lena.pgm 
  Mat2d<int> lena;
  // lena.readPGM("./pgm_files/motion05.512.ascii.pgm");
  lena.readPGM("./pgm/lena.pgm");
  printf("Opened lena.pgm\n");

  // detect edges in X-direction
  Mat2d<int> kernel = Mat2d<int>({{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}});
  Mat2d<int> lena_mod = applyFilter(lena, kernel).clip(0, lena.maxVal());
  lena_mod.writePGM("lena_edge_x.pgm");
  printf("Wrote lena_edge_x.pgm\n");

  // detect edges in Y-direction
  kernel = Mat2d<int>({{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}});
  lena_mod = applyFilter(lena, kernel).clip(0, lena.maxVal());
  lena_mod.writePGM("lena_edge_y.pgm");
  printf("Wrote lena_edge_y.pgm\n");
 
  kernel = Mat2d<int>({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}});  
  lena_mod = applyFilter(lena, kernel).clip(0, lena.maxVal());
  lena_mod.writePGM("lena_sharp.pgm");
  printf("Wrote lena_sharp.pgm\n");

  // adding box blur
  Mat2d<double> lena_double;
  lena_double.readPGM("./pgm/lena.pgm"); 
  Mat2d<double> kernel_double = (1.0/9.0) * Mat2d<double>::ones(3, 3);
  Mat2d<double> lena_double_mod = applyFilter(lena_double, kernel_double).clip(0, lena_double.maxVal());
  lena_double_mod.writePGM("lena_box_blur.pgm");
  printf("Wrote lena_box_blur.pgm\n");

}

int main() {
  // lena_examples();
  Mat2d<int> frame_1;
  Mat2d<int> frame_2;
  frame_1.readPGM("./pgm/motion05.pgm");
  frame_2.readPGM("./pgm/motion06.pgm");
  frame_1.print(); 
  frame_1.writePGM("test.pgm");
  Mat2d<int> diff = (frame_1 - frame_2).clip(0, frame_1.maxVal());
  diff.writePGM("motion_difference.pgm"); 
  return 0;  



}