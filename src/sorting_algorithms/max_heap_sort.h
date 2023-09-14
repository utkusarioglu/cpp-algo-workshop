#ifndef CAW_SRC_SORTING_ALGORITHMS_MAX_HEAP_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_MAX_HEAP_SORT_H_

#include <memory>
#include <utility>

#include "../data_structures/max_heap.h"

template <typename T>
class MaxHeapSort
{
public:
  MaxHeapSort()
  {
    this->heap = std::make_unique<MaxHeap<T>>();
  }

  void insert(const T newElement)
  {
    this->heap->insert(newElement);
  }

  const std::vector<T> sort()
  {
    std::vector<T> sorted;
    while (!std::get<1>(this->heap->getHead()))
    {
      std::pair<int, bool> head = this->heap->popHead();
      sorted.push_back(std::get<0>(head));
    }
    return sorted;
  }

private:
  std::unique_ptr<MaxHeap<T>> heap;
};

#endif /* CAW_SRC_SORTING_ALGORITHMS_MAX_HEAP_SORT_H_ */
