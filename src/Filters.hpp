// =============================================================================
// File        : Filters.hpp
// Author      : Raphael Senn <raphaelsenn@gmx.de>
// License     : MIT
// =============================================================================

#pragma once

#include "./Mat2d.hpp"

// ____________________________________________________________________________
// Declarations

template <typename T>
Mat2d<T> applyFilter(const Mat2d<T>& src, const Mat2d<T>& kernel);

template <typename T>
Mat2d<T> addGaussianNoise();

// ____________________________________________________________________________
// Implementations

template <typename T>
inline Mat2d<T> applyFilter(const Mat2d<T>& src, const Mat2d<T>& kernel) {
  std::size_t K_H = kernel.rows();
  std::size_t K_W = kernel.cols();
  std::size_t H_out = src.rows() - K_H + 1;
  std::size_t W_out = src.cols() - K_W + 1;

  Mat2d<T> result(H_out, W_out, src.maxVal()); 

  for (std::size_t i = 0; i < H_out; i++) {
    for (std::size_t j = 0; j < W_out; j++) {
      T curr = T();
      for (std::size_t k = 0; k < K_H; k++) {
        for (std::size_t l = 0; l < K_W; l++) {
          curr += kernel(k, l) * src(i + k, j + l);
        }
      }
      result(i, j) = curr;
    }
  }
  return result;
}

// ____________________________________________________________________________
// Instanziations for int and float
template Mat2d<int> applyFilter<int>(const Mat2d<int>& src, const Mat2d<int>& kernel);
template Mat2d<double> applyFilter<double>(const Mat2d<double>& src, const Mat2d<double>& kernel);
