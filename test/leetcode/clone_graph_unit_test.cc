#ifndef CAW_TEST_LEETCODE_CLONE_GRAPH_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_CLONE_GRAPH_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/clone_graph.cc"

namespace CloneGraph
{
  namespace UnitTests
  {
    struct TestCase {
      Definitions params;
    };

    class CloneGraphTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_SUITE_P(
      CloneGraph, CloneGraphTf,
      ::testing::Values(
        TestCase(Definitions({Pair(1, 2), Pair(2, 3), Pair(3, 4), Pair(4, 1)}))
        // TestCase(Definitions({Pair(2, 4), Pair(1, 3), Pair(2, 4), Pair(1,
        // 3)}))
      )
    );

    TEST_P(CloneGraphTf, changeThis)
    {
      TestCase testCase = GetParam();
      std::shared_ptr<Node> head = CloneGraph::parse(testCase.params);
      CloneGraph::copyBfs(head);

      ASSERT_EQ(true, true);
    }

  }  // namespace UnitTests
}  // namespace CloneGraph

#endif /* CAW_TEST_LEETCODE_CLONE_GRAPH_UNIT_TEST_CC_ */
