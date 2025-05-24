// =============================================================================
// File        : Mat2d.hpp
// Author      : Raphael Senn <raphaelsenn@gmx.de>
// Description : Header-only 2D matrix template class with basic math operations
// License     : MIT
// =============================================================================

#pragma once

#include <tuple>
#include <vector>
#include <random>
#include <type_traits>
#include <stdexcept>
#include <cstddef>
#include <cmath>

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#define SEED 42
#define PI 3.14159265359
#define e  2.71828182845
#define eps 1e-8

template <typename T>
class Mat2d{
  protected: 
    std::size_t rows_;
    std::size_t cols_;
    int maxVal_;
    T* data_;

  public:
    // ________________________________________________________________________ 
    // Constructors 

    Mat2d();
    ~Mat2d();
    Mat2d(std::size_t rows, std::size_t cols, T maxVal = T(255));
    Mat2d(const Mat2d<T> &mat); 
    Mat2d(const std::vector<std::vector<T> >& vecMat, T maxVal = T(255));
    
    // ________________________________________________________________________ 
    // Operators

    Mat2d<T>& operator=(const Mat2d<T>& other);     // Copy assignment operator
    T& operator()(size_t row, size_t col);  // Element access (non-const)
    T& operator()(size_t i);  // Element access (non-const)
    const T& operator()(size_t row, size_t col) const;  // Element access (const)
    const T& operator()(size_t i) const;  // Element access (const)
    
    bool operator==(const Mat2d<T>& other) const;

    Mat2d<T> operator+(const Mat2d<T>& other);
    Mat2d<T> operator-(const Mat2d<T>& other);
    Mat2d<T> operator*(const T& scalar) const;    // Scalar mutliplication

    // ________________________________________________________________________ 
    // Methods

    size_t rows() const {return rows_;}; 
    size_t cols() const {return cols_;}; 
    T maxVal() const {return maxVal_;}; 
    void checkBounds(size_t row, size_t col);

    Mat2d<T> clip(T min, T max);    

    // I/O method
    void readPGM(std::string FileName);
    void writePGM(std::string FileName);
    void print();

    // ________________________________________________________________________ 
    // Static methods
    
    static Mat2d<T> zeros(std::size_t rows, std::size_t cols); 
    static Mat2d<T> ones(std::size_t rows, std::size_t cols); 
    static Mat2d<T> normal(double mu, double std, std::size_t rows, std::size_t cols); 
    static Mat2d<T> uniform(double low, double high, std::size_t rows, std::size_t cols); 
    static Mat2d<T> bernoulli(double p, std::size_t rows, std::size_t cols); 

    static Mat2d<T> zeros_like(const Mat2d<T>& other);
    static Mat2d<T> ones_like(const Mat2d<T>& other);
  };

// ________________________________________________________________________ 
// Declerations of none member functions
template <typename T>
Mat2d<T> operator*(const T& scalar, const Mat2d<T>& mat);

// ________________________________________________________________________ 
// Implementations - since this is a header-only file.
//
// Constructors

template <typename T>
inline Mat2d<T>::Mat2d() {
  rows_ = 0;
  cols_ = 0;
  maxVal_ = 0;
  data_ = nullptr;
}

template <typename T>
inline Mat2d<T>::Mat2d(std::size_t rows, std::size_t cols, T maxVal) {
  rows_ = rows;
  cols_ = cols;
  maxVal_ = maxVal;
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
  maxVal_ = mat.maxVal_;
  data_ = new T[rows_ * cols_];
  for (size_t i=0; i < rows_ * cols_; i++) {
    data_[i] = mat.data_[i];
  }
}

template <typename T>
inline Mat2d<T>::Mat2d(const std::vector<std::vector<T> >& vecMat, const T maxVal) {
  if (vecMat.empty() || vecMat[0].empty()) {
    throw std::invalid_argument("Input vector is empty");
  }
  rows_ = vecMat.size();
  cols_ = vecMat[0].size();
  maxVal_ = 255;
  data_ = new T[rows_ * cols_];
  for (size_t row=0; row < rows_; row++) {
    for (size_t col=0; col < cols_; col++) {
      data_[row * cols_ + col] = vecMat[row][col];
    }
  }
}

// ________________________________________________________________________ 
// Overloading operators

template <typename T> 
inline Mat2d<T>& Mat2d<T>::operator=(const Mat2d<T>& other) {
  if (this == &other) {return *this;} 
  delete[] data_;                 // deleting memory
  rows_ = other.rows_; 
  cols_ = other.cols_;
  maxVal_ = other.maxVal_; 
  data_ = new T[rows_ * cols_];   // allocating new memory
  for (size_t i=0; i < rows_ * cols_; i++) {
    data_[i] = other.data_[i];
  }
  return *this;
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

template <typename T>
inline Mat2d<T> Mat2d<T>::operator+(const Mat2d<T>& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Mat2d shapes not align");}
  Mat2d<T> result(rows_, cols_);
  for (size_t i = 0; i < rows_ * cols_; i++) {
    result.data_[i] = data_[i] + other.data_[i];
  }
  return result;
}

template <typename T>
inline Mat2d<T> Mat2d<T>::operator-(const Mat2d<T>& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Mat2d shapes not align");}
  Mat2d<T> result(rows_, cols_);
  for (size_t i = 0; i < rows_ * cols_; i++) {
    result.data_[i] = data_[i] - other.data_[i];
  }
  return result;
}

template <typename T>
inline Mat2d<T> Mat2d<T>::operator*(const T& scalar) const {
  Mat2d<T> result(rows_, cols_, maxVal_); 
  for (std::size_t i = 0; i < rows_ * cols_; i++) {
    result.data_[i] = scalar * data_[i];
  }
  return result;
}

// ____________________________________________________________________________
// Methods

template <typename T>
inline void Mat2d<T>::checkBounds(size_t row, size_t col) {
  if ((row >= rows_) || (col >= cols_)) {
    std::out_of_range("Mat2d: Index out of bounds");
  }
}

template <typename T>
inline Mat2d<T> Mat2d<T>::clip(T min, T max) {
  Mat2d<T> result(rows_, cols_, max);
  for (std::size_t i=0; i < rows_ * cols_; i++) {
    if (data_[i] < min) {result.data_[i] = min;}
    else if (data_[i] > max) {result.data_[i] = max;}
    else {result.data_[i] = data_[i];}
  }
  return result;
}

template <typename T>
inline void Mat2d<T>::readPGM(std::string fileName) {
  std::ifstream file(fileName);
  if (!file) std::cout << "Error reading the file" << std::endl;
  std::string line;
  std::getline(file, line); // P2
  if (line != "P2") std::cout << "Not PGM format" << std::endl;
  // assuming onlye one comment starting with #
  std::getline(file, line);
  std::getline(file, line);
  std::stringstream ss(line);
  ss >> rows_ >> cols_;
  file >> maxVal_;
  
  data_ = new T[rows_ * cols_];
  for (std::size_t i = 0; i < rows_ * cols_; i++) {
    int pixel;
    file >> pixel;
    data_[i] = pixel;
  }
  file.close();
}

template <typename T>
inline void Mat2d<T>::writePGM(std::string fileName) {
  std::ofstream file(fileName);
  file << "P2\n";
  file << rows_ << " " << cols_ << "\n";
  file << maxVal_ << "\n";
  for (std::size_t row = 0; row < rows_; row++) {
    for (std::size_t col = 0; col < cols_; col++) {
      file << int (data_[row * cols_ + col]) << "  ";
    }
    file << "\n";
  }
  file.close();
}

template <typename T>
void Mat2d<T>::print() {
  std::cout << "P2" << std::endl;
  std::cout << rows_ << cols_ << std::endl;
  std::cout << maxVal_ << std::endl;
  for (std::size_t row = 0; row < rows_; row++) {
    for (std::size_t col = 0; col < cols_; col++) {
      std::cout << data_[row * cols_ + col] << " ";
    }
    std::cout << "\n";
  }
}

// ____________________________________________________________________________
// Static methods

template <typename T>
inline Mat2d<T> Mat2d<T>::zeros(std::size_t rows, std::size_t cols) {
  Mat2d<T> result(rows, cols);
  for (std::size_t i = 0; i < rows * cols; i++) {
    result.data_[i] = T();
  }
  return result;
}

template <typename T>
inline Mat2d<T> Mat2d<T>::ones(std::size_t rows, std::size_t cols) {
  Mat2d<T> result(rows, cols);
  for (std::size_t i = 0; i < rows * cols; i++) {
    result.data_[i] = T(1);
  }
  return result;
}

template <typename T>
inline Mat2d<T> Mat2d<T>::zeros_like(const Mat2d<T> &other) {
  return Mat2d<T>::zeros(other.rows_, other.cols_);
}

template <typename T>
inline Mat2d<T> Mat2d<T>::ones_like(const Mat2d<T> &other) {
  return Mat2d<T>::ones(other.rows_, other.cols_);
}

template <typename T>
inline Mat2d<T> Mat2d<T>::normal(double mu, double std, std::size_t rows, std::size_t cols) {
  // Creating synthetic normal distributed random numbers.
  Mat2d<T> result(rows, cols);
  std::random_device rd;  
  std::mt19937 gen(rd());
  std::normal_distribution distribution(mu, std);
  for (std::size_t i = 0; i < rows * cols; i++) {
    result(i) = static_cast<T> (distribution(gen));
  }
  return result;
}

// ____________________________________________________________________________
// Implementations of none member functions
template <typename T>
inline Mat2d<T> operator*(const T& scalar, const Mat2d<T>& mat) {
  return mat * scalar;
}

// ____________________________________________________________________________
// Explicit instantiations for int and floats.
template class Mat2d<int>;
template class Mat2d<double>;
template class Mat2d<float>;

template Mat2d<int> operator*(const int& scalar, const Mat2d<int>& mat);
template Mat2d<double> operator*(const double& scalar, const Mat2d<double>& mat);
template Mat2d<float> operator*(const float& scalar, const Mat2d<float>& mat);