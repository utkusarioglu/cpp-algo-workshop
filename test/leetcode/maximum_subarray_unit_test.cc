#ifndef CAW_TEST_LEETCODE_MAXIMUM_SUBARRAY_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_MAXIMUM_SUBARRAY_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/maximum_subarray.cc"

namespace MaximumSubarray
{
  namespace UnitTests
  {
    struct TestCase {
      Vec params;
      int expected;
    };

    class MaximumSubarrayTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      MaximumSubarray, MaximumSubarrayTf,
      ::testing::Values(
        TestCase(Vec{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6), TestCase(Vec{1}, 1),
        TestCase(Vec{0}, 0), TestCase(Vec{5, 4, -1, 7, 8}, 23)
      )
    );

    TEST_P(MaximumSubarrayTf, window)
    {
      TestCase testCase = GetParam();
      MaximumSubarray m = MaximumSubarray();
      int response = m.worm(testCase.params);
      ASSERT_EQ(response, testCase.expected);
    }

    TEST_P(MaximumSubarrayTf, sums)
    {
      TestCase testCase = GetParam();
      MaximumSubarray m = MaximumSubarray();
      int response = m.sums(testCase.params);
      ASSERT_EQ(response, testCase.expected);
    }

    TEST_P(MaximumSubarrayTf, db)
    {
      TestCase testCase = GetParam();
      MaximumSubarray m = MaximumSubarray();
      int response = m.dp(testCase.params);
      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace MaximumSubarray

#endif /* CAW_TEST_LEETCODE_MAXIMUM_SUBARRAY_UNIT_TEST_CC_ */
