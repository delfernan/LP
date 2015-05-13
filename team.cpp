/**
 * @file team.cpp
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 * @date 2012-2015
 * @brief Team object
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
#include "team.h"

Team::Team(){
  this->victorias=0;
  this->derrotas=0;
  this->empates=0;
  this->golesAFavor=0;
  this->golesEnContra=0;
}

Team::~Team(){

}
const char* Team::getNombre() const{
  return nombre;
}
void Team::setNombre(const char * value){
  strcpy_s(nombre,MAX_NAME_SIZE,value);
}
int Team::getVictorias() const{
  return victorias;
}
void Team::setVictorias(int value){
  victorias = value;
}
int Team::getDerrotas() const{
  return derrotas;
}
void Team::setDerrotas(int value){
  derrotas = value;
}
int Team::getEmpates() const{
  return empates;
}
void Team::setEmpates(int value){
  empates = value;
}
int Team::getGolesAFavor() const{
  return golesAFavor;
}
void Team::setGolesAFavor(int value){
  golesAFavor = value;
}
int Team::getGolesEnContra() const{
  return golesEnContra;
}
void Team::setGolesEnContra(int value){
  golesEnContra = value;
}

void Team::readFromFile(std::fstream & f){
  f.getline(this->nombre,MAX_NAME_SIZE,'#');
  f>>this->victorias >> this->derrotas >> this->empates
      >> this->golesAFavor>> this->golesEnContra;
  f.ignore(50,'\n');//leo hasta el fin de linea
}
void Team::writeToFile(std::fstream &f){
  f<<this->nombre<<"#"<<this->victorias<<" "<<this->derrotas<<" "
  <<this->empates<<" "<<this->golesAFavor<<" "<<this->golesEnContra<<" ";
}
void Team::readFromBinaryFile(std::fstream & f){
  f.read(reinterpret_cast<char*>(&this->nombre), sizeof(nombre));
  f.read(reinterpret_cast<char*>(&this->victorias), sizeof(int));
  f.read(reinterpret_cast<char*>(&this->derrotas), sizeof(int));
  f.read(reinterpret_cast<char*>(&this->empates), sizeof(int));
  f.read(reinterpret_cast<char*>(&this->golesAFavor), sizeof(int));
  f.read(reinterpret_cast<char*>(&this->golesEnContra), sizeof(int));
}
void Team::writeToBinaryFile(std::fstream &f){
  f.write(reinterpret_cast<char*>(&this->nombre), sizeof(nombre));
  f.write(reinterpret_cast<char*>(&this->victorias), sizeof(int));
  f.write(reinterpret_cast<char*>(&this->derrotas), sizeof(int));
  f.write(reinterpret_cast<char*>(&this->empates), sizeof(int));
  f.write(reinterpret_cast<char*>(&this->golesAFavor), sizeof(int));
  f.write(reinterpret_cast<char*>(&this->golesEnContra), sizeof(int));
}
int Team::calculaPuntos (){
  return (this->victorias*3+this->empates);
}
std::string Team::toStd(){
  std::stringstream res;
  res <<this->nombre<<". Puntos: "<< this->calculaPuntos()<<" ptos., "<<this->victorias<<" victorias, "
     <<this->derrotas<<" derrotas, "<<this->empates<<" empates.";
  return res.str();
}

int Team::compareName(Team e){
  return strcmp(this->nombre,e.nombre);
}

bool Team::comparePoints(Team e){
  return (this->calculaPuntos()>e.calculaPuntos());
}
