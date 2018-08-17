#ifndef ACYCLIC_NODE_H
#define ACYCLIC_NODE_H

#include <cassert>
#include "Node.h"

struct AcyclicNode: public Node
{
  AcyclicNode(csr value):
    Node(value)
  {}

  void edgeTo(Node& node) override
  {
    assert(&node != this);
    Node::edgeTo(node);
  }
};

#endif
