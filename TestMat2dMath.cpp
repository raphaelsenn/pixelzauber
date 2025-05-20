#include <vector>

#include <gtest/gtest.h>

#include "./Mat2d.hpp"
#include "./Mat2dMath.hpp"


TEST(Mat2dMath, add){
  Mat2d<int> a({{1, 2}, {3, 4}});
  Mat2d<int> b({{1, 2}, {3, 4}});
  Mat2d<int> y({{2, 4}, {6, 8}});
  Mat2d<int> y_hat = add(a, b);
  EXPECT_EQ(y, y_hat);
}

