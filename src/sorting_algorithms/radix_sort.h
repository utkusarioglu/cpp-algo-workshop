#ifndef CAW_SRC_SORTING_ALGORITHMS_RADIX_SORT_H_
#define CAW_SRC_SORTING_ALGORITHMS_RADIX_SORT_H_

#include <cmath>
#include <vector>

namespace SortingAlgorithms::RadixSort
{
  template <typename T>
  inline uint maxDigits(std::vector<T> values)
  {
    T maxNum = 0;
    for (T v : values) {
      if (v > maxNum) {
        maxNum = v;
      }
    }
    uint digits = 0;
    while (maxNum > 0) {
      digits++;
      maxNum /= 10;
    }
    return digits;
  }

  template <typename T>
  inline size_t getKey(T value, uint digit)
  {
    return (int)(value / pow(10, digit)) % 10;
  }

  template <typename T>
  std::vector<T> radixSort(std::vector<T> unsorted)
  {
    if (unsorted.size() < 2) {
      return unsorted;
    }
    uint maxDigit = maxDigits(unsorted);

    std::vector<T> sorted;
    std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));

    for (uint d = 0; d <= maxDigit; d++) {
      std::vector<T> counts(10, 0);
      for (size_t si = 0; si < sorted.size(); si++) {
        T value = sorted[si];
        size_t c_key = getKey(value, d);
        counts[c_key] += 1;
      }
      for (size_t i = 1; i < 10; i++) {
        counts[i] += counts[i - 1];
      }
      std::vector<T> newSort(sorted.size(), 0);
      for (size_t si = sorted.size(); si-- > 0;) {
        size_t value = sorted[si];
        size_t ns_key = getKey(value, d);
        size_t ni = --counts[ns_key];
        newSort[ni] = value;
      }
      sorted = newSort;
    }
    return sorted;
  };
}  // namespace SortingAlgorithms::RadixSort

#endif /* CAW_SRC_SORTING_ALGORITHMS_RADIX_SORT_H_ */
