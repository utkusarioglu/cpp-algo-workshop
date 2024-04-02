#ifndef CAW_SRC_DATA_STRUCTURES_HEAP2_H_
#define CAW_SRC_DATA_STRUCTURES_HEAP2_H_

#include <stddef.h>

#include <functional>
#include <iostream>
#include <utility>

namespace Heap
{
  template <typename T>
  using ComparatorFunc = bool(std::vector<T> &heap, T parent, T child);

  template <typename T>
  class HeapType
  {
  public:
    static bool max(std::vector<T> &heap, T parent, T child)
    {
      return heap[parent] < heap[child];
    }

    static bool min(std::vector<T> &heap, T parent, T child)
    {
      return heap[parent] > heap[child];
    }
  };

  class Index
  {
  public:
    static size_t parent(size_t index)
    {
      if (index == 0) {
        return 0;
      }
      return (index - 1) / 2;
    }

    static size_t leftChild(size_t index)
    {
      return index * 2 + 1;
    }

    static size_t rightChild(size_t index)
    {
      return index * 2 + 2;
    }
  };

  template <typename T>
  class Heap
  {
  public:
    Heap()
    {
    }

    Heap(std::function<bool(std::vector<T> &, T, T)> comparator)
    {
      this->comparator = comparator;
    }

    const T peek()
    {
      return this->heap[0];
    }

    void insert(T value)
    {
      this->heap.push_back(value);
      size_t size = this->heap.size();

      if (size < 2) {
        return;
      }

      size_t current = size - 1;
      while (current > 0) {
        size_t parent = Index::parent(current);
        if (this->comparator(this->heap, parent, current)) {
          this->swap(parent, current);
        }
        current = parent;
      }
    }

    void pop()
    {
      size_t size = this->heap.size();
      if (size == 0) {
        return;
      }
      if (size == 1) {
        this->heap.pop_back();
        return;
      }

      this->swap(0, size - 1);
      this->heap.pop_back();

      if (size > 2) {
        this->reorder(0);
      }
    }

    const std::vector<T> getHeap()
    {
      return this->heap;
    }

  private:
    std::vector<T> heap;
    std::function<ComparatorFunc<T>> comparator = HeapType<T>::min;

    void reorder(size_t i)
    {
      size_t size = this->heap.size();
      size_t left = Index::leftChild(i);
      size_t right = Index::rightChild(i);
      size_t target = i;

      auto compare = [this, &target, &size](size_t child) {
        return child < size && this->comparator(this->heap, target, child);
      };

      if (compare(left)) {
        target = left;
      }
      if (compare(right)) {
        target = right;
      }
      if (target != i) {
        this->swap(i, target);
        this->reorder(target);
      }
    }

    void swap(size_t index1, size_t index2)
    {
      T temp = this->heap[index1];
      this->heap[index1] = this->heap[index2];
      this->heap[index2] = temp;
    }
  };
};  // namespace Heap

#endif /* CAW_SRC_DATA_STRUCTURES_HEAP2_H_ */
