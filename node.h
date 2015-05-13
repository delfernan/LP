/**
 * @file node.h
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 *
 * @section LICENSE
 * Copyright 2015 Fernando Aparicio Galisteo Licensed under the
 * Educational Community License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may
 * obtain a copy of the License at
 *
 * http://www.osedu.org/licenses/ECL-2.0
 *
 */
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
