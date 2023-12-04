#ifndef CAW_TEST_LEETCODE_MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <string>

#include "leetcode/minimum_window_substring.cc"

namespace MinimumWindowSubstring
{
  namespace UnitTests
  {

    struct TestCase {
      std::string s;
      std::string t;
      std::string expected;
    };

    class MinimumWindowSubstringTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      MinimumWindowSubstring, MinimumWindowSubstringTf,
      ::testing::Values(TestCase("ADOBECODEBANC", "ABC", "BANC"))
    );

    TEST_P(MinimumWindowSubstringTf, ChangeThis)
    {
      TestCase testCase = GetParam();
      MinimumWindowSubstring m = MinimumWindowSubstring();
      std::string response = m.minWindow(testCase.s, testCase.t);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace MinimumWindowSubstring

#endif /* CAW_TEST_LEETCODE_MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_CC_ */
