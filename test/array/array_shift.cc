#ifndef CAW_TEST_ARRAY_ARRAY_SHIFT_CC_
#define CAW_TEST_ARRAY_ARRAY_SHIFT_CC_

#include <stdexcept>

#include "array/array.h"
#include "array_test_setup.cc"

namespace Array
{
  namespace UnitTests
  {
    namespace Shift
    {
      using IntVector = IntVector;

      class ArrayShiftTf : public ArrayTf
      {
      };

      INSTANTIATE_TEST_SUITE_P(
        Array, ArrayShiftTf,
        ::testing::Values(
          IntVector{0}, IntVector{0, 1}, IntVector{0, 1, 2},
          IntVector{0, 1, 2, 3}, IntVector{0, 1, 2, 3, 4},
          IntVector{0, 1, 2, 3, 4, 5}, IntVector{0, 1, 2, 3, 4, 5, 6},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
        )
      );

      TEST_P(ArrayShiftTf, ShiftCorrectSize)
      {
        auto param = GetParam();
        Array<int> a = populateWithAppend(param);
        auto shifted = a.shift();

        ASSERT_EQ(a.length(), param.size() - 1);
      }

      TEST_P(ArrayShiftTf, ShiftCorrectValue)
      {
        auto param = GetParam();
        Array<int> a = populateWithAppend(param);
        auto shifted = a.shift();

        ASSERT_EQ(a.length(), param.size() - 1);
        ASSERT_EQ(shifted, param[0]);
      }

      TEST_P(ArrayShiftTf, ShiftInOrder)
      {
        auto param = GetParam();
        Array<int> a = populateWithAppend(param);
        auto shifted = a.shift();

        for (int i = 1; i < param.size(); i++) {
          ASSERT_EQ(a.get(i - 1), param[i]);
        }
      }

      TEST(Array, ThrowOnShiftEmptyArray)
      {
        auto a = Array<int>();
        ASSERT_THROW(a.shift(), std::runtime_error);
      }

    }  // namespace Shift
  }    // namespace UnitTests
}  // namespace Array

#endif /* CAW_TEST_ARRAY_ARRAY_SHIFT_CC_ */
