#include <iostream>
#include <fstream>
using namespace std;

class World
{
public:
  int height;
  int length;
  int gamemode;
  int **nextGen;
  int **nowGen;
  ofstream output;

  //const/decon
  World(int height, int length, double density, int gamemode);//done
  World(string file, int gamemode);//done
  ~World();//done

  //functions
  void printWorld();//done
  void readWorldFromFile(string inFileName);//done
  //bool checkIfSame();

  void setCell(int h, int l, int set);//done
  int getCell(int h, int l);//done

  int getClassic(int h, int l);
  int getDonut(int h, int l);
  int getMirror(int h, int l);

  void update();

};
