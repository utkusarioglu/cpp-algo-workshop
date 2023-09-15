#ifndef CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_

#include <utility>
#include <limits>

#include "heap.h"

template <typename T>
class MaxHeap : public Heap<T>
{
public:
  void insert(const T newElement)
  {
    this->heap.emplace_back(newElement);
    uint currentIndex = this->heap.size() - 1;
    while (currentIndex > 0)
    {
      T currentValue = this->heap[currentIndex];
      uint parentIndex = this->getParentIndex(currentIndex);
      T parentValue = this->heap[parentIndex];
      if (parentValue > currentValue)
      {
        return;
      }
      this->swapIndices(currentIndex, parentIndex);
      currentIndex = parentIndex;
    }
  }

  const std::pair<T, bool> popHead()
  {
    const std::pair<T, bool> head = this->replaceHeadWithBack();
    if (!this->heap.empty())
    {
      this->reorder(0);
    }
    return head;
  }

private:
  void reorder(const uint currentIndex)
  {
    const uint leftChildIndex = this->getLeftChildIndex(currentIndex);
    const uint lastIndex = this->heap.size() - 1;
    if (leftChildIndex > lastIndex)
    {
      return;
    }
    const T leftChildValue = this->heap[leftChildIndex];
    const uint rightChildIndex = this->getRightChildIndex(currentIndex);
    const T rightChildValue = rightChildIndex > lastIndex
                                  ? std::numeric_limits<T>::min()
                                  : this->heap[rightChildIndex];
    const uint largestChildIndex = leftChildValue > rightChildValue
                                       ? leftChildIndex
                                       : rightChildIndex;
    const T largestChildValue = this->heap[largestChildIndex];
    const T currentValue = this->heap[currentIndex];
    if (largestChildValue > currentValue)
    {
      this->swapIndices(largestChildIndex, currentIndex);
    }
    this->reorder(largestChildIndex);
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_ */
