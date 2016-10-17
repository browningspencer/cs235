#pragma once
#include "PathfinderInterface.h"
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <stack>

using namespace std;

class Pathfinder : public PathfinderInterface {
private:
  string my_maze;
  int rows, cols, floors;

  bool verifyMaze(string Maze);
  string formatMaze(string input);
  int getValue(const string& Maze, int x, int y, int z);
  bool setValue(string& Maze, int x, int y, int z, int value);
  string createCoords(int x, int y, int z);
  bool check(string& Maze, stack<string>& path, int x, int y, int z);

public:
  Pathfinder();
  ~Pathfinder();


  virtual string getMaze();
  virtual void createRandomMaze();
  virtual bool importMaze(string file_name);
  virtual vector<string> solveMaze();
  //-----------------------------------------------------------------------------------------

};
