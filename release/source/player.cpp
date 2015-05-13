/**
 * @file player.cpp
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 * @date 2012-2015
 * @brief Player object
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
#include "player.h"

Player::Player(){
  nGoles=0;
}

Player::~Player(){

}
const char* Player::getNombre() const{
  return nombre;
}
void Player::setNombre(const char * value){
  strcpy_s(nombre,MAX_NAME_SIZE,value);
}
int Player::getNGoles() const{
  return nGoles;
}
void Player::setNGoles(int value){
  nGoles = value;
}
void Player::readFromFile(std::fstream & f){
  f.getline(this->nombre,MAX_NAME_SIZE,'#');
  f>>this->nGoles;
  f.ignore(50,'\n');//leo hasta el fin de linea
}
void Player::writeToFile(std::fstream &f){
  f<<this->nombre<<"#"<<this->nGoles;
}
void Player::readFromBinaryFile(std::fstream & f){
  f.read(reinterpret_cast<char*>(&this->nombre), sizeof(nombre));
  f.read(reinterpret_cast<char*>(&this->nGoles), sizeof(int));
}
void Player::writeToBinaryFile(std::fstream &f){
  f.write(reinterpret_cast<char*>(&this->nombre), sizeof(nombre));
  f.write(reinterpret_cast<char*>(&this->nGoles), sizeof(int));
}
std::string Player::toStd(){
  std::stringstream res;
  res<<this->nombre<<", Goles: "<< this->nGoles;
  return res.str();
}
bool Player::compareName(Player e){
  return strcmp(this->nombre,e.nombre);
}
int Player::comparePoints(Player e){
  return (this->nGoles>e.getNGoles());
}
