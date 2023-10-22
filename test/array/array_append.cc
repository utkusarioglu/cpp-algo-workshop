#ifndef CAW_TEST_ARRAY_ARRAY_POP_UNIT_TEST_CC_
#define CAW_TEST_ARRAY_ARRAY_POP_UNIT_TEST_CC_

#include <stdexcept>

#include "array_test_setup.cc"
#include "../../src/array/array.h"

class ArrayAppendTF : public ArrayTF
{
};

INSTANTIATE_TEST_SUITE_P(
    Array,
    ArrayAppendTF,
    testing::Values(
        IntVector{},
        IntVector{0},
        IntVector{0, 1},
        IntVector{0, 1, 2},
        IntVector{0, 1, 2, 3},
        IntVector{0, 1, 2, 3, 4},
        IntVector{0, 1, 2, 3, 4, 5},
        IntVector{0, 1, 2, 3, 4, 5, 6},
        IntVector{0, 1, 2, 3, 4, 5, 6, 7},
        IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8},
        IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));

/**
 * Tests whether the size of the array holds with successive
 * appends.
 */
TEST_P(ArrayAppendTF, AppendSize)
{
  IntVector param = GetParam();
  Array<int> a = ArrayAppendTF::populateWithAppend(param);

  ASSERT_EQ(a.length(), param.size());
}

/**
 * Tests that the append order of the element matches the array
 * order.
 */
TEST_P(ArrayAppendTF, AppendInOrder)
{
  IntVector param = GetParam();
  Array<int> a = ArrayAppendTF::populateWithAppend(param);

  for (int i = 0; i < param.size(); i++)
  {
    ASSERT_EQ(a.get(i), param[i]);
  }
}

/**
 * Tests whether the `Array` class throws a `runtime_error` if the
 * `append` calls exceed the limit.
 */
TEST(Array, ThrowOnAppendBeyondLimits)
{
  Array<int> a = populateAtLengthWithAppend(CAW_MAX_ELEMENT_COUNT);

  ASSERT_THROW(a.append(11), std::runtime_error);
}

#endif /* CAW_TEST_ARRAY_ARRAY_POP_UNIT_TEST_CC_ */
