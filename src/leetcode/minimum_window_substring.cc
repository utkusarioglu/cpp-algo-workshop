#ifndef CAW_SRC_LEETCODE_MINIMUM_WINDOW_SUBSTRING_CC_
#define CAW_SRC_LEETCODE_MINIMUM_WINDOW_SUBSTRING_CC_

#include <functional>
#include <string>

namespace MinimumWindowSubstring
{
  class MinimumWindowSubstring
  {
  public:
    std::string minWindow(std::string s, std::string t)
    {
      using Contains = std::function<bool()>;
      // what if t is longer than s?
      // what if t and s are the same length?
      size_t r = t.size();
      size_t l = 0;
      size_t sSize = s.size();
      std::string currentS = s.substr(l, r);
      std::string smallest = "";

      Contains contains = [&currentS, &t]() {
        for (size_t ti = 0; ti < t.size(); ti++) {
          bool included = false;
          for (size_t s = 0; s < currentS.size(); s++) {
            if (t[ti] == currentS[s]) {
              included = true;
            }
          }
          if (included == false) {
            return false;
          }
        }
        return true;
      };

      while (r < sSize && l < r) {
        if (!contains()) {
          r += 1;
          currentS.push_back(s[r]);
          continue;
        }
        if (currentS.size() < smallest.size()) {
          smallest = currentS;
        }
        while (contains()) {
          smallest = currentS;
          l += 1;
          currentS = currentS.substr(1);
        }
      }

      return smallest;
    }
  };

}  // namespace MinimumWindowSubstring

#endif /* CAW_SRC_LEETCODE_MINIMUM_WINDOW_SUBSTRING_CC_ */
