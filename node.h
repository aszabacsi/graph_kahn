#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

using csr = const string&;

struct Node 
{
  string m_value;
  vector<Node> m_incomingEdges;
  vector<Node> m_outgoingEdges;
  
  Node(csr value):
    m_value(value)
  {}
  
  void edgeTo(Node& node)
  {
    node.setIncoming(this);
    outgoingEdges.push_back(node);
  }
  
  private:
    
    void setIncoming(Node& node)
    {
      node.m_incomingEdges.push_back(node);
    }
};

#endif
