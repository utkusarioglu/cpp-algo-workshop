#ifndef CAW_TEST_SEARCH_DFS_UNIT_TEST_CC_
#define CAW_TEST_SEARCH_DFS_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "search/dfs.h"

namespace Search::Dfs::UnitTest
{
  using Nodes = std::vector<std::string>;
  using Edges = std::vector<std::vector<size_t>>;

  struct TestCase {
    Nodes nodes;
    Edges edges;
    size_t startIndex;
    Nodes expected;
  };

  class DfsTf : public ::testing::TestWithParam<TestCase>
  {
  protected:
    TestCase param;

    Dfs *populate(TestCase t)
    {
      Dfs *d = new Dfs();
      for (std::string value : t.nodes) {
        Node *node = new Node(value);
        d->insert(node);
      }
      for (size_t i = 0; i < t.edges.size(); i++) {
        Node *node = d->getNodeByIndex(i);
        for (size_t edgeIndex : t.edges[i]) {
          node->addEdge(d->getNodeByIndex(edgeIndex));
        }
      }
      return d;
    }
  };

  INSTANTIATE_TEST_SUITE_P(
    Dfs, DfsTf,
    ::testing::Values(
      // happy
      TestCase{Nodes{"A", "B", "C"}, Edges{{1}, {2}, {}}, 0, {"A", "B", "C"}},
      TestCase{
        Nodes{"A", "B", "C", "D"},
        Edges{{1}, {2}, {3}, {}},
        0,
        {"A", "B", "C", "D"}
      },

      // reverse
      TestCase{Nodes{"A", "B"}, Edges{{}, {0}}, 1, {"B", "A"}},
      TestCase{
        Nodes{"A", "B", "C", "D", "E", "F", "G"},
        Edges{{}, {0}, {1}, {2}, {3}, {4}, {5}},
        6,
        {"G", "F", "E", "D", "C", "B", "A"}
      },

      // forward tree
      TestCase{Nodes{"A", "B", "C"}, Edges{{1, 2}, {}, {}}, 0, {"A", "B", "C"}},
      TestCase{
        Nodes{"A", "B", "C", "D"},
        Edges{{1, 2}, {3}, {}},
        0,
        {"A", "B", "D", "C"}
      },
      // reverse tree
      TestCase{Nodes{"A", "B", "C"}, Edges{{}, {}, {1, 0}}, 2, {"C", "B", "A"}},
      TestCase{
        Nodes{"A", "B", "C", "D"},
        Edges{{}, {}, {1, 0}, {2}},
        3,
        {"D", "C", "B", "A"}
      }
    )
  );

  TEST_P(DfsTf, SizeMatch)
  {
    const TestCase t = GetParam();
    Dfs *d = this->populate(t);
    std::vector<Node *> res = d->search(t.startIndex);
    ASSERT_EQ(res.size(), t.expected.size());
  };

  TEST_P(DfsTf, ElemsMatch)
  {
    const TestCase t = GetParam();
    Dfs *d = this->populate(t);
    std::vector<Node *> res = d->search(t.startIndex);
    for (size_t i = 0; i < res.size(); i++) {
      ASSERT_EQ(res[i]->getValue(), t.expected[i]);
    }
  };

};  // namespace Search::Dfs::UnitTest

#endif /* CAW_TEST_SEARCH_DFS_UNIT_TEST_CC_ */
