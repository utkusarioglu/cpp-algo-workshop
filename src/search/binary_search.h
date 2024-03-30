#ifndef CAW_SRC_SEARCH_BINARY_SEARCH_H_
#define CAW_SRC_SEARCH_BINARY_SEARCH_H_

#include <spdlog/spdlog.h>

#include <vector>

namespace BinarySearch
{
  template <typename T>
  size_t binarySearchLoop(std::vector<T> arr, T target)
  {
    int size = arr.size();
    if (!size) {
      return -1;
    }

    size_t start = 0;
    size_t end = size - 1;

    if (arr[start] > target || arr[end] < target) {
      return -1;
    }

#ifdef DEBUG
    spdlog::warn("DEBUG");
    int counter = 0;
#endif

    while (start <= end) {
#ifdef DEBUG
      if (++counter > 100) {
        spdlog::warn("CIRCUIT_BREAKER");
        break;
      }
#endif

      size_t mid = start + (end - start) / 2;

#ifdef DEBUG
      spdlog::info("s:{} m:{} e:{} v:{}", start, mid, end, arr[mid]);
#endif

      if (target == arr[mid]) {
        return mid;
      } else if (target > arr[mid]) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return -1;
  };

  template <typename T>
  size_t binarySearchRecursive(
    std::vector<T> arr, T target, size_t start, size_t end
  )
  {
#ifdef DEBUG
    spdlog::info("s:{} e:{}", start, end);
#endif
    if (start > end) {
      return -1;
    } else if (start == end) {
      if (arr[start] == target) {
        return start;
      } else {
        return -1;
      }
    }

    size_t mid = start + (end - start) / 2;
    if (arr[mid] < target) {
      return binarySearchRecursive(arr, target, mid + 1, end);
    } else {
      return binarySearchRecursive(arr, target, start, mid);
    }
  }

  template <typename T>
  size_t binarySearchRecursive(std::vector<T> arr, T target)
  {
    int size = arr.size();
    if (!size) {
      return -1;
    }

    size_t start = 0;
    size_t end = size - 1;
    return binarySearchRecursive(arr, target, start, end);
  }

}  // namespace BinarySearch

#endif /* CAW_SRC_SEARCH_BINARY_SEARCH_H_ */
