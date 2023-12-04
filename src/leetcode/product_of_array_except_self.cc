#ifndef CAW_SRC_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_CC_
#define CAW_SRC_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_CC_

#include <iostream>
#include <map>
#include <vector>

namespace ProductOfArrayExceptSelf
{
  using Map = std::map<int, int>;
  using Vec = std::vector<int>;

  class ProductOfArrayExceptSelf
  {
  public:
    Vec reverseWindow(Vec vec) const
    {
      uint size = vec.size();
      if (size < 2) {
        return vec;
      }

      Vec right(size);
      Vec left(size);
      Vec products(size);
      left[0] = 1;
      right[size - 1] = 1;

      for (uint i = 1; i < size; i++) {
        left[i] = left[i - 1] * vec[i - 1];
      }

      for (int i = size - 2; i >= 0; i--) {
        right[i] = right[i + 1] * vec[i + 1];
      }

      for (uint i = 0; i < size; i++) {
        products[i] = left[i] * right[i];
      }

      return products;
    }

    Vec lowSpace(Vec vec) const
    {
      uint size = vec.size();
      Vec products(size);
      products[0] = 1;
      for (uint i = 1; i < size; i++) {
        products[i] = products[i - 1] * vec[i - 1];
      }

      int rightProduct = 1;
      for (int i = size - 1; i >= 0; i--) {
        products[i] *= rightProduct;
        rightProduct *= vec[i];
      }

      return products;
    }
  };
}  // namespace ProductOfArrayExceptSelf

#endif /* CAW_SRC_LEETCODE_PRODUCT_OF_ARRAY_EXCEPT_SELF_CC_ */
