#ifndef CAW_TEST_ARRAY_ARRAY_PREPEND_CC_
#define CAW_TEST_ARRAY_ARRAY_PREPEND_CC_

#include "array/array.h"
#include "array_test_setup.cc"

namespace Array
{
  namespace UnitTests
  {
    namespace Prepend
    {
      class ArrayPrependTf : public ArrayTf
      {
      };

      INSTANTIATE_TEST_SUITE_P(
        Array, ArrayPrependTf,
        ::testing::Values(
          IntVector{}, IntVector{0}, IntVector{0, 1}, IntVector{0, 1, 2},
          IntVector{0, 1, 2, 3}, IntVector{0, 1, 2, 3, 4},
          IntVector{0, 1, 2, 3, 4, 5}, IntVector{0, 1, 2, 3, 4, 5, 6},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8},
          IntVector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
        )
      );

      /**
       * Tests whether the size of the array matches the number of prepend
       * operations.
       */
      TEST_P(ArrayPrependTf, PrependSize)
      {
        IntVector param = GetParam();
        Array<int> a = ArrayPrependTf::populateWithPrepend(param);

        ASSERT_EQ(a.length(), param.size());
      }

      /**
       * Tests whether the order in which the elements are prepended
       * matches the expected order.
       */
      TEST_P(ArrayPrependTf, PrependInOrder)
      {
        IntVector param = GetParam();
        Array<int> a = ArrayPrependTf::populateWithPrepend(param);

        for (int i = 0 - 1; i < param.size(); i++) {
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

    }  // namespace Prepend
  }    // namespace UnitTests
}  // namespace Array

#endif /* CAW_TEST_ARRAY_ARRAY_PREPEND_CC_ */
