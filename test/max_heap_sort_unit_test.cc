#ifndef CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_
#define CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_

#include <gtest/gtest.h>
#include <memory>

#include "../src/sorting_algorithms/max_heap_sort.h"

class MaxHeapSortTestFixture : public ::testing::TestWithParam<std::vector<int>>
{
protected:
  std::vector<int> param;
};

INSTANTIATE_TEST_SUITE_P(
    MaxHeapSort,
    MaxHeapSortTestFixture,
    ::testing::Values(
        std::vector<int>{1, 2, 3}));

TEST_P(MaxHeapSortTestFixture, Works)
{
  std::vector<int> param = GetParam();
  std::vector<int> expected = {3, 2, 1};
  std::unique_ptr<MaxHeapSort<int>> sorter = std::make_unique<MaxHeapSort<int>>();
  for (auto value : param)
  {
    sorter->insert(value);
  }
  std::vector<int> sorted = sorter->sort();

  // ASSERT_EQ(sorted.size(), param.size());
  ASSERT_EQ(sorted, expected);
}

#endif /* CAW_TEST_MAX_HEAP_SORT_UNIT_TEST_H_ */
