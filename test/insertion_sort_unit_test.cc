#ifndef CAW_TEST_INSERTION_SORT_UNIT_TEST_CC_
#define CAW_TEST_INSERTION_SORT_UNIT_TEST_CC_

#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

#include "../src/sorting_algorithms/insertion_sort.h"

using IntVector = std::vector<int>;

class InsertionSortTestFixture : public ::testing::TestWithParam<IntVector>
{
public:
  static const IntVector produceReverseSortedParams(const IntVector params)
  {
    std::vector<int> expected;
    std::copy(params.begin(), params.end(), std::back_inserter(expected));
    std::sort(expected.begin(), expected.end());
    return expected;
  }

protected:
  IntVector param;
};

INSTANTIATE_TEST_SUITE_P(
    InsertionSort,
    InsertionSortTestFixture,
    ::testing::Values(
        IntVector{3, 2, 1},
        IntVector{3, 2, 1, 6},
        IntVector{3, 2, 1, 1, 6},
        IntVector{3, 2, 100, 1, 1, 6},
        IntVector{3, 2, 100, 1, 1, 6, -5}));

TEST_P(InsertionSortTestFixture, Handles321)
{
  auto instance = new InsertionSort();
  IntVector params = GetParam();
  auto response = instance->loop(params);
  IntVector expected =
      InsertionSortTestFixture::produceReverseSortedParams(params);

  ASSERT_EQ(response, expected);
}

#endif /* CAW_TEST_INSERTION_SORT_UNIT_TEST_CC_ */
