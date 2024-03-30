#ifndef CAW_TEST_DATA_STRUCTURES_FENWICK_TREE_UNIT_TEST_CC_
#define CAW_TEST_DATA_STRUCTURES_FENWICK_TREE_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "data_structures/fenwick_tree.cc"

namespace FenwickTree
{
  namespace UnitTests
  {
    namespace SingleIndex
    {
      struct TestCase {
        Values input;
        size_t index;
        Value expected;
      };

      class FenwickTreeTf : public ::testing::TestWithParam<TestCase>
      {
      protected:
        TestCase params;
      };

      INSTANTIATE_TEST_SUITE_P(
        FenwickTree, FenwickTreeTf,
        ::testing::Values(
          TestCase(Values{1, 3, 10}, 0, 1), TestCase(Values{1, 3, 10}, 1, 4),
          TestCase(Values{1, 3, 10}, 2, 14),
          TestCase(Values{3, 5, 7, 9, 11}, 3, 24)
        )
      );

      TEST_P(FenwickTreeTf, sumSingleIndex)
      {
        TestCase testCase = GetParam();
        FenwickTree f = FenwickTree(testCase.input.size());
        for (size_t i = 0; i < testCase.input.size(); i++) {
          f.add(i, testCase.input[i]);
        }
        Value response = f.sum(testCase.index);

        ASSERT_EQ(response, testCase.expected);
      }
    }  // namespace SingleIndex
  }    // namespace UnitTests
}  // namespace FenwickTree

#endif /* CAW_TEST_DATA_STRUCTURES_FENWICK_TREE_UNIT_TEST_CC_ */
