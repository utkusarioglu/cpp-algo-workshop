#ifndef CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_
#define CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_

#include <algorithm>
#include <gtest/gtest.h>

#include "../src/sorting_algorithms/counting_sort.h"

using IntVector = std::vector<int>;

class CountingSortTestFixture : public ::testing::TestWithParam<IntVector>
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
  IntVector params;
};

INSTANTIATE_TEST_SUITE_P(
    CountingSort,
    CountingSortTestFixture,
    ::testing::Values(
        IntVector{3, 2, 1},
        IntVector{3, 2, 1, 6},
        IntVector{3, 2, 1, 1, 6},
        IntVector{3, 2, 100, 1, 1, 6},
        IntVector{3, 2, 100, 1, 1, 6, -5}));

TEST_P(CountingSortTestFixture, Handles321)
{
  auto instance = new CountingSort();
  std::vector<int> params = GetParam();
  auto response = instance->loop(params);
  auto expected = CountingSortTestFixture::produceReverseSortedParams(params);

  ASSERT_EQ(response, expected);
}

#endif /* CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_ */
