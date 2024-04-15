#ifndef CAW_TEST_MERGE_SORT_UNIT_TEST_CC_
#define CAW_TEST_MERGE_SORT_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <memory>

#include "sorting_algorithms/merge_sort.h"

namespace MergeSort
{
  namespace UnitTests
  {

    using IntVector = std::vector<int>;

    class MergeSortTestFixture : public ::testing::TestWithParam<IntVector>
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
      MergeSort, MergeSortTestFixture,
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

    TEST_P(MergeSortTestFixture, Recursive)
    {
      const IntVector param = GetParam();
      const IntVector expected =
        MergeSortTestFixture::produceSortedExpected(param);
      auto mergeSort = std::make_unique<MergeSort<int>>();
      auto response = mergeSort->recurse(param);

      ASSERT_EQ(response, expected);
    }

    TEST_P(MergeSortTestFixture, Loopy)
    {
      const IntVector param = GetParam();
      const IntVector expected =
        MergeSortTestFixture::produceSortedExpected(param);
      auto mergeSort = std::make_unique<MergeSort<int>>();
      auto response = mergeSort->loop(param);

      ASSERT_EQ(response, expected);
    }
  }  // namespace UnitTests
}  // namespace MergeSort

#endif /* CAW_TEST_MERGE_SORT_UNIT_TEST_CC_ */
