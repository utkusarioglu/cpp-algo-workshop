#ifndef CAW_SRC_LEETCODE_BUY_SELL_STOCK_H_
#define CAW_SRC_LEETCODE_BUY_SELL_STOCK_H_

#include <map>
#include <vector>

namespace BuySellStock
{
  using Prices = std::vector<int>;

  class BuySellStock
  {
  public:
    uint sortedDoubleLoop(Prices prices) const
    {
      Prices sorted;
      std::copy(prices.begin(), prices.end(), std::back_inserter(sorted));
      sort(sorted.begin(), sorted.end());

      std::map<int, uint> indices;
      for (uint i = 0; i < prices.size(); i++) {
        indices[prices[i]] = i;
      }

      for (uint l = 0; l < sorted.size() - 1; l++) {
        for (uint r = sorted.size() - 1; r > l; r--) {
          if (indices[sorted[l]] < indices[sorted[r]]) {
            return sorted[r] - sorted[l];
          }
        }
      }
      return 0;
    }

    uint singleLoop(Prices prices) const
    {
      int minPrice = prices[0];
      int maxProfit = 0;
      for (uint i = 0; i < prices.size(); i++) {
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
        minPrice = std::min(prices[i], minPrice);
      }

      return maxProfit;
    }
  };
}  // namespace BuySellStock

#endif /* CAW_SRC_LEETCODE_BUY_SELL_STOCK_H_ */
