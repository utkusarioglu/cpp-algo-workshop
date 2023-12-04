#ifndef CAW_TEST_LEETCODE_VALID_ANAGRAM_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_VALID_ANAGRAM_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/valid_anagram.cc"

namespace ValidAnagram
{
  namespace UnitTests
  {
    struct TestCase {
      std::string s;
      std::string t;
      bool expected;
    };

    class ValidAnagramTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      ValidAnagram, ValidAnagramTf,
      ::testing::Values(
        TestCase("anagram", "nagaram", true), TestCase("rat", "car", false),
        TestCase("a", "b", false), TestCase("a", "a", true),
        TestCase("aa", "a", true), TestCase("aab", "ab", true),
        TestCase("baa", "ab", true), TestCase("baa", "a", false),
        TestCase("baa", "b", false), TestCase("baab", "b", false)
      )
    );

    TEST_P(ValidAnagramTf, Works)
    {
      TestCase testCase = GetParam();
      bool response = isAnagram(testCase.s, testCase.t);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace ValidAnagram

#endif /* CAW_TEST_LEETCODE_VALID_ANAGRAM_UNIT_TEST_CC_ */
