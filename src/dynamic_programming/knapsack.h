#ifndef CAW_SRC_DYNAMIC_PROGRAMMING_KNAPSACK_H_
#define CAW_SRC_DYNAMIC_PROGRAMMING_KNAPSACK_H_

#include <memory>
#include <string>
#include <vector>

namespace Knapsack
{
  struct Memo {
    uint price;
    float weight;
  };

  struct Item {
    const char *name;
    uint price;
    float weight;
  };

  using VecItems = std::vector<Item>;
  using SetIndices = std::set<uint>;
  using Memoized = std::map<SetIndices, Memo>;

  class Knapsack
  {
  public:
    Knapsack(VecItems items)
    {
      this->items = items;
    }

    uint recursive(float startWeight) const
    {
      SetIndices included;
      return this->recursive(startWeight, 0, included);
    }

    uint memoized(float weightThreshold) const
    {
      SetIndices included;
      Memoized memo{std::make_pair(SetIndices{}, Memo(0, 0.0))};
      uint maxPrice = this->memoized(weightThreshold, included, &memo);

      return maxPrice;
    }

  private:
    uint startWeight;
    VecItems items;

    SetIndices includeIndex(SetIndices indices, uint insertIndex) const
    {
      SetIndices newSet;
      std::copy(
        indices.begin(), indices.end(), std::inserter(newSet, newSet.begin())
      );
      newSet.insert(insertIndex);
      return newSet;
    }

    uint recursive(float startWeight, uint startPrice, SetIndices included)
      const
    {
      uint maxPrice = startPrice;

      for (uint i = 0; i < this->items.size(); i++) {
        if (included.contains(i)) {
          continue;
        }
        Item current = this->items[i];
        if (current.weight > startWeight) {
          continue;
        }
        float newWeight = startWeight - current.weight;
        uint newPrice = startPrice + current.price;
        uint finalPrice;
        if (newWeight > 0) {
          SetIndices newIncluded = this->includeIndex(included, i);
          finalPrice = this->recursive(newWeight, newPrice, newIncluded);
        } else {
          finalPrice = newPrice;
        }
        if (finalPrice > maxPrice) {
          maxPrice = finalPrice;
        }
      }

      return maxPrice;
    }

    uint memoized(float weightThreshold, SetIndices prevPath, Memoized *memo)
      const
    {
      if (!memo->contains(prevPath)) {
        std::runtime_error("Index not in memo");
      }
      Memo prev = (*memo)[prevPath];
      uint maxPrice = prev.price;

      for (uint i = 0; i < this->items.size(); i++) {
        if (prevPath.contains(i)) {
          continue;
        }
        Item current = this->items[i];
        SetIndices currentPath = this->includeIndex(prevPath, i);
        float newWeight = prev.weight + current.weight;
        if (newWeight > weightThreshold) {
          memo->emplace(std::make_pair(currentPath, prev));
          continue;
        }
        uint newPrice = prev.price + current.price;
        memo->emplace(std::make_pair(currentPath, Memo(newPrice, newWeight)));
        uint finalPrice = this->memoized(weightThreshold, currentPath, memo);

        if (finalPrice > maxPrice) {
          maxPrice = finalPrice;
        }
      }

      return maxPrice;
    }
  };

}  // namespace Knapsack

#endif /* CAW_SRC_DYNAMIC_PROGRAMMING_KNAPSACK_H_ */
