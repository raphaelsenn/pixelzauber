
#pragma once
#include <cstddef>
#include <stdexcept>
#include <tuple>
#include <vector>

template <typename T>
class Mat2d{
  private: 
    std::size_t rows_;
    std::size_t cols_;
    T* data_;

  public:
    Mat2d(std::size_t rows, std::size_t cols);
    ~Mat2d();
    Mat2d(const Mat2d<T> &mat); 
    Mat2d(const std::vector<std::vector<T> >& vecMat);

    T& operator()(size_t row, size_t col);  // Element access (non-const)
    T& operator()(size_t i);  // Element access (non-const)
    const T& operator()(size_t row, size_t col) const;  // Element access (const)
    const T& operator()(size_t i) const;  // Element access (const)
    
    bool operator==(const Mat2d<T>& other) const;

    size_t rows() const {return rows_;}; 
    size_t cols() const {return cols_;}; 
    void checkBounds(size_t row, size_t col);
  };

// ________________________________________________________________________ 
// Implementations - since this is a header-only file.

template <typename T>
inline Mat2d<T>::Mat2d(std::size_t rows, std::size_t cols) {
  rows_ = rows;
  cols_ = cols;
  data_ = new T[rows_ * cols_];
}

template <typename T>
inline Mat2d<T>::~Mat2d() {
  delete[] data_;
}

template <typename T>
inline Mat2d<T>::Mat2d(const Mat2d<T> &mat) {
  rows_ = mat.rows_;
  cols_ = mat.cols_;
  data_ = new T[rows_ * cols_];
  for (size_t i=0; i < rows_ * cols_; i++) {
    data_[i] = mat.data_[i];
  }
}

template <typename T>
inline Mat2d<T>::Mat2d(const std::vector<std::vector<T> >& vecMat) {
  if (vecMat.empty() || vecMat[0].empty()) {
    throw std::invalid_argument("Input vector is empty");
  } 
  rows_ = vecMat.size();
  cols_ = vecMat[0].size();
  data_ = new T[rows_ * cols_];
  for (size_t row=0; row < rows_; row++) {
    for (size_t col=0; col < cols_; col++) {
      data_[row * cols_ + col] = vecMat[row][col];
    }
  }
}

template <typename T>
inline T& Mat2d<T>::operator()(size_t row, size_t col) {return data_[row * cols_ + col];}

template <typename T>
inline const T& Mat2d<T>::operator()(size_t row, size_t col) const {return data_[row * cols_ + col];}


template <typename T>
inline T& Mat2d<T>::operator()(size_t i) {return data_[i];}

template <typename T>
inline const T& Mat2d<T>::operator()(size_t i) const {return data_[i];}


template <typename T>
inline bool Mat2d<T>::operator==(const Mat2d<T>& other) const{
  if (rows_ != other.rows_ || cols_ != other.cols_) {return false;} 
  for (size_t i = 0; i < rows_ * cols_; i++) {
    if (data_[i] != other.data_[i]) {return false;}
  }  
  return true;
}


// ____________________________________________________________________________
// Methods

template <typename T>
inline void Mat2d<T>::checkBounds(size_t row, size_t col) {
  if ((row >= rows_) || (col >= cols_)) {
    std::out_of_range("Mat2d: Index out of bounds");
  }
}

// ____________________________________________________________________________
// Explicit instantiations for int and floats.
template class Mat2d<int>;
template class Mat2d<float>;