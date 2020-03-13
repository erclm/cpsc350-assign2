#include "GameofLife.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

int main(int argc, char const *argv[]){
  //GameofLife play;
  string outFileName;
  ofstream outFile;
  int pause;
  char ans;
  std::cout << "===== Assuming all weird answers to: NO =====" << '\n';
  std::cout << "Read world from file? [y/n]" << '\n';
  std::cin >> ans;

  if(ans=='y'){
    string fileName;
    int gm;
    std::cout << "enter file name" << '\n';
    std::cin >> fileName;
    std::cout << "enter gamemode (1: classic, 2: donut, 3: mirror):" << '\n';
    std::cin >> gm;
    if(gm>3 || gm<1){
      std::cout << "enter valid gamemode" << '\n';
      return 0;
    }
    GameofLife play = GameofLife(fileName, gm);
    std::cout << "output mode? [1: enter for next generation, 2: pause in between generations, 3: out to file]" << '\n';
    std::cin >> pause;
    if(pause>3 || pause<1){
      std::cout << "enter valid mode" << '\n';
      return 0;
    }
    if(pause==3){
      std::cout << "enter output file name" << '\n';
      std::cin >> outFileName;
      outFile.open(outFileName);
    }

    int cnt = 0;

    do{
      if(pause==1){
        std::cout << cnt << '\n';
        play.board->printWorld();
        cin.clear();
        cin.ignore();
      }else if(pause==2){
        std::cout << cnt << '\n';
        play.board->printWorld();
        std::chrono::seconds dura(5);
        std::this_thread::sleep_for(dura);
      }else if(pause==3){
        outFile<< cnt << endl;
        for(int i=0;i<play.board->height;i++){
          for(int j=0;j<play.board->length;j++){
            if(play.board->nextGen[i][j] == 1){
      				outFile << "X ";
      			}else if(play.board->nextGen[i][j] == 0){
      				outFile << "- ";
      			}
          }
          outFile << endl;
        }
        outFile << endl;
      }

      play.simulate();
      cnt++;
    }while(!play.checkIfSame());
  }else{
    int h, l, gm;
    double dens;
    std::cout << "enter height of world:" << '\n';
    std::cin >> h;
    std::cout << "enter length of world:" << '\n';
    std::cin >> l;
    std::cout << "enter density(between 0 and 1, decmial):" << '\n';
    std::cin >> dens;
    if(dens>1){
      std::cout << "enter valid density" << '\n';
      return 0;
    }
    std::cout << "enter gamemode (1: classic, 2: donut, 3: mirror):" << '\n';
    std::cin >> gm;
    if(gm>3 || gm<1){
      std::cout << "enter valid gamemode" << '\n';
      return 0;
    }
    GameofLife play = GameofLife(h, l, dens, gm);
    std::cout << "output mode? [1: enter for next generation, 2: pause in between generations, 3: out to file]" << '\n';
    std::cin >> pause;
    if(pause>3 || pause<1){
      std::cout << "enter valid mode" << '\n';
      return 0;
    }
    if(pause==3){
      std::cout << "enter output file name" << '\n';
      std::cin >> outFileName;
      outFile.open(outFileName);
    }


    int cnt = 0;

    do{
      if(pause==1){
        std::cout << cnt << '\n';
        play.print();
        cin.clear();
        cin.ignore();
      }else if(pause==2){
        std::cout << cnt << '\n';
        play.print();
        std::chrono::seconds dura(5);
        std::this_thread::sleep_for(dura);
      }else if(pause==3){
        outFile<< cnt << endl;
        for(int i=0;i<play.board->height;i++){
          for(int j=0;j<play.board->length;j++){
            if(play.board->nextGen[i][j] == 1){
      				outFile << "X ";
      			}else if(play.board->nextGen[i][j] == 0){
      				outFile << "- ";
      			}
          }
          outFile << endl;
        }
        outFile << endl;
      }

      play.simulate();
      cnt++;
    }while(!play.checkIfSame());
  }


/*
  std::cout << "output mode? [1: enter for next generation, 2: pause in between generations, 3: out to file]" << '\n';
  std::cin >> pause;
  if(pause>3 || pause<1){
    std::cout << "enter valid mode" << '\n';
    return 0;
  }
  if(pause==3){
    std::cout << "enter output file name" << '\n';
    std::cin >> outFileName;
    outFile.open(outFileName);
  }


  int cnt = 0;

  do{
    if(pause==1){
      std::cout << cnt << '\n';
      play.print();
      cin.clear();
      cin.ignore();
    }else if(pause==2){
      std::cout << cnt << '\n';
      play.print();
      std::chrono::seconds dura(5);
      std::this_thread::sleep_for(dura);
    }else if(pause==3){
      outFile<< cnt << endl;
      for(int i=0;i<play.board->height;i++){
        for(int j=0;j<play.board->length;j++){
          if(play.board->nextGen[i][j] == 1){
    				outFile << "X ";
    			}else if(play.board->nextGen[i][j] == 0){
    				outFile << "- ";
    			}
        }
        outFile << endl;
      }
      outFile << endl;
    }

    play.simulate();
    cnt++;
  }while(!play.checkIfSame());

  */

}
