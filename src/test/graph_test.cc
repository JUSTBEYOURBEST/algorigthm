#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <gtest/gtest.h>

#include "data_struct/linklist/diff.h"

namespace algorithm {
namespace test {

int numberOfProvince(std::vector<std::vector<int>>& isConnected) {
  std::vector<std::vector<int>> parent;
  int length = isConnected.size();
  for (int i = 0; i < length; i++) {
    parent.push_back({i});
  }
  return parent.size();
}

// https://leetcode.cn/problems/number-of-provinces/description/?envType=study-plan-v2&envId=graph-theory
TEST(GraphTest, NumberOfProvince) {
  // std::vector<std::vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  // int num = numberOfProvince(isConnected);
  // EXPECT_EQ(num, 2);
  // std::vector<std::vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  // int num2 = numberOfProvince(isConnected2);
  // EXPECT_EQ(num2, 3);
}
} // namespace test
} // namespace algorithm
