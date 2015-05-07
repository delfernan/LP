#ifndef PLAYER_H
#define PLAYER_H
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#define MAX_NAME_SIZE 50
class Player
{
public:
  Player();
  ~Player();

  const char* getNombre() const;
  void setNombre(const char* value);

  int getNGoles() const;
  void setNGoles(int value);

  void readFromFile(std::fstream &f);
  void writeToFile(std::fstream &f);
  void readFromBinaryFile(std::fstream &f);
  void writeToBinaryFile(std::fstream &f);
  std::string toStd ();
  bool compareName(Player e);
  int comparePoints(Player e);
private:
  char nombre[MAX_NAME_SIZE];
  int nGoles;
};

#endif // PLAYER_H
