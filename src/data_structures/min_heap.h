#ifndef CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_

#include "heap.h"

template <typename T>
class MinHeap : public Heap<T>
{
public:
  void insert(const T newElement)
  {
    this->heap.push_back(newElement);
    uint currentIndex = this->heap.size() - 1;
    while (currentIndex > 0)
    {
      const uint parentIndex = this->getParentIndex(currentIndex);
      const T parentValue = this->heap[parentIndex];
      if (newElement < parentValue)
      {
        std::swap(this->heap[currentIndex], this->heap[parentIndex]);
      }
      currentIndex = parentIndex;
    }
  }

  const std::pair<T, bool> popHead()
  {
    const std::pair<T, bool> head = this->replaceHeadWithBack();
    if (!this->heap.empty() > 0)
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
                                  ? std::numeric_limits<T>::max()
                                  : this->heap[rightChildIndex];
    const uint smallestChildIndex = leftChildValue < rightChildValue
                                        ? leftChildIndex
                                        : rightChildIndex;
    const T smallestChildValue = this->heap[smallestChildIndex];
    const T currentValue = this->heap[currentIndex];
    if (smallestChildValue < currentValue)
    {
      this->swapIndices(smallestChildIndex, currentIndex);
    }
    this->reorder(smallestChildIndex);
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_ */
