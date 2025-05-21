
#pragma once

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#include "./Mat2d.hpp"


class ImgPGM : public Mat2d<int> {
  private:
    int maxVal_;
    
  public:
    ImgPGM() = default;
    ImgPGM(const Mat2d<int>& mat);
    void read(std::string fileName);
    void write(std::string fileName);
};

inline ImgPGM::ImgPGM(const Mat2d<int>& mat) : maxVal_(255), Mat2d<int>(mat) {};

inline void ImgPGM::read(std::string fileName) {
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
  
  data_ = new int[rows_ * cols_];
  for (std::size_t i = 0; i < rows_ * cols_; i++) {
    int pixel;
    file >> pixel;
    data_[i] = pixel;
  }
  file.close();
}

inline void ImgPGM::write(std::string fileName) {
  std::ofstream file(fileName);
  file << "P2\n";
  file << rows_ << " " << cols_ << "\n";
  file << maxVal_ << "\n";
  
  for (std::size_t row = 0; row < rows_; row++) {
    for (std::size_t col = 0; col < cols_; col++) {
      file << data_[row * cols_ + col] << "  ";
    }
    file << "\n";
  }
  file.close();
}