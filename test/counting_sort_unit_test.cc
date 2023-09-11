#ifndef CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_
#define CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_

#include <iostream>
#include <gtest/gtest.h>
#include "../src/sorting_algorithms/counting_sort.h"

TEST(CountingSort, Handles321)
{
  auto instance = new CountingSort();
  std::vector<int> params = {3, 2, 1};
  auto response = instance->loop(params);
  std::vector<int> expected = {1, 2, 3};

  ASSERT_EQ(response, expected);
}

TEST(CountingSort, Handles3216)
{
  auto instance = new CountingSort();
  std::vector<int> params = {3, 2, 1, 6};
  auto response = instance->loop(params);
  std::vector<int> expected = {1, 2, 3, 6};

  ASSERT_EQ(response, expected);
}

TEST(CountingSort, Handles32116)
{
  auto instance = new CountingSort();
  std::vector<int> params = {3, 2, 1, 1, 6};
  auto response = instance->loop(params);
  std::vector<int> expected = {1, 1, 2, 3, 6};

  ASSERT_EQ(response, expected);
}

TEST(CountingSort, Handles32_100_116)
{
  auto instance = new CountingSort();
  std::vector<int> params = {3, 2, 100, 1, 1, 6};
  auto response = instance->loop(params);
  std::vector<int> expected = {1, 1, 2, 3, 6, 100};

  ASSERT_EQ(response, expected);
}

TEST(CountingSort, Handles32_100_116_m5)
{
  auto instance = new CountingSort();
  std::vector<int> params = {3, 2, 100, 1, 1, 6, -5};
  auto response = instance->loop(params);
  std::vector<int> expected = {-5, 1, 1, 2, 3, 6, 100};

  ASSERT_EQ(response, expected);
}

#endif /* CAW_TEST_COUNTING_SORT_UNIT_TEST_CC_ */
