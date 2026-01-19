//
// Created by sccloud on 4/21/25.
//
#include <bits/stdc++.h>

namespace algorithm {

template<typename T>
struct ListNode {
public:
  T val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

} // namespace algorithm
