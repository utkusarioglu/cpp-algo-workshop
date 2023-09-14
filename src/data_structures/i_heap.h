#ifndef CAW_SRC_DATA_STRUCTURES_I_HEAP_H_
#define CAW_SRC_DATA_STRUCTURES_I_HEAP_H_

#include <vector>
#include <utility>

template <typename T>
class IHeap
{
public:
  virtual void insert(const T newElement) = 0;
  virtual const std::pair<T, bool> getHead() = 0;
  virtual const std::pair<T, bool> popHead() = 0;

private:
  std::vector<T> heap;

  virtual const uint getParentIndex(uint index) = 0;
  virtual const uint getLeftChildIndex(uint index) = 0;
  virtual const uint getRightChildIndex(uint index) = 0;
  virtual void reorder(const uint index) = 0;
};

#endif /* CAW_SRC_DATA_STRUCTURES_I_HEAP_H_ */
