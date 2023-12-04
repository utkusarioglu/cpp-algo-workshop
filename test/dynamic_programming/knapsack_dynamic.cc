#ifndef CAW_TEST_DYNAMIC_PROGRAMMING_DYNAMIC_CC_
#define CAW_TEST_DYNAMIC_PROGRAMMING_DYNAMIC_CC_

#include <gtest/gtest.h>

#include <utility>

#include "dynamic_programming/knapsack.h"
#include "knapsack_test_setup.cc"

namespace Knapsack
{
  namespace UnitTests
  {
    namespace Dynamic
    {
      class KnapsackDynamicTf : public ::testing::TestWithParam<TestCase>
      {
      protected:
        TestCase param;
      };

      INSTANTIATE_TEST_SUITE_P(
        Knapsack, KnapsackDynamicTf,
        ::testing::Values(TestCase(
          VecItems{
            Item("a", 3, 5.0), Item("b", 4, 6.0), Item("c", 5, 3.0),
            Item("d", 2, 1.0)
          },
          7.0
        ))
      );

      TEST_P(KnapsackDynamicTf, Works)
      {
        const TestCase testCase = GetParam();
        Knapsack *k = new Knapsack(testCase.first);
        auto response = k->memoized(7.0);
        uint expected = testCase.second;

        ASSERT_EQ(response, expected);
      }

    }  // namespace Dynamic
  }    // namespace UnitTests
}  // namespace Knapsack

#endif /* CAW_TEST_DYNAMIC_PROGRAMMING_DYNAMIC_CC_ */
