#ifndef CAW_TEST_QUICK_SORT_UNIT_TEST_CC_
#define CAW_TEST_QUICK_SORT_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "sorting_algorithms/quick_sort.h"

namespace QuickSort
{
  namespace UnitTests
  {

    using IntVector = std::vector<int>;

    class QuickSortTestFixture : public ::testing::TestWithParam<IntVector>
    {
    public:
      const IntVector produceSortedParams(const IntVector unsorted)
      {
        IntVector expected;
        std::copy(
          unsorted.begin(), unsorted.end(), std::back_inserter(expected)
        );
        std::sort(expected.begin(), expected.end());
        return expected;
      }

    protected:
      IntVector param;
    };

    INSTANTIATE_TEST_SUITE_P(
      QuickSort, QuickSortTestFixture,
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

    TEST_P(QuickSortTestFixture, Works)
    {
      IntVector param = GetParam();
      IntVector expected = QuickSortTestFixture::produceSortedParams(param);
      std::unique_ptr<QuickSort<int>> sorter =
        std::make_unique<QuickSort<int>>();
      IntVector sorted = sorter->sort(param);

      ASSERT_EQ(sorted, expected);
    }

  }  // namespace UnitTests
}  // namespace QuickSort

#endif /* CAW_TEST_QUICK_SORT_UNIT_TEST_CC_ */
