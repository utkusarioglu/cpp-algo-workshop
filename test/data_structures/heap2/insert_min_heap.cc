#ifndef CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MIN_HEAP_CC_
#define CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MIN_HEAP_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "data_structures/heap2.h"

namespace Heap::UnitTest::Insert::Min
{
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  class HeapInsertMinTf : public ::testing::TestWithParam<TestCase>
  {
  protected:
    TestCase param;
  };

  INSTANTIATE_TEST_SUITE_P(
    InsertMinHeap, HeapInsertMinTf,
    ::testing::Values(
      // happy
      TestCase(std::vector<int>{1, 2}, 1),
      TestCase(std::vector<int>{1, 2, 3}, 1),
      TestCase(std::vector<int>{1, 2, 3, 4}, 1),
      TestCase(std::vector<int>{1, 2, 3, 4, 5}, 1),
      TestCase(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, 1),

      TestCase(std::vector<int>{1}, 1), TestCase(std::vector<int>{5, 4, 3}, 3),
      TestCase(std::vector<int>{5, 4, 3, 2, 1}, 1)
    )
  );

  TEST_P(HeapInsertMinTf, InsertMinHeap)
  {
    const TestCase tc = GetParam();
    Heap2<int> h = Heap2<int>();

    for (int val : tc.arr) {
      h.insert(val);
    }

    ASSERT_EQ(h.peek(), tc.expected);
  }
}  // namespace Heap::UnitTest::Insert::Min
#endif /* CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MIN_HEAP_CC_ */
