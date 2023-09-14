#ifndef CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_
#define CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_

#include <gtest/gtest.h>
#include <memory>

#include "../src/sorting_algorithms/max_heap_sort.h"

using IntVector = std::vector<int>;

class MaxHeapSortTestFixture : public ::testing::TestWithParam<IntVector>
{
public:
  static const IntVector produceSortedParams(const IntVector param)
  {
    IntVector expected;
    std::copy(param.begin(), param.end(), std::back_inserter(expected));
    std::sort(expected.begin(), expected.end(), std::greater<int>());
    return expected;
  }

protected:
  IntVector param;
};

INSTANTIATE_TEST_SUITE_P(
    MaxHeapSort,
    MaxHeapSortTestFixture,
    ::testing::Values(
        IntVector{},
        IntVector{1},
        IntVector{1, 2},
        IntVector{1, 2, 3},
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
        IntVector{-1, -2, -3, -4},
        IntVector{1, 2, 3, 4, -1, 6, 4, 1},
        IntVector{4, 4, 4, 4, 4, 4, 4}));

TEST_P(MaxHeapSortTestFixture, Works)
{
  IntVector param = GetParam();
  IntVector expected = MaxHeapSortTestFixture::produceSortedParams(param);
  std::unique_ptr<MaxHeapSort<int>> sorter = std::make_unique<MaxHeapSort<int>>();
  for (auto value : param)
  {
    sorter->insert(value);
  }
  IntVector sorted = sorter->sort();

  ASSERT_EQ(sorted.size(), param.size());
  ASSERT_EQ(sorted, expected);
}

#endif /* CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_ */
