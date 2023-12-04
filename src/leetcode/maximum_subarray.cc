#ifndef CAW_SRC_LEETCODE_MAXIMUM_SUBARRAY_CC_
#define CAW_SRC_LEETCODE_MAXIMUM_SUBARRAY_CC_

#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <tuple>
#include <vector>

namespace MaximumSubarray
{
  using Vec = std::vector<int>;

  class MaximumSubarray
  {
  public:
    int worm(Vec vec) const
    {
      uint size = vec.size();

      int maxAmount = std::numeric_limits<int>::min();
      int sum = 0;

      for (uint i = 0; i < size; i++) {
        sum += vec[i];
        if (sum <= maxAmount) {
          continue;
        }
        maxAmount = sum;

        for (uint j = 0; j < i; j++) {
          sum -= vec[j];
          if (sum > maxAmount) {
            maxAmount = sum;
          }
        }
      }

      return maxAmount;
    }

    int sums(Vec vec) const
    {
      uint size = vec.size();
      int maxSubarray = std::numeric_limits<int>::min();
      int current = 0;

      for (uint r = 0; r < size; r++) {
        if (current < 0) {
          current = 0;
        }
        current += vec[r];
        if (current > maxSubarray) {
          maxSubarray = current;
        }
      }

      return maxSubarray;
    }

    int dp(Vec vec) const
    {
      using Pair = std::pair<uint, uint>;
      using Retrieve = std::function<int(uint, uint)>;

      uint size = vec.size();
      std::map<Pair, int> memo;
      for (size_t i = 0; i < size; i++) {
        memo[std::make_pair(i, i)] = vec[i];
      }
      int maxAmount = std::numeric_limits<int>::min();

      Retrieve retrieve = [&memo, &vec, &retrieve](uint l, uint r) {
        if (memo.contains(std::make_pair(l, r))) {
          return memo[std::make_pair(l, r)];
        }
        int child = retrieve(l, r - 1);
        Pair newKey = std::make_pair(l, r);
        memo[newKey] = child + vec[r];
        return memo[newKey];
      };

      for (size_t r = 0; r < size; r++) {
        for (size_t l = 0; l <= r; l++) {
          int current = retrieve(l, r);
          if (current > maxAmount) {
            maxAmount = current;
          }
        }
      }

      return maxAmount;
    };
  };
}  // namespace MaximumSubarray

#endif /* CAW_SRC_LEETCODE_MAXIMUM_SUBARRAY_CC_ */
