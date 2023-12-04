#ifndef CAW_SORTING_ALGORITHMS_COUNTING_SORT_CC_
#define CAW_SORTING_ALGORITHMS_COUNTING_SORT_CC_

#include "./counting_sort.h"

#include <fmt/core.h>

#include <algorithm>
#include <climits>
#include <vector>

int max(const std::vector<int> &arr)
{
  int current = INT_MIN;
  int arrLength = arr.size();
  for (int i = 0; i < arrLength; i++) {
    if (current < arr[i]) {
      current = arr[i];
    }
  }
  return current;
}

int min(const std::vector<int> &arr)
{
  int current = INT_MAX;
  int arrLength = arr.size();
  for (int i = 0; i < arrLength; i++) {
    if (current > arr[i]) {
      current = arr[i];
    }
  }
  return current;
}

std::vector<int> CountingSort::CountingSort::loop(
  const std::vector<int> &unsorted
)
{
  int maxValue = max(unsorted);
  int minValue = min(unsorted);
  auto counts = std::vector<int>(maxValue - minValue + 1);
  for (auto elem : unsorted) {
    int index = elem - minValue;
    counts[index] += 1;
  }
  auto sorted = std::vector<int>();
  for (int i = 0; i < counts.size(); i++) {
    int value = i + minValue;
    auto count = counts[i];
    for (int c = 0; c < count; c++) {
      sorted.push_back(value);
    }
  }

  return sorted;
}

#endif /* CAW_SORTING_ALGORITHMS_COUNTING_SORT_CC_ */
