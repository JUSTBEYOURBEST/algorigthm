#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <gtest/gtest.h>

#include "data_struct/linklist/diff.h"

namespace algorithm {

TEST(DiffTest, Basic) {
  LOG(INFO) << "Starting Basic test";

  std::vector<int> nums = {1, 2, 3, 4, 5};
  Difference diff(nums);

  // 增量操作：[1, 3] 区间加 2
  diff.increment(1, 3, 2);

  // 获取结果并验证
  std::vector<int> result = diff.result();
  std::vector<int> expected = {1, 4, 5, 6, 5};

  // GoogleTest 断言
  EXPECT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < result.size(); ++i) {
    EXPECT_EQ(result[i], expected[i]) << "Mismatch at index " << i;
  }

  LOG(INFO) << "Basic test passed";
}

TEST(DiffTest, MultipleIncrements) {
  LOG(INFO) << "Starting MultipleIncrements test";

  std::vector<int> nums = {0, 0, 0, 0, 0};
  Difference diff(nums);

  // 多次增量操作
  diff.increment(0, 2, 1);  // [0,2] +1 => [1,1,1,0,0]
  diff.increment(1, 4, 2);  // [1,4] +2 => [1,3,3,2,2]

  std::vector<int> result = diff.result();
  std::vector<int> expected = {1, 3, 3, 2, 2};

  EXPECT_EQ(result, expected);
  LOG(INFO) << "MultipleIncrements test passed";
}

TEST(DiffTest, EdgeCases) {
  LOG(INFO) << "Starting EdgeCases test";

  // 单元素数组
  {
    std::vector<int> nums = {5};
    Difference diff(nums);
    diff.increment(0, 0, 3);
    std::vector<int> result = diff.result();
    EXPECT_EQ(result[0], 8);
  }

  // 负数增量
  {
    std::vector<int> nums = {10, 10, 10};
    Difference diff(nums);
    diff.increment(0, 1, -5);
    std::vector<int> result = diff.result();
    std::vector<int> expected = {5, 5, 10};
    EXPECT_EQ(result, expected);
  }

  LOG(INFO) << "EdgeCases test passed";
}

} // namespace algorithm
