#ifndef CAW_TEST_SEARCH_BINARY_SEARCH_UNIT_TEST_CC_
#define CAW_TEST_SEARCH_BINARY_SEARCH_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "search/binary_search.h"

namespace BinarySearch
{
  namespace UnitTest
  {
    template <typename T>
    struct TestCase {
      std::vector<T> in;
      T target;
      size_t expected;
    };

    class BinarySearchTfInt : public ::testing::TestWithParam<TestCase<int>>
    {
    protected:
      TestCase<int> param;
    };

    INSTANTIATE_TEST_SUITE_P(
      binarySearch, BinarySearchTfInt,
      ::testing::Values(
        // happy
        TestCase<int>(std::vector<int>{0, 1, 2, 3}, 0, 0),
        TestCase<int>(std::vector<int>{1, 2, 3}, 1, 0),
        TestCase<int>(std::vector<int>{1, 2, 3}, 2, 1),
        TestCase<int>(std::vector<int>{1, 2, 3}, 3, 2),
        TestCase<int>(std::vector<int>{10, 20, 30, 40, 50, 60, 70}, 20, 1),

        // Empty
        TestCase<int>(std::vector<int>{}, 0, -1),
        TestCase<int>(std::vector<int>{}, 4, -1),

        // // // // Non-member
        TestCase<int>(std::vector<int>{1, 2, 3}, 4, -1),
        TestCase<int>(std::vector<int>{1, 2, 3}, 0, -1)
      )
    );

    TEST_P(BinarySearchTfInt, Loop)
    {
      const TestCase testCase = GetParam();
      const size_t res = binarySearchLoop(testCase.in, testCase.target);

      ASSERT_EQ(res, testCase.expected);
    };

    TEST_P(BinarySearchTfInt, Recursive)
    {
      const TestCase testCase = GetParam();
      const size_t res = binarySearchRecursive(testCase.in, testCase.target);

      ASSERT_EQ(res, testCase.expected);
    };
  }  // namespace UnitTest
}  // namespace BinarySearch

#endif /* CAW_TEST_SEARCH_BINARY_SEARCH_UNIT_TEST_CC_ */
