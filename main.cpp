#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct DNode {
  int key_;
  int value_;
  DNode* prev_;
  DNode* next_;

  DNode()
    : key_(0), value_(0), prev_(nullptr), next_(nullptr) {}
  DNode(int key, int value)
      :  key_(key), value_(value), prev_(nullptr), next_(nullptr) {}
  DNode(int key, int value, DNode* prev, DNode* next)
    : key_(key), value_(value), prev_(prev), next_(next) {}
  ~DNode() {}
};

class LRUCache {
public:
  LRUCache(int capacity) {
    head_ = new DNode();
    tail_ = new DNode();
    size_ = capacity;
    head_->next_ = tail_;
    tail_->prev_ = head_;
  }

  int get(int key) {
    if (cache_.count(key)) {
      DNode* node = cache_[key];
      moveToHead(node);
      return node->value_;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (cache_.count(key)) {
      DNode* node = cache_[key];
      node->value_ = value;
      moveToHead(node);
    } else {
      DNode* node = new DNode(key, value);
      cache_.insert(std::make_pair(key, node));
      addToHead(node);
      if (cache_.size() > size_) {
        DNode* tail_node = tail_->prev_;
        cache_.erase(tail_node->key_);
        removeNode(tail_node);
        delete tail_node;
      }
    }
  }

  void moveToHead(DNode* node) {
    removeNode(node);
    addToHead(node);
  }
  void addToHead(DNode* node) {
    node->next_ = head_->next_;
    node->prev_ = head_;
    head_->next_->prev_ = node;
    head_->next_ = node;
  }
  void removeNode(DNode* node) {
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
  }
private:
  DNode* head_;
  DNode* tail_;
  int size_;
  std::unordered_map<int, DNode*> cache_;
};

// 区域和检索 - 数组不可变（前缀和）:https://leetcode.cn/problems/range-sum-query-immutable/description/
class NumArray {
public:
  NumArray(vector<int>& nums) {
    int sum = 0;
    presum.push_back(0);
    for (const int i : nums) {
      sum = sum + i;
      presum.push_back(sum);
    }
  }

  int sumRange(int left, int right) {
    return presum[right + 1] - presum[left];
  }

private:
  vector<int> presum;
};

// 二维区域和检索 - 矩阵不可变：https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
class NumMatrix {
public:
  vector<vector<int>> sum_matrix_;

  NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    sum_matrix_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    // 构建前缀和矩阵：sum_matrix_[i+1][j+1] 是从 (0,0) 到 (i,j) 的区域和
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum_matrix_[i + 1][j + 1] = matrix[i][j]
                                    + sum_matrix_[i][j + 1]
                                    + sum_matrix_[i + 1][j]
                                    - sum_matrix_[i][j];  // 避免重复计算
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum_matrix_[row2 + 1][col2 + 1]
           - sum_matrix_[row2 + 1][col1]
           - sum_matrix_[row1][col2 + 1]
           + sum_matrix_[row1][col1];
  }
};

class Difference {
public:
  Difference(vector<int>& nums) {
    length_ = nums.size();
    different_ = vector<int>(length_, 0);
    int diff = 0;
    for (int i = 0; i < length_; ++i) {
      different_[i] = diff = nums[i] - diff;
    }
  }

  void increment(int left, int right, int val) {
    different_[left] += val;
    if (right + 1 < different_.size()) {
      different_[right + 1] -= val;
    }
  }

  vector<int> result() {
    vector<int> res = vector<int>(different_.size());
    int sum = 0;
    for (int i = 0; i < length_; ++i) {
      sum += different_[i];
      res[i] = sum;
    }
    return res;
  }

private:
  int length_;
  vector<int> different_;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class Solution {
public:
  Solution() {}
  ~Solution() {}
  // https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = 0;
    int result = 1;
    std::set<char> ch_set;
    for (int i = 0; i < s.length();) {
      if (ch_set.count(s.at(i)) == 0) {
        ++end;
        ch_set.insert(s.at(i));
        ++i;
      } else {
        result = std::max(result, end - start);
        ch_set.erase(s.at(start));
        ++start;
      }
    }
    return std::max(result, end - start);
  }
  // https://leetcode.cn/problems/reverse-linked-list/
  ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  // 合并有序链表：https://leetcode.cn/problems/merge-two-sorted-lists/description/
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy_head = new ListNode();
    ListNode* current_node = dummy_head;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        current_node->next = list1;
        list1 = list1->next;
      } else {
        current_node->next = list2;
        list2 = list2->next;
      }
      current_node = current_node->next;
    }
    current_node->next = list1 == nullptr ? list2 : list1;
    return dummy_head->next;
  }

//  方法一：
//  ListNode* mergeKLists(vector<ListNode*>& lists) {
//    if (lists.empty() || lists.size() < 2) {
//      return lists.empty() ? new ListNode() : lists[0];
//    }
//    ListNode* list1 = lists[0];
//    for (int i = 1; i < lists.size(); ++i) {
//      list1 = mergeTwoLists(list1, lists[i]);
//    }
//    return list1;
//  }
  // 合并k个有序链表：https://leetcode.cn/problems/merge-k-sorted-lists/description/
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    // 虚拟头结点
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    // 优先级队列，最小堆
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > pq(cmp);
    // 将 k 个链表的头结点加入最小堆
    for (ListNode* head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    while (!pq.empty()) {
      // 获取最小节点，接到结果链表中
      ListNode* node = pq.top();
      pq.pop();
      p->next = node;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
      // p 指针不断前进
      p = p->next;
    }
    return dummy->next;
  }

  // 分隔链表：https://leetcode.cn/problems/partition-list/description/
  ListNode* partition(ListNode* head, int x) {
    ListNode* min_dummy_head = new ListNode();
    ListNode* max_dummy_head = new ListNode();
    ListNode* current_min_node = min_dummy_head;
    ListNode* current_max_node = max_dummy_head;
    while (head != nullptr) {
      if (head->val < x) {
        current_min_node->next = head;
        current_min_node = current_min_node->next;
        head = head->next;
        current_min_node->next=nullptr;
      } else {
        current_max_node->next = head;
        current_max_node = current_max_node->next;
        head = head->next;
        current_max_node->next = nullptr;
      }
    }
    current_min_node->next = max_dummy_head->next;
    return min_dummy_head->next;
  }

  // 删除链表的倒数第 N 个结点: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = head;
    ListNode* second = dummy;
    for (int i = 0; i < n; ++i) {
      first = first->next;
    }
    while (first) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
  }

  int maxSubArray(vector<int>& nums) {
    int min = nums[0];
    int max = 0;
    int sum = 0;
    for (int num : nums) {
      sum += num;
      min = std::min(min, sum);
      max = std::max(max, sum);
    }
    return min < 0 ? max - min : max;
  }

  // 目标和：https://leetcode.cn/problems/target-sum/description/?envType=problem-list-v2&envId=dynamic-programming
  int findTargetSumWays(vector<int>& nums, int target) {
    return subSolution(nums, 0, target);
  }

  int subSolution(vector<int>& nums, int index, int target) {
    if (index == nums.size() - 1) {
      return (target == nums[index]) + (target == -nums[index]);
    }

    return subSolution(nums, index + 1, target + nums[index]) + subSolution(nums, index + 1 ,target - nums[index]);
  }

//  int findTargetSumWays(vector<int>& nums, int target) {
//    int sum = 0;
//    for (int& num : nums) {
//      sum += num;
//    }
//    int diff = sum - target;
//    if (diff < 0 || diff % 2 != 0) {
//      return 0;
//    }
//    int neg = diff / 2;
//    vector<int> dp(neg + 1);
//    dp[0] = 1;
//    for (int& num : nums) {
//      for (int j = neg; j >= num; j--) {
//        dp[j] += dp[j - num];
//      }
//    }
//    return dp[neg];
//  }

  // 删除有序数组中的重复项: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int prenums = nums[0];
    int slow = 0;
    for (int fast = 1; fast < nums.size(); ++fast) {
      if (nums[fast] != prenums) {
        prenums = nums[fast];
        nums[++slow] = nums[fast];
      }
    }
    return slow + 1;
  }

  // 移除元素：https://leetcode.cn/problems/remove-element/
  int removeElement(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        ++slow;
      }
      ++fast;
    }

    return slow;
  }

  // 两数之和 II - 输入有序数组: https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
  vector<int> twoSum(vector<int>& numbers, int target) {
    int head = 0; int tail = numbers.size() - 1;
    while (head != tail) {
      if (numbers[head] + numbers[tail] > target) {
        --tail;
        continue;
      } else if (numbers[head] + numbers[tail] < target) {
        ++head;
        continue;
      } else {
        break;
      }
    }
    return {head, tail};
  }
};

int main() {
  Solution* solution = new Solution();
  vector<int> nums = {0,1,2,2,3,0,4,2};
  cout << solution->removeElement(nums, 2) << endl;
  for (int num : nums) {
    cout << num << " ";
  }
}
