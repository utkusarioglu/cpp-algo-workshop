#ifndef CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_

#include <utility>

template <typename T>
class MaxHeap
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
    if (this->heap.size() == 0)
    {
      return std::make_pair(0, true);
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
      std::swap(this->heap[0], this->heap.at(-1));
    }
    this->heap->pop();
    this->reorder(0);
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

  void reorder(const uint index)
  {
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_MAX_HEAP_H_ */
