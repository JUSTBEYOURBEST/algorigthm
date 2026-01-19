#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <gtest/gtest.h>

#include "data_struct/utils/util.h"

namespace algorithm {
namespace test {

TEST(LinkListTest, util_function) {
  std::vector<int> nums = {1,2,3,4,5};
  ListNode<int>* head = algorithm::utils::create_linklist(nums);
  algorithm::utils::print_linklist(head);
}



TEST(LinkListTest, reverse_linked_list) {

}

} // namespace test
} // namespace algorithm
