/**
 * @file list.cpp
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 * @date 2012-2015
 * @brief List class
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
#ifndef LIST_CPP
#define LIST_CPP
#include "list.h"

template <class T>
List<T>::List(){
  init();
}
template <class T>
void List<T>::init(){
  this->liga_=NULL;
  this->lon_=0;
}
template <class T>
List<T>::~List(){
  Node<T> * aux=NULL;
  while(liga_!=NULL){
    aux=liga_;
    liga_=liga_->next;
    delete aux;
  }
}
template <class T>
bool List<T>::isEmpty() {
  return (liga_==NULL);
}
template <class T>
size_t List<T>::length(){
  return this->lon_;
}
template <class T>
void List<T>::insertAfter (T e){
  if (liga_ != NULL){
    Node<T> * aux;
    //No es necesario reservar memoria, aux es una variable puntero
    //(ya tiene memoria para almacenar la dirección de liga)
    for (aux=liga_;aux->next!=NULL;aux=aux->next){}
    aux->next=new Node<T>(e);
  } else {
    liga_=new Node<T>(e);
  }
  this->lon_++;
}
template <class T>
void List<T>::insert (size_t pos, T e){
  //assert (pos != 0 && this->length()+1>=pos); //no es posible asignar esa posición
  if(this->isEmpty()){
    liga_=new Node<T>(e);
  }else if(pos==1){
    liga_=new Node<T>(e,liga_);
  }else{
    Node<T> * aux=liga_;
    for(size_t i=1;i<pos-1;aux=aux->next){i++;}
    aux->next=new Node<T>(e,aux->next);
  }
  this->lon_++;
}

template <class T>
T List<T>::searchPos(size_t pos){
//  assert(!this->isEmpty()); //List vacía
//  assert(pos !=0 && this->length() >= pos); //Posición incorrecta
  Node<T> * aux;
  size_t i=1;
  for(aux=liga_;i<pos;aux=aux->next)
      i++;

  return aux->info;
}
template <class T>
void List<T>::modify(size_t pos, T e){
//  assert (pos != 0 && this->length()>=pos); //no existe esa posición en la lista
  Node<T> * aux=liga_;
  for(size_t i=1;i<pos;aux=aux->next) i++;
  aux->info=e;
}
template <class T>
void List<T>::erase(size_t pos){
//  assert (!this->isEmpty()); //lista vacía
//  assert (pos != 0 && this->length()>=pos); //no existe esa posición en la lista
  Node<T> * aux=liga_;
  Node<T> * nodeToErase;
  if(pos==1){
    nodeToErase=aux;
    aux=aux->next;
    liga_=aux;
  }else{
    for(size_t i=1;i<pos-1;i++)
        aux=aux->next;
    nodeToErase=aux->next;
    aux->next=aux->next->next;
    }
  delete nodeToErase;
  this->lon_--;
}
template <class T>
void List<T>::insertSorted(T e){
  if (liga_==NULL){ //si la lista está vacia, lo ponemos a la cabeza de la lista
    liga_=new Node<T>(e);
  } else if(e.comparePoints(liga_->info)) {// si el primer elemento de la lista ya es mayor que nuestro elemento lo insertamos el primero
    liga_=new Node<T>(e,liga_);
  } else { //recorremos la lista hasta quedarnos en el ultimo que sea menor que nuestro elemento
    Node<T> * aux=liga_;
    while ((aux->next!=NULL) && (aux->next->info.comparePoints(e)))
      aux=aux->next;
    // Ahora lo insertamos despues de ptraux
    aux->next=new Node<T>(e,aux->next);
  }
  this->lon_++;
}
template <class T>
void List<T>::copy(List<T> &lNew){
  Node<T> * orig;
  for(orig=liga_;orig!=NULL;orig=orig->next)
    lNew.insertAfter(orig->info);
}
template <class T>
void List<T>::copySorted(List<T> &lNew){
  Node<T> * orig;
  for(orig=liga_;orig!=NULL;orig=orig->next)
    lNew.insertSorted(orig->info);
}
template <class T>
void List<T>::sort(){
  Node<T> * aux, * auxsig;
  //Primer nodo
  aux=liga_;
  //Comenzamos el bucle comprobando si el segundo (así no pasa cuando longitud=1)
  while(aux->next != NULL){
    auxsig = aux->next;
    //Recorremos auxsig desde el segundo hasta el final (longitud)
    while(auxsig!=NULL){
      //Comparo el n+i (con i=1,...,longitud) con el n, si es verdadero, intercambio el n+i con el n
      //De este modo el nodo n queda ordenado
      if(auxsig->info.comparePoints(aux->info)){
        T temp=auxsig->info;
        auxsig->info = aux->info;
        aux->info = temp;
      }
      //Paso al siguiente para comparar el nodo n+i, recorriendo desde n+1 hasta longitud
      auxsig = auxsig->next;
    }
    //Repito la operación con el siguiente nodo
    aux = aux->next;
  }
}
template <class T>
void List<T>::sortDesc(){
  Node<T> * aux, * auxsig;
  aux=liga_;
  while(aux->next != NULL){
    auxsig = aux->next;
    while(auxsig!=NULL){
      if(aux->info.comparePoints(auxsig->info)){
        T temp=auxsig->info;
        auxsig->info = aux->info;
        aux->info = temp;
      }
      auxsig = auxsig->next;
    }
    aux = aux->next;
  }
}
template <class T>
size_t List<T>::searchEleName(T e){
  size_t iPos=0,iTemp=0;
  Node<T> * aux;
  for(aux=liga_;aux!=NULL && !iPos;aux=aux->next){
    iTemp++;
    if(aux->info.compareName(e)!=0)
      iPos=iTemp;
    }
  return iPos;
}
template <class T>
bool List<T>::readFromFile(const char * fileName){
  bool fileloaded=false;
  std::fstream f;
  //abro el fichero
  f.open(fileName, std::fstream::in);
  //si no se abre o está vacío devuelvo falso
  if (!f || f.peek() == std::ifstream::traits_type::eof()){
    fileloaded=false;
  }else{
    //leo los datos del fichero
    while (!f.eof()){
      T e;
      e.readFromFile (f);
      insertAfter(e);
    }
    f.close();
    fileloaded=true;
  }
  return fileloaded;
}
template <class T>
bool List<T>::writeToFile(const char * fileName){
  bool filesaved=false;
  std::fstream f;
  //abro el fichero
  f.open(fileName, std::fstream::out);
  if (!f){
    filesaved=false;
  }else{
    //Escribo los datos de la lista en el fichero
    Node<T> * l=liga_;
    while (l!=NULL){
      l->info.writeToFile(f);
      l=l->next;
      if (l!=NULL)
        f<<std::endl;
    }
    f.close();
    filesaved=true;
  }
  return filesaved;
}
template <class T>
bool List<T>::readFromBinaryFile(const char * fileName){
  bool fileloaded=false;
  std::fstream f;
  //abro el fichero para lectura binaria
  f.open(fileName, std::ios::in| std::ios::binary);
  //si no se abre o está vacío devuelvo falso
  if (!f || f.peek() == std::ifstream::traits_type::eof())
    fileloaded=false;
  else{
    //leo los datos del fichero cargando un objeto en cada vuelta
    while (f.peek() != std::ifstream::traits_type::eof()){
      T e;
      e.readFromBinaryFile (f);
      insertAfter(e);
    }
    f.close();
    fileloaded=true;
  }
  return fileloaded;
}
template <class T>
bool List<T>::writeToBinaryFile(const char * fileName){
  bool filesaved=false;
  std::fstream f;
  //abrimos el archivo para escritura binaria
  f.open(fileName, std::ios::out| std::ios::binary);
  //For appending
  //f.open(fileName,ios::out|ios::binary|ios::app);
  if(!f)
    filesaved=false;
  else{
    //Escribo los datos de la lista en el fichero
    Node<T> * l=liga_;
    while (l!=NULL){
      l->info.writeToBinaryFile(f);
      l=l->next;
    }
    f.close();
    filesaved=true;
  }
  return filesaved;
}
template <class T>
bool List<T>::readFromBinaryFile2(const char * fileName){
  bool fileloaded=false;
  std::fstream f;
  //abro el fichero para lectura binaria
  f.open(fileName, std::ios::in| std::ios::binary);
  //si no se abre o está vacío devuelvo falso
  if (!f || f.peek() == std::ifstream::traits_type::eof())
    fileloaded=false;
  else{
    //leo los datos del fichero cargando un objeto en cada vuelta
    T e;
    while (f.read(reinterpret_cast<char *>(&e),sizeof(T))){
      insertAfter(e);
    }
    f.close();
    fileloaded=true;
  }
  return fileloaded;
}
template <class T>
bool List<T>::writeToBinaryFile2(const char * fileName){
  bool filesaved=false;
  std::fstream f;
  //abrimos el archivo para escritura binaria
  f.open(fileName, std::ios::out| std::ios::binary);
  //For appending
  //f.open(fileName,ios::out|ios::binary|ios::app);
  if(!f)
    filesaved=false;
  else{
    //Escribo los datos de la lista en el fichero
    Node<T> * l=liga_;
    while (l!=NULL){
      f.write(reinterpret_cast<const char*>(&l->info),sizeof(T));
      l=l->next;
    }
    f.close();
    filesaved=true;
  }
  return filesaved;
}

template <class T>
std::string List<T>::toStd (){
  std::stringstream res;
  Node<T> * l=liga_;
  while (l!=NULL){
    res <<l->info.toStd<<std::endl;
    l=l->next;
  }
  return res.str();
}

#endif // LIST_CPP
