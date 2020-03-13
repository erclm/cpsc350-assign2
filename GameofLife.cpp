#include "GameofLife.h"
#include <iostream>
#include <fstream>
using namespace std;

GameofLife::GameofLife(int h, int l, double dens, int gm){
  board = new World(h, l, dens, gm);
  count = 0;
}

GameofLife::GameofLife(string f, int gm){
  board = new World(f, gm);
  count = 0;
  //std::cout << "loaded" << '\n';
}

GameofLife::GameofLife(){

}

GameofLife::~GameofLife(){
  delete board;
}

void GameofLife::print(){
  //std::cout << "print" << '\n';
  board->printWorld();
}

bool GameofLife::checkIfSame(){
  for(int i=0;i<board->height;i++){
    for(int j=0;j<board->length;j++){
      if(board->nowGen[i][j]!=board->nextGen[i][j]){
        return false;
      }
    }
  }
  return true;
}

void GameofLife::simulate(){
  //update cus next is still simulated
  board->update();
  for(int i=0;i < board->height; i++){
    for(int j=0;j < board->length; j++){
      //n is now equal to number of alive cells in the 3x3 area
      int n = board->getCell(i-1,j-1) + board->getCell(i-1,j) + board->getCell(i-1,j+1) + board->getCell(i,j-1) + board->getCell(i,j) + board->getCell(i,j+1) + board->getCell(i+1,j-1) + board->getCell(i+1,j) + board->getCell(i+1,j+1);

      if(n<=0){
        board->setCell(i,j,0);
      }else if(n==2){
        board->setCell(i,j,board->getCell(i,j));
      }else if(n==3){
        board->setCell(i,j,1);
      }else if(n>=4){
        board->setCell(i,j,0);
      }

    }
  }
}
