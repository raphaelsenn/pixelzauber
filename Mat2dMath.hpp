#include <stdexcept>
#include "./Mat2d.hpp"


// ____________________________________________________________________________
// Declerations

template <typename T>
Mat2d<T> add(const Mat2d<T> &mat1, const Mat2d<T> &mat2);

template <typename T>
Mat2d<T> sub(const Mat2d<T> &mat1, const Mat2d<T> &mat2);

// ____________________________________________________________________________
// Implementations

template <typename T>
Mat2d<T> add(const Mat2d<T> &mat1, const Mat2d<T> &mat2) {
  if (mat1.rows() != mat2.rows() || mat1.cols() != mat2.cols()) {
    throw std::invalid_argument("Mat2d dimensions don't match");
  }
  Mat2d<T> result(mat1.rows(), mat1.cols());
  for (size_t i = 0; i < result.rows() * result.cols(); i++) {
    result(i) = mat1(i) + mat2(i);
  }
  return result;
}

template <typename T>
Mat2d<T> sub(const Mat2d<T> &mat1, const Mat2d<T> &mat2) {
  if (mat1.rows() != mat2.rows() || mat1.cols() != mat2.cols()) {
    throw std::invalid_argument("Mat2d dimensions don't match");
  }
  Mat2d<T> result(mat1.rows(), mat1.cols());
  for (size_t i = 0; i < result.rows() * result.cols(); i++) {
    result(i) = mat1(i) - mat2(i);
  }
  return result;
}

// ____________________________________________________________________________
// Instanziations for int and float
template Mat2d<int> add(const Mat2d<int> &mat1, const Mat2d<int> &mat2);
template Mat2d<float> add(const Mat2d<float> &mat1, const Mat2d<float> &mat2);

template Mat2d<int> sub(const Mat2d<int> &mat1, const Mat2d<int> &mat2);
template Mat2d<float> sub(const Mat2d<float> &mat1, const Mat2d<float> &mat2);

