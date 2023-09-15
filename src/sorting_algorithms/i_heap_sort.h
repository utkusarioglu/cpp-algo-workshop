#ifndef CAW_SRC_SORTING_ALGORITHMS_I_HEAP_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_I_HEAP_SORT_H_

#include <vector>

template <typename T>
class IHeapSort
{
public:
  virtual void insert(const T newElement) = 0;
  virtual const std::vector<T> sort() = 0;
};

#endif /* CAW_SRC_SORTING_ALGORITHMS_I_HEAP_SORT_H_ */
