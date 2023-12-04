#ifndef CAW_TEST_MIN_HEAP_UNIT_TEST_CC_
#define CAW_TEST_MIN_HEAP_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <memory>
#include <vector>

#include "data_structures/min_heap.h"

namespace Heap
{
  namespace MinHeap
  {
    namespace UnitTests
    {

      using IntVector = std::vector<int>;

      class MinHeapTestFixture : public ::testing::TestWithParam<IntVector>
      {
      public:
        static const IntVector produceExpected(const IntVector param)
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
        MinHeap, MinHeapTestFixture,
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

      TEST_P(MinHeapTestFixture, ReturnsExpectedHead)
      {
        const IntVector param = GetParam();
        const auto minHeap = std::make_unique<MinHeap<int>>();
        for (auto elem : param) {
          minHeap->insert(elem);
        }
        const auto [responseHeadValue, responseIsError] = minHeap->getHead();
        const int expectedHeadValue =
          param.size() == 0 ? 0 : *std::min_element(param.begin(), param.end());
        const bool expectedIsError = param.size() == 0;

        ASSERT_EQ(responseIsError, expectedIsError);
        ASSERT_EQ(responseHeadValue, expectedHeadValue);
      }

      TEST_P(MinHeapTestFixture, SortsElemsAsExpected)
      {
        const IntVector param = GetParam();
        const auto minHeap = std::make_unique<MinHeap<int>>();
        for (auto elem : param) {
          minHeap->insert(elem);
        }
        const IntVector expected = MinHeapTestFixture::produceExpected(param);
        IntVector response;
        while (!std::get<1>(minHeap->getHead())) {
          const auto [headValue, _isError] = minHeap->popHead();
          response.push_back(headValue);
        }

        ASSERT_EQ(expected.size(), response.size());
        ASSERT_EQ(expected, response);
      }

    }  // namespace UnitTests
  }    // namespace MinHeap

}  // namespace Heap

#endif /* CAW_TEST_MIN_HEAP_UNIT_TEST_CC_ */
