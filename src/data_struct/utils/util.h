#include "data_struct/linklist/diff.h"
#include "data_struct/linklist/list_node.h"
#include "data_struct/linklist/num_arrays.h"

namespace algorithm {
namespace utils {

// linklist functions
ListNode<int>* create_linklist(const std::vector<int>& nums, bool with_dummy = true);

void print_linklist(const ListNode<int>* head);

} // namespace utils
} // namespace algorithm
