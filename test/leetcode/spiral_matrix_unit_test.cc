#ifndef CAW_TEST_LEETCODE_SPIRAL_MATRIX_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_SPIRAL_MATRIX_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <vector>

#include "leetcode/spiral_matrix.cc"

namespace SpiralMatrix
{
  namespace UnitTests
  {
    struct TestCase {
      Matrix param;
      Linearized expected;
    };

    class SpiralMatrixTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      SpiralMatrix, SpiralMatrixTf,
      ::testing::Values(
        TestCase(
          Matrix{Row{1, 2, 3}, Row{4, 5, 6}, Row{7, 8, 9}},
          Linearized{1, 2, 3, 6, 9, 8, 7, 4, 5}
        ),
        TestCase(Matrix{Row{1, 2}, Row{3, 4}}, Linearized{1, 2, 4, 3}),
        TestCase(
          Matrix{
            Row{1, 2, 3, 4}, Row{5, 6, 7, 8}, Row{9, 10, 11, 12},
            Row{13, 14, 15, 16}
          },
          Linearized{1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10}
        )
      )
    );

    TEST_P(SpiralMatrixTf, damn)
    {
      TestCase testCase = GetParam();
      SpiralMatrix p = SpiralMatrix();
      Linearized response = p.handle(testCase.param);
      ASSERT_EQ(response, testCase.expected);
    }
  }  // namespace UnitTests
}  // namespace SpiralMatrix

#endif /* CAW_TEST_LEETCODE_SPIRAL_MATRIX_UNIT_TEST_CC_ */
