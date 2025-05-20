#include <vector>

#include <gtest/gtest.h>

#include "../src/Mat2d.hpp"
#include "../src/Filters.hpp"


TEST(Filter, applyFilter_1){
  Mat2d<int> input({{1, 1}, {1, 1}});
  Mat2d<int> kernel({{1, 1}, {1, 1}});
  Mat2d<int> y({{4}});
  Mat2d<int> y_hat = applyFilter(input, kernel);
  EXPECT_EQ(y, y_hat); 
}

TEST(Filter, applyFilter_2){
  Mat2d<int> input({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  Mat2d<int> kernel({{100}});
  Mat2d<int> y({{100, 200, 300}, {400, 500, 600}, {700, 800, 900}});
  Mat2d<int> y_hat = applyFilter(input, kernel);
  EXPECT_EQ(y, y_hat); 
}

