#ifndef CAW_TEST_MAX_HEAP_UNIT_TEST_CC_
#define CAW_TEST_MAX_HEAP_UNIT_TEST_CC_

#include <gtest/gtest.h>
#include <memory>
#include <algorithm>
#include <utility>

#include "../src/data_structures/max_heap.h"

class MaxHeapGetHeadTestFixture : public ::testing::TestWithParam<std::vector<int>>
{
protected:
  std::vector<int> param;
};

INSTANTIATE_TEST_SUITE_P(
    MaxHeap,
    MaxHeapGetHeadTestFixture,
    ::testing::Values(
        std::vector<int>{1, 2, 3},
        std::vector<int>{3, 2, 1},
        std::vector<int>{
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
        std::vector<int>{2, 0, 12, 100, 3, 26913, 5, 1, 3, 4},
        std::vector<int>{100, 101, 102, 103, 0, 10000, -151},
        std::vector<int>{-1, -2, -3, -4},
        std::vector<int>{1, 2, 3, 4, -1, 6, 4, 1},
        std::vector<int>{4, 4, 4, 4, 4, 4, 4}));

TEST_P(MaxHeapGetHeadTestFixture, CorrectHead)
{
  std::vector<int> param = GetParam();
  int expected = *std::max_element(param.begin(), param.end());
  auto h = new MaxHeap<int>();
  for (auto value : param)
  {
    h->insert(value);
  }

  auto [headValue, isError] = h->getHead();
  ASSERT_EQ(headValue, expected);
  ASSERT_EQ(isError, false);
}

// TEST_P(MaxHeapGetHeadTestFixture, PopHead)
// {
//   std::vector<int> param = GetParam();
//   std::vector<int> expected;
//   std::copy(param.begin(), param.end(), std::back_inserter(expected));
//   std::sort(expected.begin(), expected.end(), std::greater<int>());
//   auto h = std::make_unique<MaxHeap<int>>();
//   for (auto value : param)
//   {
//     h->insert(value);
//   }
//   std::vector<int> sorted;
//   while (!std::get<1>(h->getHead()))
//   {
//     auto [headValue, isError] = h->popHead();
//     sorted.push_back(headValue);
//   }
//   ASSERT_EQ(sorted.size(), expected.size());
//   ASSERT_EQ(sorted, expected);
// }

#endif /* CAW_TEST_MAX_HEAP_UNIT_TEST_CC_ */
