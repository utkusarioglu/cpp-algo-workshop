#ifndef CAW_TEST_DATA_STRUCTURES_HEAP2_REMOVE_MIN_HEAP_CC_
#define CAW_TEST_DATA_STRUCTURES_HEAP2_REMOVE_MIN_HEAP_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "data_structures/heap2.h"

namespace Heap::UnitTest::Remove::Min
{
  struct TestCase {
    std::vector<int> values;
  };

  class HeapRemoveMinTf : public ::testing::TestWithParam<TestCase>
  {
  protected:
    TestCase param;
  };

  INSTANTIATE_TEST_SUITE_P(
    heapify, HeapRemoveMinTf,
    ::testing::Values(
      TestCase{std::vector<int>{1, 2}}, TestCase{std::vector<int>{1, 2, 3}},
      TestCase{std::vector<int>{1, 2, 3, 4}},
      TestCase{std::vector<int>{4, 3, 2, 1}},

      TestCase{std::vector<int>{8, 7, 6, 5, 4, 3, 2, 1}}
    )
  );

  TEST_P(HeapRemoveMinTf, Remove)
  {
    using Num = int;
    TestCase t = GetParam();
    Heap2<Num> h = Heap2<Num>();

    for (Num v : t.values) {
      h.insert(v);
    }

    std::vector<Num> sorted;
    std::copy(t.values.begin(), t.values.end(), std::back_inserter(sorted));
    std::sort(sorted.begin(), sorted.end());

    for (size_t i = 0; i < sorted.size() - 1; i++) {
      h.pop();
      ASSERT_EQ(h.peek(), sorted[i + 1]);
    }
  };
}  // namespace Heap::UnitTest::Remove::Min

#endif /* CAW_TEST_DATA_STRUCTURES_HEAP2_REMOVE_MIN_HEAP_CC_ */
