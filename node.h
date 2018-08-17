#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

struct Node;

using csr = const string&;
using NodePtr = shared_ptr<Node>;

struct Node: public enable_shared_from_this<Node>
{
  string m_value;
  vector<NodePtr> m_incomingEdges;
  vector<NodePtr> m_outgoingEdges;
  
  Node(csr value):
    m_value(value)
  {}

  virtual void edgeTo(Node& node)
  {
    // Workaround for bad_weak_ptr exception, can be remove after C++17
    auto pthis = shared_ptr<Node>(this, [](Node*) {}); 
    node.setIncoming(shared_from_this());
    m_outgoingEdges.push_back(make_shared<Node>(node));
  }

  void removeEdge(bool isIncoming = true)
  {
    if (isIncoming && m_incomingEdges.size()) 
    {
      auto incoming = m_incomingEdges.back();
      incoming->removeEdge(false);
      m_incomingEdges.pop_back();
    }
    else
    {
      if(m_outgoingEdges.size()) m_outgoingEdges.pop_back();
    }
  }
  
  private:
    
    void setIncoming(const NodePtr& node)
    {
      node->m_incomingEdges.push_back(node);
    }
};

#endif
