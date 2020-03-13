#include "World.h"
#include <iostream>
#include <fstream>
using namespace std;

//const 1, density given
World::World(int h, int l, double density, int gm){
  height = h;
  length = l;
  gamemode = gm;

  nowGen = new int*[height];
  nextGen = new int*[height];
  for(int i = 0; i<height;i++){
    nowGen[i] = new int[length];
    nextGen[i] = new int[length];
  }

  for(int i = 0;i<height;i++){
    for(int j = 0;j<length;j++){
      if((rand()%100)<(density*100)){//if random variable is smaller than density(a decimal), we fill with 1. simple but works
        //1 is equal to X and 0 is equal to 1.
        //filling world based on density
        nowGen[i][j] = 1;
        nextGen[i][j] = 1;
      }else{
        nowGen[i][j] = 0;
        nextGen[i][j] = 0;
      }
    }
  }
}

//const 2, file given
World::World(string inFileName, int gm){
  gamemode = gm;
  readWorldFromFile(inFileName);
}


World::~World(){
  for(int i=0;i<height;i++){
    delete nowGen[i];
    delete nextGen[i];
  }
  delete nowGen;
  delete nextGen;
}



void World::printWorld(){
  for(int i=0; i<height;i++){
    for(int j=0; j<length;j++){
      if(nextGen[i][j]==1){
        std::cout << "X ";
      }else{
        std::cout << "- ";
      }
    }
    cout<<endl;
  }
}


void World::readWorldFromFile(string inFileName){
  ifstream inFile(inFileName);
  if(inFile){
    string s = "";
    int i=0;

    //get dimensions
    while(getline(inFile,s)){
      if(i==0){
        height=stoi(s);
      }else if(i==1){
        length=stoi(s);
        break;

      }
      i++;
    }

    //make the arrays
    nowGen = new int*[height];
    nextGen = new int*[height];
    for(int i = 0; i<height;i++){
      nowGen[i] = new int[length];
      nextGen[i] = new int[length];
    }

    //input the world
    i=0;
    while(getline(inFile, s)){
      for(int j=0;j<s.length();j++){
        if(s[j]=='X'){
          nowGen[i][j]=1;
          nextGen[i][j]=1;
        }else if(s[j]=='-'){
          nowGen[i][j]=0;
          nextGen[i][j]=0;
        }
      }
      i++;
    }

  }else{
    std::cout << "File not found" << '\n';
    inFile.close();
  }
}


void World::setCell(int h, int l, int set){
  nextGen[h][l] = set;
}

int World::getClassic(int h, int l){
  if(h < height && l < length && h>=0 && l>=0){
    return nowGen[h][l];
  }else{
    return 0;
  }
}

int World::getDonut(int h, int l){
  if (h < height && l < length && h>=0 && l>=0){
    return nowGen[h][l];
  }
		//returns donut values if requested outside of normal
	if (h<0){
    h = height-1;
  }else if (h>=height){
    h = 0;
  }

	if (l<0){
    l = length-1;
  }else if (l>=length){
    l = 0;
  }

	return nowGen[h][l];
}

int World::getMirror(int h, int l){
  if (h < height && l < length && h>=0 && l>=0){
    return nowGen[h][l];
  }
		//returns mirror values if requested outside of normal
	if (h<0){
    h = 0;//if its -1, gotta return rows at 0, and it will never ask for -2 as an input
  }else if (h>=height){
    h--;
  }

	if (l<0){
    l = 0;
  }else if (l>=length){
    l--;;
  }

  return nowGen[h][l];
}

int World::getCell(int h, int l){
  if(gamemode==1){
    return getClassic(h,l);
  }else if(gamemode==2){
    return getDonut(h,l);
  }else if(gamemode==3){
    return getMirror(h,l);
  }
}

void World::update(){
  for (int i = 0; i < height; ++i){
    for (int j = 0; j < length; ++j){
			nowGen[i][j] = nextGen[i][j];
		}
  }
}
