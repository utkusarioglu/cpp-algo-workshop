#ifndef CAW_SRC_LEETCODE_TWO_SUM_H_
#define CAW_SRC_LEETCODE_TWO_SUM_H_

#include <utility>
#include <vector>

namespace TwoSum
{
  struct TwoSumsParams {
    std::vector<int> list;
    int target;
  };

  using Response = std::pair<uint, uint>;

  template <typename T>
  class TwoSum
  {
  public:
    Response doubleLoop(TwoSumsParams params) const
    {
      std::vector<T> vec = params.list;
      int target = params.target;
      for (uint i = 0; i < vec.size() - 1; i++) {
        for (uint j = i + 1; j < vec.size(); j++) {
          if (vec[i] + vec[j] == target) {
            return std::make_pair(i, j);
          }
        }
      }
      return std::make_pair(0, 0);
    }

    Response mapped(TwoSumsParams params) const
    {
      std::map<T, T> mapped;
      for (uint i = 0; i < params.list.size(); i++) {
        T counterpart = params.target - params.list[i];

        if (mapped.contains(counterpart)) {
          uint counterpartIndex = mapped[counterpart];
          if (i > counterpartIndex) {
            return std::make_pair(counterpartIndex, i);
          } else {
            return std::make_pair(i, counterpartIndex);
          }
        }
        mapped[params.list[i]] = i;
      }
      return std::make_pair(0, 0);
    }
  };

}  // namespace TwoSum

#endif /* CAW_SRC_LEETCODE_TWO_SUM_H_ */
