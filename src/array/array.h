#ifndef CAW__IGNORE_ARRAY_ARRAY_H_
#define CAW__IGNORE_ARRAY_ARRAY_H_

#define CAW_MAX_ELEMENT_COUNT 10

#include <stdexcept>

namespace Array
{
  template <typename T>
  class Array
  {
  public:
    /**
     * Adds a new element to the end of the array
     */
    void append(T element)
    {
      checkSize();
      this->elements[this->len++] = element;
    }

    /**
     * Adds a new element to the beginning of the array.
     * All preexisting elements are moved one index higher.
     */
    void prepend(T element)
    {
      checkSize();
      for (int i = this->len - 1; i >= 0; i--) {
        this->elements[i + 1] = this->elements[i];
      }
      this->elements[0] = element;
      this->len++;
    }

    /**
     * Removes and returns the first element
     */
    T shift()
    {
      if (this->len == 0) {
        throw std::runtime_error("Cannot shift from empty array");
      }
      T shifted = this->elements[0];
      for (int i = 1; i < this->len; i++) {
        this->elements[i - 1] = this->elements[i];
      }
      this->len--;
      return shifted;
    }

    /**
     * Removes and returns the last element
     */
    T pop()
    {
      if (this->len == 0) {
        throw std::runtime_error("Cannot pop from empty array");
      }
      return this->elements[--this->len];
    }

    /**
     * Removes the given element from the array. The indices of the
     * following elements are reduced by one.
     */
    void remove(T element)
    {
      if (0 == this->len) {
        return;
      }

      int elementIndex = this->index(element);
      if (-1 == elementIndex) {
        return;
      }
      if (elementIndex == this->len - 1) {
        this->pop();
        return;
      }

      for (int i = elementIndex; i < this->len - 1; i++) {
        this->elements[i] = this->elements[i + 1];
      }
      this->len--;
    }

    /**
     * Returns the length of the array
     */
    int length() const
    {
      return this->len;
    }

    /**
     * Returns true if the given element exists in the array
     */
    bool has(T element) const
    {
      return this->index(element) > -1;
    }

    /**
     * Returns the index of the given element.
     * Returns `-1` if the element is not in the array.
     */
    int index(T element) const
    {
      for (int i = 0; i < this->len; i++) {
        if (this->elements[i] == element) {
          return i;
        }
      }
      return -1;
    }

    /**
     * Returns the element at the given index.
     * Throws if the index requested is larger than the array size
     */
    T get(int index)
    {
      if (index > this->len - 1) {
        throw std::runtime_error("Index out of bounds");
      }
      return this->elements[index];
    }

  private:
    /**
     * Elements of the array
     */
    T elements[CAW_MAX_ELEMENT_COUNT];
    /**
     * Size of the array
     */
    int len = 0;

    /**
     * Checks the current size of the array against the max allowed limits
     * throws an exception if the array is beyond allowed size limits.
     */
    void checkSize()
    {
      if (this->len >= CAW_MAX_ELEMENT_COUNT) {
        throw std::runtime_error("Too many elements");
      }
    }
  };

}  // namespace Array

#endif /* CAW__IGNORE_ARRAY_ARRAY_H_ */
