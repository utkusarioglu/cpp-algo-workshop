#ifndef CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_

#include <exception>
#include <utility>
#include <vector>

namespace MergeSort
{
  template <typename T>
  class MergeSort
  {
  public:
    const std::vector<T> recurse(const std::vector<T> unsorted)
    {
      const int unsortedSize = unsorted.size();
      if (unsortedSize < 2) {
        return unsorted;
      }
      const int midPoint = unsortedSize / 2;
      std::vector<T> smallerUnsorted;
      std::vector<T> largerUnsorted;
      for (auto i = 0; i < unsortedSize; i++) {
        if (i < midPoint) {
          smallerUnsorted.push_back(unsorted[i]);
        } else {
          largerUnsorted.push_back(unsorted[i]);
        }
      }

      const std::vector<T> smallerSorted = this->recurse(smallerUnsorted);
      const std::vector<T> largerSorted = this->recurse(largerUnsorted);
      const int smallerSortedSize = smallerSorted.size();
      const int largerSortedSize = largerSorted.size();
      int smallerIndex = 0;
      int largerIndex = 0;

      std::vector<T> sorted;

      while (smallerIndex < smallerSortedSize && largerIndex < largerSortedSize
      ) {
        int smallerValue = smallerSorted[smallerIndex];
        int largerValue = largerSorted[largerIndex];
        if (smallerValue < largerValue) {
          sorted.push_back(smallerValue);
          smallerIndex++;
        } else {
          sorted.push_back(largerValue);
          largerIndex++;
        }
      }

      for (int i = smallerIndex; i < smallerSortedSize; i++) {
        sorted.push_back(smallerSorted[i]);
      }
      for (int i = largerIndex; i < largerSortedSize; i++) {
        sorted.push_back(largerSorted[i]);
      }

      return sorted;
    }

    const std::vector<T> loop(const std::vector<T> unsorted)
    {
      if (unsorted.size() < 2) {
        return unsorted;
      }

      std::vector<std::vector<T>> sorted;
      for (size_t i = 0; i < unsorted.size(); i++) {
        sorted.emplace_back(std::vector<T>{unsorted[i]});
      }

      while (sorted.size() != 1) {
        std::vector<std::vector<T>> newLevel;

        for (size_t p = 0; p < sorted.size(); p = p + 2) {
          std::vector<T> left = sorted[p];
          if (p + 1 == sorted.size()) {
            newLevel.push_back(left);
            continue;
          }
          std::vector<T> right = sorted[p + 1];
          size_t li = 0;
          size_t ri = 0;
          std::vector<T> merged;

          while (li < left.size() || ri < right.size()) {
            if (li == left.size()) {
              merged.push_back(right[ri++]);
              continue;
            } else if (ri == right.size()) {
              merged.push_back(left[li++]);
              continue;
            }

            if (left[li] < right[ri]) {
              merged.push_back(left[li++]);
            } else {
              merged.push_back((right[ri++]));
            }
          }

          newLevel.push_back(merged);
        }

        sorted = newLevel;
      }

      return sorted[0];
    }
  };

}  // namespace MergeSort

#endif /* CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_ */
