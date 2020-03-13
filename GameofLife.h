#include "World.h"
#include<iostream>
using namespace std;

class GameofLife{
public:
  GameofLife(int h, int l, double dens, int gm);
  GameofLife(string fileName, int gm);
  GameofLife();
  ~GameofLife();
  void simulate();
  bool checkIfSame();

  void print();
  int count;
  World *board;
};
