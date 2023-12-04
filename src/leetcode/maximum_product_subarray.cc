#ifndef CAW_SRC_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_CC_
#define CAW_SRC_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_CC_

#include <functional>
#include <limits>
#include <map>
#include <utility>
#include <vector>

namespace MaximumProductSubarray
{
  using Vec = std::vector<int>;
  using Response = int;

  class MaximumProductSubarray
  {
  public:
    Response loop(Vec vec) const
    {
      size_t size = vec.size();
      int global = std::numeric_limits<int>::min();
      int local = 1;
      for (size_t i = 0; i < size; i++) {
        if (local < 1) {
          local = 1;
        }
        local *= vec[i];
        if (local > global) {
          global = local;
        }
      }
      return global;
    }

    Response dp(Vec vec) const
    {
      using Pair = std::pair<size_t, size_t>;
      using Memo = std::map<Pair, int>;
      using Retrieve = std::function<Response(size_t, size_t)>;

      size_t size = vec.size();
      Memo memo;
      for (size_t i = 0; i < size; i++) {
        memo[std::make_pair(i, i)] = vec[i];
      }

      Response global = std::numeric_limits<int>::min();

      Retrieve retrieve = [&retrieve, &memo, &vec](size_t l, size_t r) {
        Pair pair = std::make_pair(l, r);
        if (memo.contains(pair)) {
          return memo[pair];
        }
        Response child = memo[std::make_pair(l, r - 1)];
        memo[pair] = child * vec[r];

        return memo[pair];
      };

      for (size_t r = 0; r < size; r++) {
        for (size_t l = 0; l <= r; l++) {
          Response local = retrieve(l, r);
          if (local > global) {
            global = local;
          }
        }
      }

      return global;
    }
  };
}  // namespace MaximumProductSubarray

#endif /* CAW_SRC_LEETCODE_MAXIMUM_PRODUCT_SUBARRAY_CC_ */
