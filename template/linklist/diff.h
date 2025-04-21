//
// Created by sccloud on 4/21/25.
//
#include <bits/stdc++.h>

using namespace std;
#ifndef CPP_DIFF_H
#define CPP_DIFF_H

class Difference {
  // 差分数组
  vector<int> diff;

public:
  Difference(const vector<int>& nums) {
    assert(!nums.empty());
    diff.resize(nums.size());
    // 构造差分数组
    diff[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      diff[i] = nums[i] - nums[i - 1];
    }
  }

  // 给闭区间 [i, j] 增加 val（可以是负数）
  void increment(int i, int j, int val) {
    diff[i] += val;
    if (j + 1 < diff.size()) {
      diff[j + 1] -= val;
    }
  }

  vector<int> result() {
    vector<int> res(diff.size());
    // 根据差分数组构造结果数组
    res[0] = diff[0];
    for (size_t i = 1; i < diff.size(); ++i) {
      res[i] = res[i - 1] + diff[i];
    }
    return res;
  }
};

#endif //CPP_DIFF_H
