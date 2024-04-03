#ifndef CAW_SRC_SEARCH_DFS_H_
#define CAW_SRC_SEARCH_DFS_H_

#include <exception>
#include <stack>
#include <string>
#include <unordered_set>

namespace Search::Dfs
{
  class Node
  {
  private:
    std::string value;
    std::unordered_set<Node *> edges;

  public:
    Node(std::string value)
    {
      this->value = value;
    }

    void addEdge(Node *edge)
    {
      this->edges.insert(edge);
    }

    // bool containsEdge(Node *edge)
    // {
    //   return this->edges.contains(edge);
    // }

    const std::string getValue()
    {
      return this->value;
    }

    std::unordered_set<Node *> getEdges()
    {
      return this->edges;
    }
  };

  class Dfs
  {
  public:
    void insert(Node *node)
    {
      this->nodes.push_back(node);
    }

    Node *getNodeByValue(std::string value)
    {
      for (Node *node : this->nodes) {
        if (node->getValue() == value) {
          return node;
        }
      }
      return nullptr;
    }

    Node *getNodeByIndex(size_t index)
    {
      return this->nodes[index];
    }

    const std::vector<Node *> search(size_t startIndex)
    {
      // check if start index exists
      if (startIndex >= this->nodes.size()) {
        throw std::overflow_error("No such search index");
      }

      std::stack<Node *> stack;
      std::vector<Node *> res;
      stack.push(this->nodes[startIndex]);

      while (!stack.empty()) {
        Node *current = stack.top();
        stack.pop();
        res.push_back(current);
        for (Node *edge : current->getEdges()) {
          stack.push(edge);
        }
      }

      return res;
    }

  private:
    std::vector<Node *> nodes;
  };
};  // namespace Search::Dfs

#endif /* CAW_SRC_SEARCH_DFS_H_ */
