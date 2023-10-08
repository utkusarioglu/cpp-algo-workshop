#ifndef CAW_SRC_SORTING_ALGORITHMS_BUBBLE_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_BUBBLE_SORT_H_

#include <algorithm>

template <typename T>
class BubbleSort
{
public:
  const std::vector<T> sort(const std::vector<T> unsorted)
  {
    std::vector<T> sorted;
    std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));

    bool has_changed = true;
    while (has_changed)
    {
      has_changed = false;
      for (auto i_large = 1; i_large < sorted.size(); i_large++)
      {
        uint i_small = i_large - 1;
        T value_small = sorted[i_small];
        T value_large = sorted[i_large];
        if (value_small > value_large)
        {
          std::swap(sorted[i_small], sorted[i_large]);
          has_changed = true;
        }
      }
    }
    return sorted;
  }

  const std::vector<T> startFromReverse(const std::vector<T> unsorted)
  {
    std::vector<T> sorted;
    std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));

    if (sorted.size() == 0)
    {
      return sorted;
    }

    bool has_changed = true;
    while (has_changed)
    {
      has_changed = false;
      for (uint i_large = sorted.size() - 1; i_large > 0; i_large--)
      {
        uint i_small = i_large - 1;
        T value_small = sorted[i_small];
        T value_large = sorted[i_large];
        if (value_small > value_large)
        {
          std::swap(sorted[i_small], sorted[i_large]);
          has_changed = true;
        }
      }
    }

    return sorted;
  }
};

#endif /* CAW_SRC_SORTING_ALGORITHMS_BUBBLE_SORT_H_ */
