#ifndef CAW_TEST_LEETCODE_TWO_SUM_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_TWO_SUM_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "leetcode/two_sum.h"

namespace TwoSum
{
  namespace UnitTests
  {

    struct TestCase {
      TwoSumsParams params;
      Response expected;
    };

    class TwoSumTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      TwoSum, TwoSumTf,
      ::testing::Values(
        TestCase(
          TwoSumsParams(std::vector<int>{2, 7, 11, 15}, 9), Response(0, 1)
        ),
        TestCase(TwoSumsParams(std::vector<int>{3, 2, 4}, 6), Response(1, 2)),
        TestCase(TwoSumsParams(std::vector<int>{3, 3}, 6), Response(0, 1))
      )
    );

    TEST_P(TwoSumTf, doubleLoop)
    {
      TestCase testCase = GetParam();
      TwoSum t = TwoSum<int>();
      Response response = t.doubleLoop(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

    TEST_P(TwoSumTf, mapped)
    {
      TestCase testCase = GetParam();
      auto t = TwoSum<int>();
      Response response = t.mapped(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace TwoSum

#endif /* CAW_TEST_LEETCODE_TWO_SUM_UNIT_TEST_CC_ */
