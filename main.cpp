#include "AcyclicNode.h"

void topological_sort(const vector<Node>& nodes)
{
  
  vector<Node> rootNodes;
  vector<Node> sorted;

  for (auto node : nodes)
  {
    if (node.m_incomingEdges.size() == 0)
    {
      rootNodes.push_back(node);
    }
  }

  while (rootNodes.size() != 0) 
  {
    auto root = rootNodes.back();
    rootNodes.pop_back();
    sorted.push_back(root);

    //TODO
  }
}

int main() 
{
  AcyclicNode a("a");
  AcyclicNode b("b");
  AcyclicNode c("c");
  AcyclicNode d("d");

  a.edgeTo(b);
  b.edgeTo(c);
  b.edgeTo(d);
  c.edgeTo(d);

  vector<Node> graph({a, b, c, d});

  topological_sort(graph);

  return 0;
}
