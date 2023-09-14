#ifndef CAW_TEST_MAX_HEAP_UNIT_TEST_CC_
#define CAW_TEST_MAX_HEAP_UNIT_TEST_CC_

#include <memory>
#include <algorithm>
#include <utility>

#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

#include "../src/data_structures/max_heap.h"

using IntVector = std::vector<int>;

class MaxHeapGetHeadTestFixture : public ::testing::TestWithParam<IntVector>
{
public:
  MaxHeapGetHeadTestFixture()
  {
    spdlog::set_level(spdlog::level::debug);
  }

  static IntVector produceSortedParams(const IntVector param)
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
    MaxHeap,
    MaxHeapGetHeadTestFixture,
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

TEST_P(MaxHeapGetHeadTestFixture, CorrectHead)
{
  IntVector param = GetParam();
  int expectedValue = param.size() == 0
                          ? std::numeric_limits<int>::min()
                          : *std::max_element(param.begin(), param.end());
  int expectedIsError = param.size() == 0;
  auto h = new MaxHeap<int>();
  for (auto value : param)
  {
    h->insert(value);
  }
  auto [headValue, isError] = h->getHead();
  ASSERT_EQ(headValue, expectedValue);
  ASSERT_EQ(isError, expectedIsError);
}

TEST_P(MaxHeapGetHeadTestFixture, PopHead)
{
  IntVector param = GetParam();
  IntVector expected = MaxHeapGetHeadTestFixture::produceSortedParams(param);
  auto maxHeap = std::make_unique<MaxHeap<int>>();
  for (auto value : param)
  {
    maxHeap->insert(value);
  }
  IntVector sorted;
  while (!std::get<1>(maxHeap->getHead()))
  {
    auto [headValue, isError] = maxHeap->popHead();
    sorted.push_back(headValue);
  }
  ASSERT_EQ(sorted.size(), expected.size());
  ASSERT_EQ(sorted, expected);
}

#endif /* CAW_TEST_MAX_HEAP_UNIT_TEST_CC_ */
