#ifndef CAW_SRC_SHUFFLING_ALGORITHMS_FISHER_YATES_H_
#define CAW_SRC_SHUFFLING_ALGORITHMS_FISHER_YATES_H_

#include <algorithm>
#include <cmath>
#include <vector>

namespace FisherYates
{
  template <typename T>
  std::vector<T> fisherYates(std::vector<T> vanilla)
  {
    std::vector<T> shuffled;
    copy(vanilla.begin(), vanilla.end(), back_inserter(shuffled));
    for (uint i = vanilla.size() - 1; i > 0; i--) {
      uint j = floor(rand() % i);
      std::swap(shuffled[i], shuffled[j]);
    }
    return shuffled;
  }
}  // namespace FisherYates

#endif /* CAW_SRC_SHUFFLING_ALGORITHMS_FISHER_YATES_H_ */
