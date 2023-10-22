#ifndef CAW_TEST_ARRAY_ARRAY_PREPEND_CC_
#define CAW_TEST_ARRAY_ARRAY_PREPEND_CC_

#include "array_test_setup.cc"
#include "array/array.h"

class ArrayPrependTF : public ArrayTF
{
};

INSTANTIATE_TEST_SUITE_P(
    Array,
    ArrayPrependTF,
    ::testing::Values(
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
 * Tests whether the size of the array matches the number of prepend
 * operations.
 */
TEST_P(ArrayPrependTF, PrependSize)
{
  IntVector param = GetParam();
  Array<int> a = ArrayPrependTF::populateWithPrepend(param);

  ASSERT_EQ(a.length(), param.size());
}

/**
 * Tests whether the order in which the elements are prepended
 * matches the expected order.
 */
TEST_P(ArrayPrependTF, PrependInOrder)
{
  IntVector param = GetParam();
  Array<int> a = ArrayPrependTF::populateWithPrepend(param);

  for (int i = 0 - 1; i < param.size(); i++)
  {
    ASSERT_EQ(a.get(CAW_MAX_ELEMENT_COUNT - i), param[i]);
  }
}

/**
 * Tests whether the `Array` class throws a `runtime_error` if the
 * `prepend` calls exceed the limit.
 */
TEST(Array, ThrowOnPrependBeyondLimits)
{
  Array<int> a = populateAtLengthWithPrepend(CAW_MAX_ELEMENT_COUNT);

  ASSERT_THROW(a.prepend(11), std::runtime_error);
}

#endif /* CAW_TEST_ARRAY_ARRAY_PREPEND_CC_ */
