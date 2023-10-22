#ifndef CAW_TEST_ARRAY_ARRAY_REMOVE_CC_
#define CAW_TEST_ARRAY_ARRAY_REMOVE_CC_

#include "array_test_setup.cc"
#include "array/array.h"

class ArrayRemoveTF : public ArrayTF
{
};

INSTANTIATE_TEST_SUITE_P(
    Array,
    ArrayRemoveTF,
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

// TEST_P(ArrayRemoveTF, RemoveFirstElement_CorrectArraySize)
// {
//   auto param = GetParam();
//   Array<int> a = ArrayRemoveTF::populateWithAppend(param);
//   a.remove(0);

//   ASSERT_EQ(a.length(), param.size() - 1);
// }

TEST_P(ArrayRemoveTF, RemoveFirstElement_CorrectArrayElements)
{
  auto param = GetParam();
  Array<int> a = ArrayRemoveTF::populateWithAppend(param);
  a.remove(0);

  for (int i = 0; i < param.size() - 1; i++)
  {
    ASSERT_EQ(a.get(i), param[i + 1]);
  }
}

// TEST_P(ArrayRemoveTF, Remove1SizeWorks)
// {
//   auto param = GetParam();
//   Array<int> a = ArrayRemoveTF::populateWithAppend(param);
//   a.remove(1);

//   if (param.size() > 2)
//   {
//     ASSERT_EQ(a.length(), param.size() - 1);
//   }
//   else
//   {
//     ASSERT_EQ(a.length(), param.size());
//   }
// }

#endif /* CAW_TEST_ARRAY_ARRAY_REMOVE_CC_ */
