#include "Pathfinder.h"
using namespace std;


Pathfinder::Pathfinder() {
  rows = 5;
  cols = 5;
  floors = 5;
}
Pathfinder::~Pathfinder() {}


//##############################################################################
//
//##############################################################################

bool Pathfinder::verifyMaze(string Maze) {
  bool valid = true;
  valid = (Maze.length() == 125);
  valid = (this->getValue(Maze, 0, 0, 0) == 1 && this->getValue(Maze, 4, 4, 4) == 1);
  return valid;
}

string Pathfinder::formatMaze(string input) {
  if (!this->verifyMaze(input)) {
    return input;
  }

  string maze;
  for (int i = 0; i < (rows * floors); i++) {
    for (int j = 0; j < cols; j++) {
      maze += input.substr((cols * i) + j, 1);

      if ((j + 1) % cols != 0) {
        maze += " ";
      }
    }
    maze += '\n';
    if ((i + 1) % cols == 0 && (i + 1) != (rows * floors)) {
      maze += '\n';
    }
  }
  return maze;
}

int Pathfinder::getValue(const string& Maze, int x, int y, int z) {
  if ((x + 1) < 1 || (x + 1) > cols) {
    return -1;
  }
  if ((y + 1) < 1 || (y + 1) > rows) {
    return -2;
  }
  if ((z + 1) < 1 || (z + 1) > floors) {
    return -3;
  }
  int index = (z * rows * cols) + (y * cols) + x;

  stringstream ss;
  ss << Maze.substr(index, 1);
  int value;
  ss >> value;

  return value;
}

//Part 1-----------------------------------------------------------------------------------
/*
 * getMaze
 *
 * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
 * has yet been generated or imported.
 *
 * A valid string representation of a maze consists only of 125 1s and 0s (each separated
 * by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
 * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
 *
 * Cell (0, 0, 0) is represented by the first number in the string representation of the
 * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
 * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
 * sixth number. Increasing in z means moving downward to a new grid, meaning cell
 * (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
 *
 * Returns:		string
 *				A single string representing the current maze
 */

string Pathfinder::getMaze() {
  if (my_maze == "") {
    return this->formatMaze(string(125, '1'));
  }
  else {
    return this->formatMaze(my_maze);
  }
}

//##############################################################################
//
//##############################################################################

/*
 * createRandomMaze
 *
 * Generates a random maze and stores it as the current maze.
 *
 * The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
 * in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
 * solvable or unsolvable, and this method should be able to produce both kinds of mazes.
 */

void Pathfinder::createRandomMaze() {
  stringstream ss;
  int ones = 0;
  int zeros = 0;
  int max = 5;
  ss << 1;
  for (int i = 0; i < ((rows * cols * floors) - 2); i++) {
    int random_num = rand() % 2;

    if (abs(ones - zeros) > max) {
      if (ones > zeros) {
        random_num = 0;
      }
      else {
        random_num = 1;
      }
    }
    if (random_num == 1) {
      ones++;
    }
    else {
      zeros++;
    }
    ss << random_num;
  }
  ss << 1;

  my_maze = ss.str();
}


//##############################################################################
//
//##############################################################################

//Part 2-----------------------------------------------------------------------------------
/*
 * importMaze
 *
 * Reads in a maze from a file with the given file name and stores it as the current maze.
 * Does nothing if the file does not exist or if the file's data does not represent a valid
 * maze.
 *
 * The file's contents must be of the format described above to be considered valid.
 *
 * Parameter:	file_name
 *				The name of the file containing a maze
 * Returns:		bool
 *				True if the maze is imported correctly; false otherwise
 */
 // Rows, Cols, Floors
 // x, y, z

 bool Pathfinder::importMaze(string file_name) {

   bool valid = true;
   stringstream Maze;
   ifstream file (file_name.c_str());

   if (file.is_open()) {
     string line;
     int row_count = 0;
     while (getline(file, line) && valid) {
       if (line == "") {
         continue;
       }
       stringstream ss(line);
       string token;
       int col_count = 0;
       while (ss >> token) {
         if (token == "0" || token == "1") {
           Maze << token;
           col_count++;
         }
       }
       valid = (col_count == cols);
       row_count++;
     }
     valid = ((row_count == (rows * floors)) && this->verifyMaze(Maze.str()));
    
     if (valid) {
       my_maze = Maze.str();
     }
     return valid;
   }
   else {
     return false;
   }
 }

//##############################################################################
//
//##############################################################################

bool Pathfinder::setValue(string& Maze, int x, int y, int z, int value) {
  if ((x + 1) < 1 || (x + 1) > cols) {
    return false;
  }
  if ((y + 1) < 1 || (y + 1) > rows) {
    return false;
  }
  if ((z + 1) < 1 || (z + 1) > floors) {
    return false;
  }
  int index = (z * rows * cols) + (y * cols) + x;

  stringstream ss;
  ss << value;
  char newValue;
  ss >> newValue;

  Maze[index] = newValue;

  return true;
}

string Pathfinder::createCoords(int x, int y, int z) {
  stringstream ss;
  ss << "(" << x << ", " << y << ", " << z << ")";
  return ss.str();
}

bool Pathfinder::check(string& Maze, stack<string>& path, int x, int y, int z) {
  if (x == 4 && y == 4 && z == 4) {
    path.push(this->createCoords(x, y, z));
    return true;
  }
  else {
    if ((x + 1) < 1 || (x + 1) > cols) {
      return false;
    }
    if ((y + 1) < 1 || (y + 1) > rows) {
      return false;
    }
    if ((z + 1) < 1 || (z + 1) > floors) {
      return false;
    }
    if (this->getValue(Maze, x, y, z) == 1) {
      this->setValue(Maze, x, y, z, 2);
    }
    else {
      return false;
    }
  }

  //Recursive Checks
  if (this->check(Maze, path, x - 1, y, z) ||
      this->check(Maze, path, x + 1, y, z) ||
      this->check(Maze, path, x, y - 1, z) ||
      this->check(Maze, path, x, y + 1, z) ||
      this->check(Maze, path, x, y, z - 1) ||
      this->check(Maze, path, x, y, z + 1)) {
    path.push(this->createCoords(x, y, z));
    return true;
  }
  return false;
}

//Part 3-----------------------------------------------------------------------------------
/*
 * solveMaze
 *
 * Attempts to solve the current maze and returns a solution if one is found.
 *
 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
 * (or an empty vector if no solution is found). This list cannot contain duplicates, and
 * any two consecutive coordinates in the list can only differ by 1 for only one
 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
 * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
 * where x, y, and z are the integer coordinates of a cell.
 *
 * Understand that most mazes will contain multiple solutions
 *
 * Returns:		vector<string>
 *				A solution to the current maze, or an empty vector if none exists
 */

vector<string> Pathfinder::solveMaze() {
  string copy_of_maze = my_maze;
  stack<string> temp;
  vector<string> path;

  if (this->check(copy_of_maze, temp, 0, 0, 0)) {
    int count = 1;
    while (!temp.empty()) {
      path.push_back(temp.top());
      temp.pop();
      count++;
    }
  }
  return path;
}
