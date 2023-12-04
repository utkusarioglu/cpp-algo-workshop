#ifndef CAW_SRC_LEETCODE_CLONE_GRAPH_CC_
#define CAW_SRC_LEETCODE_CLONE_GRAPH_CC_

#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

namespace CloneGraph
{

  struct Node;

  using Pair = std::pair<size_t, size_t>;
  using Definitions = std::vector<Pair>;
  using SharedNode = std::shared_ptr<Node>;
  using NodeMap = std::map<size_t, SharedNode>;
  using NodeVec = std::vector<SharedNode>;
  using NodeQueue = std::deque<SharedNode>;
  using NeighborsSet = std::unordered_set<SharedNode>;

  struct Node {
    int val;
    NeighborsSet neighbors;
  };

  class CloneGraph
  {
  public:
    static SharedNode parse(Definitions definitions)
    {
      using GetNode = std::function<SharedNode(size_t)>;
      NodeMap nodes;

      GetNode getNode = [&nodes](size_t key) {
        if (!nodes.contains(key)) {
          std::unordered_set<SharedNode> neighbors;
          auto node = std::make_shared<Node>(key, neighbors);
          nodes.emplace(key, node);
        }
        return nodes[key];
      };

      for (size_t i = 0; i < definitions.size(); i++) {
        size_t nodeKey = definitions[i].first;
        size_t neighborKey = definitions[i].second;
        auto node = getNode(nodeKey);
        auto neighbor = getNode(neighborKey);
        node->neighbors.insert(neighbor);
      }

      return nodes[1];
    }

    static SharedNode copyBfs(SharedNode head)
    {
      NodeVec visited;
      NodeQueue queue;
      queue.push_back(head);

      while (!queue.empty()) {
        SharedNode node = queue.front();
        queue.pop_front();
        visited.push_back(node);
        for (auto neighbor : node->neighbors) {
          bool isVisited =
            std::find(visited.begin(), visited.end(), neighbor) !=
            visited.end();
          bool isQueued =
            std::find(queue.begin(), queue.end(), neighbor) != queue.end();
          if (isVisited || isQueued) {
            continue;
          }
          queue.push_back(neighbor);
        }
      }

      return head;
    }
  };
}  // namespace CloneGraph

#endif /* CAW_SRC_LEETCODE_CLONE_GRAPH_CC_ */
