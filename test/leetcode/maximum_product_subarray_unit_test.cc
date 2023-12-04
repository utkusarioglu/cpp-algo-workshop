#ifndef CAW_TEST_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/maximum_product_subarray.cc"

namespace MaximumProductSubarray
{
  namespace UnitTests
  {
    struct TestCase {
      Vec params;
      Response expected;
    };

    class MaximumProductSubarrayTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      MaximumProductSubarray, MaximumProductSubarrayTf,
      ::testing::Values(
        TestCase(Vec{2, 3, -2, 4}, 6), TestCase(Vec{-2, 0, -1}, 0)
      )
    );

    // TEST_P(MaximumProductSubarrayTf, loop)
    // {
    //   TestCase testCase = GetParam();
    //   MaximumProductSubarray m = MaximumProductSubarray();
    //   Response response = m.loop(testCase.params);

    //   ASSERT_EQ(response, testCase.expected);
    // }

    TEST_P(MaximumProductSubarrayTf, dp)
    {
      TestCase testCase = GetParam();
      auto m = MaximumProductSubarray();
      Response response = m.dp(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace MaximumProductSubarray

#endif /* CAW_TEST_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_UNIT_TEST_CC_ */
