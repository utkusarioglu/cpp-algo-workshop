#ifndef CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MAX_HEAP_CC_
#define CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MAX_HEAP_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "data_structures/heap2.h"

namespace Heap::UnitTest::Insert::Max
{
  struct TestCase {
    std::vector<int> arr;
    int expected;
  };

  class HeapInsertMaxTf : public ::testing::TestWithParam<TestCase>
  {
  protected:
    TestCase param;
  };

  INSTANTIATE_TEST_SUITE_P(
    InsertMaxHeap, HeapInsertMaxTf,
    ::testing::Values(
      // happy
      TestCase(std::vector<int>{1, 2}, 2),
      TestCase(std::vector<int>{1, 2, 3}, 3),
      TestCase(std::vector<int>{1, 2, 3, 4}, 4),
      TestCase(std::vector<int>{1, 2, 3, 4, 5}, 5),
      TestCase(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, 8),

      TestCase(std::vector<int>{1}, 1), TestCase(std::vector<int>{5, 4, 3}, 5),
      TestCase(std::vector<int>{5, 4, 3, 2, 1}, 5)
    )
  );

  TEST_P(HeapInsertMaxTf, InsertMaxHeap)
  {
    const TestCase tc = GetParam();
    Heap2<int> h = Heap2<int>(HeapType<int>::max);

    for (int val : tc.arr) {
      h.insert(val);
    }

    ASSERT_EQ(h.peek(), tc.expected);
  }
}  // namespace Heap::UnitTest::Insert::Max

#endif /* CAW_TEST_DATA_STRUCTURES_HEAP2_INSERT_MAX_HEAP_CC_ */
