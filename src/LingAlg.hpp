#include "./Mat2d.hpp"



template <typename T>
Mat2d<T> solveJacobiMethod(const Mat2d<T>& A, const Mat2d<T>& b);


template <typename T>
inline Mat2d<T> solveJacobiMethod(const Mat2d<T>& A, const Mat2d<T>& b) {
  Mat2d<T> x = Mat2d<T>::zeros_like(b);
  return x;
}

