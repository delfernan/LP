#ifndef NODE_H
#define NODE_H
#include <team.h>

template <class T>
class Node
{
public:
  Node();
  Node(T pinfo, Node * pnext=NULL);
  ~Node();
  T info;
  Node * next;
};

#endif // NODE_H
