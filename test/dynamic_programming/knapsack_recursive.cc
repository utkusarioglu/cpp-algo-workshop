#ifndef CAW_TEST_DYNAMIC_PROGRAMMING_RECURSIVE_CC_
#define CAW_TEST_DYNAMIC_PROGRAMMING_RECURSIVE_CC_

#include <gtest/gtest.h>

#include <utility>

#include "dynamic_programming/knapsack.h"
#include "knapsack_test_setup.cc"

namespace Knapsack
{
  namespace UnitTests
  {
    namespace Recursive
    {
      class KnapsackRecursiveTf : public ::testing::TestWithParam<TestCase>
      {
      protected:
        TestCase param;
      };

      INSTANTIATE_TEST_SUITE_P(
        Knapsack, KnapsackRecursiveTf,
        ::testing::Values(TestCase(
          VecItems{
            Item("a", 3, 5.0), Item("b", 4, 6.0), Item("c", 5, 3.0),
            Item("d", 2, 1.0)
          },
          7.0
        ))
      );

      TEST_P(KnapsackRecursiveTf, Works)
      {
        const TestCase testCase = GetParam();
        Knapsack *k = new Knapsack(testCase.first);
        auto response = k->recursive(7.0);
        uint expected = testCase.second;

        ASSERT_EQ(response, expected);
      }
    }  // namespace Recursive
  }    // namespace UnitTests
}  // namespace Knapsack

#endif /* CAW_TEST_DYNAMIC_PROGRAMMING_RECURSIVE_CC_ */
