#ifndef CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_

#include <utility>
#include <limits>

#include "i_heap.h"

template <typename T>
class MaxHeap : public IHeap<T>
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
      std::swap(this->heap[currentIndex], this->heap[parentIndex]);
      currentIndex = parentIndex;
    }
  }

  const std::pair<T, bool> getHead()
  {
    if (this->heap.empty())
    {
      return std::make_pair(std::numeric_limits<T>::min(), true);
    }
    return std::make_pair(this->heap[0], false);
  }

  const std::pair<T, bool> popHead()
  {
    const std::pair<T, bool> head = this->getHead();
    if (std::get<1>(head))
    {
      return head;
    }
    if (this->heap.size() > 1)
    {
      this->heap[0] = this->heap.back();
    }
    this->heap.pop_back();
    if (!this->heap.empty())
    {
      this->reorder(0);
    }
    return head;
  }

private:
  std::vector<T> heap{};

  const uint getParentIndex(uint index)
  {
    return (index - 1) / 2;
  }

  const uint getLeftChildIndex(uint index)
  {
    return index * 2 + 1;
  }

  const uint getRightChildIndex(uint index)
  {
    return this->getLeftChildIndex(index) + 1;
  }

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
      std::swap(this->heap[largestChildIndex], this->heap[currentIndex]);
    }
    this->reorder(largestChildIndex);
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_ */
