#ifndef CAW_TEST_ARRAY_ARRAY_TEST_SETUP_CC_
#define CAW_TEST_ARRAY_ARRAY_TEST_SETUP_CC_

#include <gtest/gtest.h>

#include <vector>

#include "array/array.h"

namespace Array
{

  namespace UnitTests
  {

    using IntVector = std::vector<int>;

    class ArrayTf : public testing::TestWithParam<IntVector>
    {
    public:
      static Array<int> populateWithAppend(IntVector param)
      {
        Array<int> a = Array<int>();
        for (int i = 0; i < param.size(); i++) {
          a.append(i);
        }
        return a;
      }

      static Array<int> populateWithPrepend(IntVector param)
      {
        Array<int> a = Array<int>();
        for (int i = 0; i < param.size(); i++) {
          a.prepend(i);
        }
        return a;
      }

    protected:
      IntVector param;
    };

    Array<int> populateAtLengthWithAppend(int length)
    {
      Array<int> a = Array<int>();
      for (int i = 0; i < length; i++) {
        a.append(i);
      }
      return a;
    };

    Array<int> populateAtLengthWithPrepend(int length)
    {
      Array<int> a = Array<int>();
      for (int i = 0; i < length; i++) {
        a.append(i);
      }
      return a;
    };

  }  // namespace UnitTests
}  // namespace Array

#endif /* CAW_TEST_ARRAY_ARRAY_TEST_SETUP_CC_ */
