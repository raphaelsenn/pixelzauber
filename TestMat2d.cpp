#pragma once

#include <vector>

#include <gtest/gtest.h>

#include "./Mat2d.hpp"


TEST(zeros_1, Mat2d) {
  Mat2d<int> A({{0}});
  Mat2d<int> B = Mat2d<int>::zeros(1, 1);
  ASSERT_EQ(A, B);
}

TEST(zeros_2, Mat2d) {
  Mat2d<int> A({{0, 0}, {0, 0}});
  Mat2d<int> B = Mat2d<int>::zeros(2, 2);
  ASSERT_EQ(A, B);
}

TEST(zeros_like_1, Mat2d) {
  Mat2d<int> A({{0, 0}, {0, 0}});
  Mat2d<int> B = Mat2d<int>::zeros_like(A);
  ASSERT_EQ(A, B);
}

TEST(ones_1, Mat2d) {
  Mat2d<int> A({{1}});
  Mat2d<int> B = Mat2d<int>::ones(1, 1);
  ASSERT_EQ(A, B);
}

TEST(ones_2, Mat2d) {
  Mat2d<int> A({{1, 1}, {1, 1}});
  Mat2d<int> B = Mat2d<int>::ones(2, 2);
  ASSERT_EQ(A, B);
}

TEST(ones_like_1, Mat2d) {
  Mat2d<int> A({{1, 1}, {1, 1}});
  Mat2d<int> B = Mat2d<int>::ones_like(A);
  ASSERT_EQ(A, B);
}


