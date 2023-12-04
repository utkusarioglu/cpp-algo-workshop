#ifndef CAW_SRC_LEETCODE_VALID_ANAGRAM_CC_
#define CAW_SRC_LEETCODE_VALID_ANAGRAM_CC_

#include <string>
#include <unordered_set>

namespace ValidAnagram
{
  bool isAnagram(std::string s, std::string t)
  {
    std::unordered_set<char> difference;
    for (auto letter : s) {
      difference.insert(letter);
    }

    for (auto letter : t) {
      difference.erase(letter);
    }

    return difference.size() == 0;
  }
}  // namespace ValidAnagram

#endif /* CAW_SRC_LEETCODE_VALID_ANAGRAM_CC_ */
