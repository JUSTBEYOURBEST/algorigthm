#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <gtest/gtest.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cassert>

namespace algorithm {
namespace test {

class SquareArea {
public:
  SquareArea(int left_x, int left_y, int right_x, int right_y)
    : left_x_(left_x), left_y_(left_y), right_x_(right_x), right_y_(right_y) {}
  ~SquareArea() = default;

  bool isOverlap(const SquareArea& other) const {
    return left_x_ < other.right_x_ &&
           right_x_ > other.left_x_ &&
           left_y_ < other.right_y_ &&
           right_y_ > other.left_y_;
  }

long long getMaxArea(const SquareArea& other) const {
    int overlap_left_x  = std::max(left_x_,  other.left_x_);
    int overlap_right_x = std::min(right_x_, other.right_x_);
    int overlap_left_y  = std::max(left_y_,  other.left_y_);
    int overlap_right_y = std::min(right_y_, other.right_y_);

    int width  = overlap_right_x - overlap_left_x;
    int height = overlap_right_y - overlap_left_y;

    if (width <= 0 || height <= 0) {
      return 0;
    }

    long long side = std::min(width, height);
    return side * side;
  }

  int left_x_;
  int left_y_;
  int right_x_;
  int right_y_;
};

// https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/?envType=daily-question&envId=2026-01-18
TEST(StringTest, largestSquareArea) {
  std::vector<std::vector<int>>  bottomLeft = {{1,1}, {3,3}, {3,1}};
  std::vector<std::vector<int>>  topRight = {{2,2}, {4,4}, {4,2}};
  int size = bottomLeft.size();
  std::vector<SquareArea> square_areas;
  for (int i = 0; i < size; ++i) {
    square_areas.emplace_back(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]);
  }
  std::sort(square_areas.begin(), square_areas.end(), [](const SquareArea& a, const SquareArea& b) {
    return a.left_x_ < b.left_x_;
  });
  long long ans = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      ans = std::max(ans, square_areas[i].getMaxArea(square_areas[j]));
    }
  }
  ASSERT_EQ(ans, 0);

  // need clear
}




} // namespace test
} // namespace algorithm
