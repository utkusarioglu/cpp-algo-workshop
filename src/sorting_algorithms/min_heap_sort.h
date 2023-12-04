#ifndef CAW_SRC_SORTING_ALGORITHMS_MIN_HEAP_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_MIN_HEAP_SORT_H_

#include <memory>
#include <vector>

#include "../data_structures/min_heap.h"
#include "i_heap_sort.h"

namespace Heap
{
  namespace MinHeap
  {

    template <typename T>
    class MinHeapSort : public IHeapSort<T>
    {
    public:
      MinHeapSort()
      {
        this->heap = std::make_unique<MinHeap<T>>();
      }

      void insert(const T newElement)
      {
        this->heap->insert(newElement);
      }

      const std::vector<T> sort()
      {
        std::vector<T> sorted;
        while (!std::get<1>(this->heap->getHead())) {
          const auto [headValue, _isError] = this->heap->popHead();
          sorted.push_back(headValue);
        }
        return sorted;
      }

    private:
      std::unique_ptr<MinHeap<T>> heap;
    };

  }  // namespace MinHeap
}  // namespace Heap

#endif /* CAW_SRC_SORTING_ALGORITHMS_MIN_HEAP_SORT_H_ */
