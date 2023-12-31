#ifndef CAW_TEST_BUBBLE_SORT_UNIT_TEST_CC_
#define CAW_TEST_BUBBLE_SORT_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <memory>
#include <vector>

#include "sorting_algorithms/bubble_sort.h"

namespace BubbleSort
{
  namespace UnitTests
  {

    using IntVector = std::vector<int>;

    class BubbleSortTestFixture : public ::testing::TestWithParam<IntVector>
    {
    public:
      static const IntVector produceSortedExpected(const IntVector param)
      {
        IntVector expected;
        std::copy(param.begin(), param.end(), std::back_inserter(expected));
        std::sort(expected.begin(), expected.end());
        return expected;
      }

    protected:
      IntVector param;
    };

    INSTANTIATE_TEST_SUITE_P(
      BubbleSort, BubbleSortTestFixture,
      ::testing::Values(
        IntVector{}, IntVector{1}, IntVector{1, 2}, IntVector{1, 2, 3},
        IntVector{3, 2, 1},
        IntVector{
          3,
          5,
          1,
          7,
          55,
          2,
          4,
          8,
          77,
          4,
          3,
          5,
        },
        IntVector{2, 0, 12, 100, 3, 26913, 5, 1, 3, 4},
        IntVector{100, 101, 102, 103, 0, 10000, -151},
        IntVector{-1, -2, -3, -4}, IntVector{1, 2, 3, 4, -1, 6, 4, 1},
        IntVector{4, 4, 4, 4, 4, 4, 4}
      )
    );

    TEST_P(BubbleSortTestFixture, Inserts)
    {
      const IntVector param = GetParam();
      const IntVector expected =
        BubbleSortTestFixture::produceSortedExpected(param);
      const auto bubbleSort = std::make_unique<BubbleSort<int>>();
      const auto response = bubbleSort->sort(param);

      ASSERT_EQ(response.size(), expected.size());
      ASSERT_EQ(response, expected);
    }

    TEST_P(BubbleSortTestFixture, LoopsInReverse)
    {
      const IntVector param = GetParam();
      const IntVector expected =
        BubbleSortTestFixture::produceSortedExpected(param);
      const auto bubbleSort = std::make_unique<BubbleSort<int>>();
      const auto response = bubbleSort->startFromReverse(param);

      ASSERT_EQ(response.size(), expected.size());
      ASSERT_EQ(response, expected);
    }

  }  // namespace UnitTests
}  // namespace BubbleSort

#endif /* CAW_TEST_BUBBLE_SORT_UNIT_TEST_CC_ */
