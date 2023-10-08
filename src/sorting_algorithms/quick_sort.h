#ifndef CAW_SRC_SORTING_ALGORITHMS_QUICK_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_QUICK_SORT_H_

#include <vector>
#include <utility>

// 1. pick a pivot
// 2. in the range separate the elems that come before the pivot to the
// beginning and the ones that come after the pivot to the end
// 3. call the sorter on the two sections that were separated by the pivot

template <typename T>
class QuickSort
{
private:
  void swapIndices(std::vector<T> &unsorted, const int index1, const int index2)
  {
    const int temp = unsorted[index1];
    unsorted[index1] = unsorted[index2];
    unsorted[index2] = temp;
  }

  const int partition(std::vector<T> &unsorted, const int startIndex, const int endIndex)
  {
    int pivot = endIndex;
    int i = startIndex - 1;
    int j = startIndex;
    while (j < pivot)
    {
      if (unsorted[j] > unsorted[pivot])
      {
        j++;
      }
      else
      {
        i++;
        this->swapIndices(unsorted, i, j);
        j++;
      }
    }
    i++;
    this->swapIndices(unsorted, i, pivot);
    return i;
  }

  void sortRange(std::vector<T> &unsorted, const int startIndex, const int endIndex)
  {
    if (endIndex < startIndex)
    {
      return;
    }
    const int partition = this->partition(unsorted, startIndex, endIndex);
    this->sortRange(unsorted, startIndex, partition - 1);
    this->sortRange(unsorted, partition + 1, endIndex);
  }

public:
  const std::vector<T> sort(const std::vector<T> unsorted)
  {
    std::vector<T> sorted;
    std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));
    this->sortRange(sorted, 0, sorted.size() - 1);
    return sorted;
  }
};

#endif /* CAW_SRC_SORTING_ALGORITHMS_QUICK_SORT_H_ */
