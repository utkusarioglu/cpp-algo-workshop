#ifndef CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_

#include "i_heap.h"

template <typename T>
class MinHeap : public IHeap<T>
{
public:
  void insert(const T newElement)
  {
  }

  const std::pair<T, bool> getHead()
  {
  }
  const std::pair<T, bool> popHead()
  {
  }

private:
  std::vector<T> heap;

  const uint getParentIndex(uint index)
  {
  }
  const uint getLeftChildIndex(uint index)
  {
  }
  const uint getRightChildIndex(uint index)
  {
  }
  void reorder(const uint index)
  {
  }
};

#endif /* CAW_SRC_DATA_STRUCTURES_MIN_HEAP_H_ */
