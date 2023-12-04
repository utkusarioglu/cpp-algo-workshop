#ifndef CAW_TEST_LEETCODE_BUY_SELL_STOCK_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_BUY_SELL_STOCK_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/buy_sell_stock.h"

namespace BuySellStock
{
  namespace UnitTests
  {
    struct TestCase {
      Prices params;
      uint expected;
    };

    class BuySellStockTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      BuySellStock, BuySellStockTf,
      ::testing::Values(
        TestCase(Prices{7, 1, 5, 3, 6, 4}, 5),
        TestCase(Prices{7, 6, 4, 3, 1}, 0)
      )
    );

    TEST_P(BuySellStockTf, sortedDoubleLoop)
    {
      BuySellStock b = BuySellStock();
      TestCase testCase = GetParam();
      uint response = b.sortedDoubleLoop(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

    TEST_P(BuySellStockTf, singleLoop)
    {
      BuySellStock b = BuySellStock();
      TestCase testCase = GetParam();
      uint response = b.singleLoop(testCase.params);

      ASSERT_EQ(response, testCase.expected);
    }

  }  // namespace UnitTests
}  // namespace BuySellStock

#endif /* CAW_TEST_LEETCODE_BUY_SELL_STOCK_UNIT_TEST_CC_ */
