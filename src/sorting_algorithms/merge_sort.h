#ifndef CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_

#include <vector>
#include <utility>

template <typename T>
class MergeSort
{
public:
  const std::vector<T> sort(const std::vector<T> unsorted)
  {
    const int unsortedSize = unsorted.size();
    if (unsortedSize < 2)
    {
      return unsorted;
    }
    const int midPoint = unsortedSize / 2;
    std::vector<T> smallerUnsorted;
    std::vector<T> largerUnsorted;
    for (auto i = 0; i < unsortedSize; i++)
    {
      if (i < midPoint)
      {
        smallerUnsorted.push_back(unsorted[i]);
      }
      else
      {
        largerUnsorted.push_back(unsorted[i]);
      }
    }

    const std::vector<T> smallerSorted = this->sort(smallerUnsorted);
    const std::vector<T> largerSorted = this->sort(largerUnsorted);
    const int smallerSortedSize = smallerSorted.size();
    const int largerSortedSize = largerSorted.size();
    int smallerIndex = 0;
    int largerIndex = 0;

    std::vector<T> sorted;

    while (smallerIndex < smallerSortedSize && largerIndex < largerSortedSize)
    {
      int smallerValue = smallerSorted[smallerIndex];
      int largerValue = largerSorted[largerIndex];
      if (smallerValue < largerValue)
      {
        sorted.push_back(smallerValue);
        smallerIndex++;
      }
      else
      {
        sorted.push_back(largerValue);
        largerIndex++;
      }
    }

    for (int i = smallerIndex; i < smallerSortedSize; i++)
    {
      sorted.push_back(smallerSorted[i]);
    }
    for (int i = largerIndex; i < largerSortedSize; i++)
    {
      sorted.push_back(largerSorted[i]);
    }

    return sorted;
  }
};

#endif /* CAW_SRC_SORTING_ALGORITHMS_MERGE_SORT_H_ */
