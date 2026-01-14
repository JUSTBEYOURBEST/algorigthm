//
// Created by sccloud on 4/21/25.
//

#ifndef CPP_NUMARRAYS_H
#define CPP_NUMARRAYS_H


#include <vector>

class NumArray {
  // 前缀和数组
  std::vector<int> preSum;

  // 输入一个数组，构造前缀和
public:
  NumArray(std::vector<int>& nums) {
    // preSum[0] = 0，便于计算累加和
    preSum.resize(nums.size() + 1);
    // 计算 nums 的累加和
    for (int i = 1; i < preSum.size(); i++) {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
  }

  // 查询闭区间 [left, right] 的累加和
  int sumRange(int left, int right) {
    return preSum[right + 1] - preSum[left];
  }
};


#endif //CPP_NUMARRAYS_H
