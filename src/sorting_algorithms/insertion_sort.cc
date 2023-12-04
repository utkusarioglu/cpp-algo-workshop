#ifndef CAW_SRC_SORTING_ALGORITHMS_INSERTION_SORT_CC_
#define CAW_SRC_SORTING_ALGORITHMS_INSERTION_SORT_CC_

#include "insertion_sort.h"

#include <algorithm>
#include <iterator>
#include <vector>

std::vector<int> InsertionSort::InsertionSort::loop(
  const std::vector<int> &unsorted
)
{
  std::vector<int> sorted;
  std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));

  for (int i = 1; i < sorted.size(); i++) {
    for (int j = i; j > 0; j--) {
      if (sorted[j - 1] < sorted[j]) {
        continue;
      }
      int temp = sorted[j];
      sorted[j] = sorted[j - 1];
      sorted[j - 1] = temp;
    }
  }
  return sorted;
}

#endif /* CAW_SRC_SORTING_ALGORITHMS_INSERTION_SORT_CC_ */
