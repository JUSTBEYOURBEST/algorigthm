#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LRUCache {
public:
  LRUCache(int capacity) {

  }

  int get(int key) {

  }

  void put(int key, int value) {

  }
private:

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
};

int main() {
  Solution* solution = new Solution();
  std::vector<int> nums{5,4,-1,7,8};
  std::cout << solution->maxSubArray(nums);
}
