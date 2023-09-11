#ifndef CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_
#define CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_

#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include "../src/shuffling_algorithms/fisher_yates.h"

class FisherYatesTestFixture : public ::testing::TestWithParam<std::vector<int>>
{
protected:
  std::vector<int> param;
};

INSTANTIATE_TEST_SUITE_P(
    ShufflingAlgorithms,
    FisherYatesTestFixture,
    ::testing::Values(
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9},
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9},
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9},
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9},
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9},
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));

TEST_P(FisherYatesTestFixture, Works)
{
  auto param = GetParam();
  auto response = shuffling_algorithms::fisherYates(param);

  ASSERT_NE(param, response);

  std::set<int> paramSet(param.begin(), param.end());
  std::set<int> responseSet(response.begin(), response.end());

  ASSERT_EQ(responseSet, paramSet);
}

#endif /* CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_ */
