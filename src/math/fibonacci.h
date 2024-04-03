#ifndef CAW_SRC_MATH_FIBONACCI_H_
#define CAW_SRC_MATH_FIBONACCI_H_

#include <stddef.h>

#include <vector>

namespace Math::Fibonacci
{
  namespace Recursion
  {
    ulong fibonacci(size_t index, std::vector<ulong> &memo)
    {
      if (memo.size() > index) {
        return memo[index];
      }
      size_t val = fibonacci(index - 1, memo) + fibonacci(index - 2, memo);
      memo.push_back(val);
      return val;
    }

    ulong fibonacci(size_t index)
    {
      std::vector<ulong> memo{0, 1};
      return fibonacci(index, memo);
    }
  }  // namespace Recursion

  namespace Loop
  {
    ulong fibonacci(size_t index)
    {
      std::vector<ulong> memo{0, 1};

      for (size_t i = memo.size(); i <= index; i++) {
        memo.push_back(memo[i - 1] + memo[i - 2]);
      }

      return memo[index];
    }
  }  // namespace Loop
}  // namespace Math::Fibonacci

#endif /* CAW_SRC_MATH_FIBONACCI_H_ */
