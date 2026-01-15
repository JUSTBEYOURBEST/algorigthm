#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <gtest/gtest.h>
#include <set>

namespace algorithm {
namespace test {

int lengthOfLongestSubstring(const std::string& s) {
  if (s.empty()) {
    return 0;
  }
  std::set<char> char_set;
  int left = 0;
  int right = 0;
  int length = s.size();
  int ans = 0;
  for (right = 0; right < length;) {
    if (char_set.count(s[right]) > 0) {
      ans = std::max(ans, right - left);
      char_set.erase(s[left]);
      ++left;
      continue;
    } else {
      char_set.insert(s[right]);
      ++right;
    }
  }
  return std::max(ans, right - left + 1);
}

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
TEST(StringTest, LongestSubStringWithoutRepeat) {
  std::string s = "abcabcbb";
  EXPECT_EQ(lengthOfLongestSubstring(s), 3);
  s = "bbbbb";
  EXPECT_EQ(lengthOfLongestSubstring(s), 1);
  s = "pwwkew";
  EXPECT_EQ(lengthOfLongestSubstring(s), 3);
}

} // namespace test
} // namespace algorithm
