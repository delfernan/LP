/**
 * @file node.cpp
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 * @date 2012-2015
 * @brief Node class
 * @copyright ECL-2.
 * @section LICENSE
 * Copyright 2015 Fernando Aparicio Galisteo Licensed under the
 * Educational Community License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may
 * obtain a copy of the License at
 *
 * http://www.osedu.org/licenses/ECL-2.0
 *
 */
#include "node.h"

template <class T>
Node<T>::Node(){
  this->next=NULL;
}

template <class T>
Node<T>::Node(T pinfo, Node *pnext){
  this->info=pinfo;
  this->next=pnext;
}

template <class T>
Node<T>::~Node(){
}

