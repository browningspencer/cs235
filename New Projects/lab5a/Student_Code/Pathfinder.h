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
  int x, y, z;

  bool verifyMaze(string Maze);
  string formatMaze(string input);
  int getValue(const string& Maze, int xs, int ys, int zs);
  bool setValue(string& Maze, int xs, int ys, int zs, int value);
  string createCoords(int xs, int ys, int zs);
  bool check(string& Maze, stack<string>& path, int xs, int ys, int zs);

public:
  Pathfinder();
  ~Pathfinder();


  virtual string getMaze();
  virtual void createRandomMaze();
  virtual bool importMaze(string file_name);
  virtual vector<string> solveMaze();
  //-----------------------------------------------------------------------------------------

};
