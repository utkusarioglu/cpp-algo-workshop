#ifndef CAW_TEST_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_UNIT_TEST_H_
#define CAW_TEST_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_UNIT_TEST_H_

#include <gtest/gtest.h>

#include <vector>

#include "leetcode/product_of_array_except_self.cc"

namespace ProductOfArrayExceptSelf
{
  namespace UnitTests
  {

    struct TestCase {
      Vec params;
      Vec expected;
    };

    class ProductOfArrayExceptSelfTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      ProductOfArrayExceptSelf, ProductOfArrayExceptSelfTf,
      ::testing::Values(TestCase(Vec{1, 2, 3, 4}, Vec{24, 12, 8, 6})
                        // ,
                        // TestCase(Vec{-1, 1, 0, -3, 0}, Vec{0, 0, 0, 0, 0}),
                        // TestCase(Vec{-1, 1, 0, -3, 3}, Vec{0, 0, 9, 0, 0})
      )
    );

    // TEST_P(ProductOfArrayExceptSelfTf, window)
    // {
    //   TestCase testCase = GetParam();
    //   ProductOfArrayExceptSelf p = ProductOfArrayExceptSelf();
    //   Vec response = p.reverseWindow(testCase.params);

    //   ASSERT_EQ(response, testCase.expected);
    // }

    TEST_P(ProductOfArrayExceptSelfTf, lowSpace)
    {
      TestCase testCase = GetParam();
      ProductOfArrayExceptSelf p = ProductOfArrayExceptSelf();
      Vec response = p.lowSpace(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace ProductOfArrayExceptSelf

#endif /* CAW_TEST_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_UNIT_TEST_H_ */
