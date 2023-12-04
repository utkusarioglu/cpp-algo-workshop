#ifndef CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_
#define CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "shuffling_algorithms/fisher_yates.h"

namespace FisherYates
{
  namespace UnitTests
  {

    using IntVector = std::vector<int>;

    class FisherYatesTestFixture
        : public ::testing::TestWithParam<std::vector<int>>
    {
    protected:
      std::vector<int> param;
    };

    INSTANTIATE_TEST_SUITE_P(
      ShufflingAlgorithms, FisherYatesTestFixture,
      ::testing::Values(
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9},
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9},
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9},
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9},
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9},
        IntVector{1, 2, 3, 4, 5, 6, 7, 8, 9}
      )
    );

    TEST_P(FisherYatesTestFixture, Works)
    {
      auto param = GetParam();
      auto response = FisherYates::fisherYates(param);

      ASSERT_NE(param, response);

      std::set<int> paramSet(param.begin(), param.end());
      std::set<int> responseSet(response.begin(), response.end());

      ASSERT_EQ(responseSet, paramSet);
    }

  }  // namespace UnitTests
}  // namespace FisherYates

#endif /* CAW_TEST_SHUFFLING_ALGORITHMS_FISHER_YATES_UNIT_TEST_CC_ */
