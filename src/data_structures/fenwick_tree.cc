#ifndef CAW_SRC_DATA_STRUCTURES_FENWICK_TREE_CC_
#define CAW_SRC_DATA_STRUCTURES_FENWICK_TREE_CC_

#include <vector>

namespace FenwickTree
{
  using Value = int;
  using Values = std::vector<Value>;
  class FenwickTree
  {
  public:
    FenwickTree(size_t size)
    {
      this->size = size;
      this->values.assign(this->size, 0);
      this->bit.assign(this->size, 0);
    }

    Value sum(size_t index)
    {
      index += 1;
      Value res = 0;
      while (index > 0) {
        res += this->bit[index];
        index -= index & -index;
      }
      return res;
    }

    Value sum(size_t start, size_t end)
    {
      return this->sum(end) - this->sum(start);
    }

    void add(size_t index, int increment)
    {
      index += 1;
      this->values[index] += increment;
      int size = this->values.size();

      while (index <= size) {
        this->bit[index] += increment;
        index += index & -index;
      }
    }

  private:
    Values values;
    Values bit;
    size_t size;
  };

}  // namespace FenwickTree

#endif /* CAW_SRC_DATA_STRUCTURES_FENWICK_TREE_CC_ */
