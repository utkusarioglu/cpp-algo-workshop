#ifndef CAW_TEST_SORTING_ALGORITHMS_RADIX_SORT_UNIT_TEST_CC_
#define CAW_TEST_SORTING_ALGORITHMS_RADIX_SORT_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <vector>

#include "sorting_algorithms/radix_sort.h"

namespace SortingAlgorithms::RadixSort::UnitTest
{
  using Uv = std::vector<uint>;

  class RadixSortTf : public ::testing::TestWithParam<Uv>
  {
  protected:
    uint params;

  public:
    Uv sort(Uv unsorted)
    {
      Uv sorted;
      std::copy(unsorted.begin(), unsorted.end(), std::back_inserter(sorted));
      std::sort(sorted.begin(), sorted.end());
      return sorted;
    }
  };

  INSTANTIATE_TEST_SUITE_P(
    RadixSort, RadixSortTf,
    ::testing::Values(
      Uv{}, Uv{1}, Uv{1, 2}, Uv{2, 1}, Uv{1, 2, 3}, Uv{3, 2, 1},
      Uv{6, 5, 1, 110, 15234, 101},
      Uv{288347, 962557, 729781, 87436, 740484, 900912, 759280, 631052},
      Uv{
        288347, 962557, 729781, 87436, 740484, 900912, 759280, 631052, 733636,
        289207, 594260, 341146, 997783, 946845
      },
      Uv{71575,  853482, 5269,   284513, 930030, 17173,  424511, 379249, 977456,
         898755, 190641, 398293, 632647, 220020, 196594, 163647, 590383, 566946,
         818400, 824350, 652780, 829338, 979048, 935268, 526124, 259441, 672598,
         644541, 681312, 197122, 103017, 257990, 901318, 337505, 942730, 485203,
         44608,  446700, 476045, 285976, 617200, 560710, 980170, 222929, 39028},
      Uv{921752, 3783,   71956,  780205, 691992, 579521, 239,    51714,  875912,
         256962, 97273,  768534, 963168, 336572, 264490, 3004,   343496, 14192,
         908283, 51828,  101699, 752603, 158636, 763569, 91,     776836, 92695,
         81538,  900598, 153524, 530039, 437568, 1,      6,      7,      880282,
         292238, 18,     969367, 490439, 448120, 473165, 851782, 85246,  647482,
         112004, 44792,  85139,  680,    829,    56,     908832, 465837, 52,
         126456, 5171,   643873, 734,    225804, 10,     184748, 24015,  487,
         139864, 44891,  971530, 179833, 367024, 1,      342079, 156497, 89629,
         31195,  930,    498,    662021, 110319, 368914, 30654,  288399, 963,
         945363, 55808,  112012, 977345, 328421, 957,    282495, 367272, 3547,
         951654, 528577, 689033, 187245, 8217,   98369,  383,    803}
    )
  );

  TEST_P(RadixSortTf, Happy)
  {
    Uv unsorted = GetParam();
    Uv response = radixSort(unsorted);
    Uv expected = sort(unsorted);

    ASSERT_EQ(expected, response);
  }
}  // namespace SortingAlgorithms::RadixSort::UnitTest

#endif /* CAW_TEST_SORTING_ALGORITHMS_RADIX_SORT_UNIT_TEST_CC_ */
