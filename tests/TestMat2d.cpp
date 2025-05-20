#pragma once

#include <vector>

#include <gtest/gtest.h>

#include "../src/Mat2d.hpp"

// ____________________________________________________________________________
// Testing operators

TEST(Mat2d, operator_add_1) {
  Mat2d<int> a({{1}});
  Mat2d<int> b({{1}});
  Mat2d<int> y = Mat2d<int>({{2}});
  Mat2d<int> y_hat = a + b;
  ASSERT_EQ(y, y_hat);
}

TEST(Mat2d, operator_add_2) {
  Mat2d<int> a({{1, 2}});
  Mat2d<int> b({{3, 4}});
  Mat2d<int> y({{4, 6}});
  Mat2d<int> y_hat = a + b;
  ASSERT_EQ(y, y_hat);
}

TEST(Mat2d, operator_sub_1) {
  Mat2d<int> a({{1}});
  Mat2d<int> b({{1}});
  Mat2d<int> y({{0}});
  Mat2d<int> y_hat = a - b;
  ASSERT_EQ(y, y_hat);
}

TEST(Mat2d, operator_sub_2) {
  Mat2d<int> a({{1, 2}});
  Mat2d<int> b({{3, 4}});
  Mat2d<int> y({{-2, -2}});
  Mat2d<int> y_hat = a - b;
  ASSERT_EQ(y, y_hat);
}

// ____________________________________________________________________________
// Testing static methods

TEST(Mat2d, static_method_zeros_1) {
  Mat2d<int> y({{0}});
  Mat2d<int> y_hat = Mat2d<int>::zeros(1, 1);
  ASSERT_EQ(y_hat, y);
}

TEST(Mat2d, static_method_zeros_2) {
  Mat2d<int> y({{0, 0}, {0, 0}});
  Mat2d<int> y_hat = Mat2d<int>::zeros(2, 2);
  ASSERT_EQ(y_hat, y);
}

TEST(Mat2d, static_method_zeros_3) {
  Mat2d<int> y({{0, 0}, {0, 0}});
  Mat2d<int> y_hat = Mat2d<int>::zeros_like(y);
  ASSERT_EQ(y_hat, y);
}

TEST(Mat2d, static_method_ones_1) {
  Mat2d<int> y({{1}});
  Mat2d<int> y_hat = Mat2d<int>::ones(1, 1);
  ASSERT_EQ(y_hat, y);
}

TEST(Mat2d, static_method_ones_2) {
  Mat2d<int> y({{1, 1}, {1, 1}});
  Mat2d<int> y_hat = Mat2d<int>::ones(2, 2);
  ASSERT_EQ(y_hat, y);
}

TEST(Mat2d, static_method_ones_3) {
  Mat2d<int> y({{1, 1}, {1, 1}});
  Mat2d<int> y_hat = Mat2d<int>::ones_like(y);
  ASSERT_EQ(y_hat, y);
}


