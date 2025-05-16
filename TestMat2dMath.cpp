#pragma once

#include <vector>

#include <gtest/gtest.h>

#include "./Mat2d.hpp"
#include "./Mat2dMath.hpp"


TEST(Mat2dAdd, Mat2d){
  Mat2d<int> A({{1, 2}, {3, 4}});
  Mat2d<int> B({{1, 2}, {3, 4}});
  Mat2d<int> A_plus_B = add(A, B);
  EXPECT_EQ(A_plus_B, Mat2d<int>({{2, 4}, {6, 8}})); 
}