
#pragma once

#include <vector>

#include "./Mat2d.hpp"


template <typename T>
Mat2d<T> thresholding(const Mat2d<T>& src, T threshold);


template <typename T>
Mat2d<T> thresholding(const Mat2d<T>& src, T threshold) {
  std::size_t rows = src.rows(); 
  std::size_t cols = src.cols(); 
  T maxVal = src.maxVal();
  std::vector<T> pixels = {};
  for (std::size_t i = 0; i < src.rows() * src.cols(); i++) {
    T pixel;
    if (src(i) < threshold) {pixel = T(0);}
    else {pixel = maxVal;}
    pixels.push_back(pixel); 
  } 
  return Mat2d<T>(pixels, rows, cols, maxVal);
}


template Mat2d<int> thresholding(const Mat2d<int>& src, int threshold);
template Mat2d<double> thresholding(const Mat2d<double>& src, double threshold);