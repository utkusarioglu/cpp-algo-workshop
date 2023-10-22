#ifndef CAW_TEST_ARRAY_ARRAY_POP_CC_
#define CAW_TEST_ARRAY_ARRAY_POP_CC_

#include <stdexcept>

#include "array_test_setup.cc"
#include "../../src/array/array.h"

class ArrayPopTF : public ArrayTF
{
};

INSTANTIATE_TEST_SUITE_P(
    Array,
    ArrayPopTF,
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

TEST_P(ArrayPopTF, PopCorrectSize)
{
  auto param = GetParam();
  Array<int> a = ArrayPopTF::populateWithAppend(param);
  auto popped = a.pop();

  ASSERT_EQ(a.length(), param.size() - 1);
}

TEST_P(ArrayPopTF, PopCorrectValue)
{
  auto param = GetParam();
  Array<int> a = ArrayPopTF::populateWithAppend(param);
  auto popped = a.pop();

  ASSERT_EQ(a.length(), param.size() - 1);
  ASSERT_EQ(popped, param[param.size() - 1]);
}

TEST_P(ArrayPopTF, PopInOrder)
{
  auto param = GetParam();
  Array<int> a = ArrayPopTF::populateWithAppend(param);
  auto popped = a.pop();

  for (int i = 0; i < param.size() - 1; i++)
  {
    ASSERT_EQ(a.get(i), param[i]);
  }
}

TEST(Array, ThrowOnPopEmptyArray)
{
  Array<int> a = Array<int>();

  ASSERT_THROW(a.pop(), std::runtime_error);
}

#endif /* CAW_TEST_ARRAY_ARRAY_POP_CC_ */
