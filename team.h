/**
 * @file team.h
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
#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>

class Team
{
public:
  Team();
  ~Team();

  const char* getNombre() const;
  void setNombre(const char* value);

  int getVictorias() const;
  void setVictorias(int value);

  int getDerrotas() const;
  void setDerrotas(int value);

  int getEmpates() const;
  void setEmpates(int value);

  int getGolesAFavor() const;
  void setGolesAFavor(int value);

  int getGolesEnContra() const;
  void setGolesEnContra(int value);

  void readFromFile(std::fstream &f);
  void writeToFile(std::fstream &f);
  void readFromBinaryFile(std::fstream &f);
  void writeToBinaryFile(std::fstream &f);
  std::string toStd ();
  int compareName(Team e);
  bool comparePoints(Team e);
private:
  char nombre[MAX_NAME_SIZE];
  int victorias;
  int derrotas;
  int empates;
  int golesAFavor;
  int golesEnContra;
  int calculaPuntos();
};

#endif // TEAM_H
