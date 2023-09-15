#ifndef CAW_SRC_DATA_STRUCTURES_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_HEAP_H_

#include "i_heap.h"

template <typename T>
class Heap : public IHeap<T>
{

public:
  const std::pair<T, bool> getHead()
  {
    if (this->heap.empty())
    {
      return std::make_pair(std::numeric_limits<T>::min(), true);
    }
    return std::make_pair(this->heap[0], false);
  }

protected:
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

  const std::pair<T, bool> replaceHeadWithBack()
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
    return head;
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_HEAP_H_ */
