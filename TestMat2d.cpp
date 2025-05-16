#pragma once

#include <vector>

#include <gtest/gtest.h>

#include "./Mat2d.hpp"

// ____________________________________________________________________________
// Testing operators
TEST(operator_add_1, Mat2d) {
  Mat2d<int> A({{1}});
  Mat2d<int> B({{1}});
  Mat2d<int> A_plus_B = A + B;
  ASSERT_EQ(A_plus_B, Mat2d<int>({{2}}));
}

TEST(operator_add_2, Mat2d) {
  Mat2d<int> A({{1, 2}});
  Mat2d<int> B({{3, 4}});
  Mat2d<int> A_plus_B = A + B;
  ASSERT_EQ(A_plus_B, Mat2d<int>({{4, 6}}));
}

TEST(operator_sub_1, Mat2d) {
  Mat2d<int> A({{1}});
  Mat2d<int> B({{1}});
  Mat2d<int> A_plus_B = A - B;
  ASSERT_EQ(A_plus_B, Mat2d<int>({{0}}));
}

TEST(operator_sub_2, Mat2d) {
  Mat2d<int> A({{1, 2}});
  Mat2d<int> B({{3, 4}});
  Mat2d<int> A_plus_B = A - B;
  ASSERT_EQ(A_plus_B, Mat2d<int>({{-2, -2}}));
}

// ____________________________________________________________________________
// Testing static methods

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


