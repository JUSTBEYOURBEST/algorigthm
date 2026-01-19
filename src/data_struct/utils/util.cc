#include "data_struct/utils/util.h"
#include <iostream>

namespace algorithm {
namespace utils {

// linklist functions
ListNode<int>* create_linklist(const std::vector<int>& nums, bool with_dummy) {
  ListNode<int> dummy;
  ListNode<int>* cur = &dummy;
  for (int i : nums) {
    cur->next = new ListNode<int>(i);
    cur = cur->next;
  }
  return dummy.next;
}

void print_linklist(const ListNode<int>* head) {
  while (head) {
    std::cout << head->val << "->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

} // namespace utils
} // namespace algorithm
