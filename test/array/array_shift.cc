#ifndef CAW_TEST_ARRAY_ARRAY_SHIFT_CC_
#define CAW_TEST_ARRAY_ARRAY_SHIFT_CC_

#include <stdexcept>

#include "array_test_setup.cc"
#include "array/array.h"

class ArrayShiftTF : public ArrayTF
{
};

INSTANTIATE_TEST_SUITE_P(
    Array,
    ArrayShiftTF,
    ::testing::Values(
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

TEST_P(ArrayShiftTF, ShiftCorrectSize)
{
  auto param = GetParam();
  Array<int> a = ArrayShiftTF::populateWithAppend(param);
  auto shifted = a.shift();

  ASSERT_EQ(a.length(), param.size() - 1);
}

TEST_P(ArrayShiftTF, ShiftCorrectValue)
{
  auto param = GetParam();
  Array<int> a = ArrayShiftTF::populateWithAppend(param);
  auto shifted = a.shift();

  ASSERT_EQ(a.length(), param.size() - 1);
  ASSERT_EQ(shifted, param[0]);
}

TEST_P(ArrayShiftTF, ShiftInOrder)
{
  auto param = GetParam();
  Array<int> a = ArrayShiftTF::populateWithAppend(param);
  auto shifted = a.shift();

  for (int i = 1; i < param.size(); i++)
  {
    ASSERT_EQ(a.get(i - 1), param[i]);
  }
}

TEST(Array, ThrowOnShiftEmptyArray)
{
  Array<int> a = Array<int>();
  ASSERT_THROW(a.shift(), std::runtime_error);
}

#endif /* CAW_TEST_ARRAY_ARRAY_SHIFT_CC_ */
