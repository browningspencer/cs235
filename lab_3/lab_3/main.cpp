//
//  main.cpp
//  lab_3
//
//  Created by Spencer Browning on 7/7/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//


/*
 Read in Dictionary set<string>
 Read in Board into vector<vector<string>>
 Compute Board Size
 
 Check for prefixes
 Check for words
 
 Print out results
 
 
    There can be multiple letters on one tile
        ex. Qu  Cats
    
 Dictionary File
	The only words that can be used
    Gets stored as a set<string>
    just use getline() to read it in
 
 
 Board File
	the white space is not always correct
	example:
        R B
        O O I
        T  R O H
	should be
        r b o
        o i t
        r o h
 
    //you will actually read in the board file twice
    //first time will be to get the board size
 
    while(ifstream >> temp) {
        count++;
    }
    size = sqrt(count); //Size would be the row/column size
 
    //second time will be to create the values of the tiles on the board
    
    vector<vector<string>>
        example
            myvector[0][1];

 for (unsigned int i = 0; i < board_length; i++)
        for (unsigned int j = 0; j < board_length; j++)
            ifstream >> temp;
            myvector[i].push_back(temp);
 
 Board Class
    int size;
 
	represent it as a vector(vector<string>);
	force all strings to lower case
	in >> s;
	Say if n = 9
	
 
	findWords()
 for each row
 for each column
 find(row, column)
 
	find(row, column)
 OFF
 BOARD
 BASE
 CASE ->
 Append tile[row][col]
 To Word
 ALREADY
 USED
 BASE
 CASE ->
 PREFIX
 BAD
 BASE
 CASE ->
 find(R, C + 1)
 (R, C - 1)
 (R - 1, C)   //8 Recursive
 
 
 
 
 Dictionary Class
	represent it as a set<string>;
	checkPrefix(string) //would tell me if it's a prefix of						//any of the words in the dictionary
 iterator i = set.lower_bound(string "ca")
 *i = cat
 //lower bound g
 
 if
 i = set.lower_bound(zz)
 i = set.end()
 
 
 
 
 Don't use "new"
 
 Don't open a test file and copy and paste it
	Do Save as instead
 
 It will always be a perfect square
 
 
 Important Set functions
    find(...)                           // Use to actually check full words
        if (find ("cats") != mySet.end()) //works if word is found
 
    lower_bound(...)                    // Use to find prefixes
        if(my_lower_bound() != mySet.end())  //lower bound returns an iterator (pointer) and you will
                                            // need to derefference that using a *
        use substr with lower_bound
 
        prefix == substr(dicWord)
        prefix == dicWord
 
Checking Board for words
    check [0][0] using lower_bound until you hit longer than 3
        check up
        check up right
        check right
        check ...
    say down worked [1][0]
        check up
        check up right
        check ...
 
    Recursion       //make it a bool?
        1. Base Case
            a. if (off_the_board)// anything < 0 or >= board_length
                return;
            b. if (already_used) //have a vector<vector<bool>> (basically the same board with bools)
                return;             //set to true if you go there
            c. if(word_no_good) //These are the 3 times that a recursion is bad
        2. Recursive Call       //If the Base cases fail (means there is a word or prefix found
                                //
            recur(int row, int col, vector<string>& my vec, string prefix;)
                if(word_is_found
                    add_the_word(...);
                if (recur(row + 1, col) ||
                    recur(row + 1, col + 1) ||
                    recur(row, col + 1) ||
                    recur(row - 1, col + 1) ||
                    recur(...)
        (3.) Wrapper function
 
            wraptheboard () {
                for ()
                    for () 
                        recur (i, j);
            }
 
 */



/*
 cout << "Going: UP" << endl;
 cout << "Current have_been" << endl;
 for (unsigned int i = 0; i < board_size; i++) {
 for (unsigned int j = 0; j < board_size; j++) {
 if (have_been[i][j] == true)
 cout << "true\t";
 else
 cout << "false\t";
 }
 cout << endl;
 }
 cout << row << col << "\tDictionary Size: " << dictionary.size() << "\tWord: "<< word << endl;
 */



#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int ZERO = 0;
const int MIN_LENGTH = 4;


bool base_cases(int& row, int& col, int& board_size, string& word, vector<vector<string>>& board, set<string>::iterator& prefix, set<string>& temp_dict, vector<vector<bool>>& have_been)
{
    bool base = false;
    
    if (row < ZERO || row >= board_size || col < ZERO || col >=board_size) { // off the board
        //cout << "OFF THE BOARD" << endl;
        return true;
    }
    string temp = word;
    temp += board[row][col];
    prefix = temp_dict.lower_bound(temp);
    string test_word = *prefix;
    test_word = test_word.substr(ZERO, temp.length());
    
    if (temp != test_word) {
        //cout << "BADWORD: " << temp << endl;
        return true;
    }
    
    if (have_been[row][col] == true) { //fails if it goes back to a tile it's already been to
        //cout << "HAVE BEEN HERE ALREADY: " << board[row][col] << " " << row << col << endl;
        return true;
    }
    
    return base;
}


bool recur(int row, int col, set<string>& dictionary, vector<vector<string>>& board, vector<vector<bool>> have_been, int& board_size, string word, set<string>& words_found)
{
    bool foo = false;
    set<string> temp_dict = dictionary;
    set<string>::iterator prefix;
    set<string>::iterator it;
    
    bool base = base_cases(row, col, board_size, word, board, prefix, temp_dict, have_been);
    if (base == true)
        return false;
    else {
        have_been[row][col] = true;
        // 1 Add to word  word += (contents of tile)
        word += board[row][col];
        
        // 2 Check prefix using lower_bound
        prefix = temp_dict.lower_bound(word);
        temp_dict.erase(temp_dict.begin(), prefix);
        
        
        if (word.length() >= MIN_LENGTH)
        {
            if (temp_dict.count(word))
            {
         
                it = temp_dict.find(word);
                words_found.insert(*it);
                temp_dict.erase(it);
                dictionary.erase(word);
                //cout << "FOUND WORD!!!!!\t\t\t" << *it << endl;
            }
            
        }
        /*
        if (word.length() == board_size * board_size)
        {
            
            return false;
            
        }
         */
        // 3 Recurs thru adjacent squares
        //up
        row--;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //up right
        col++;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //right
        row++;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //down right
        row++;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //down
        col--;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //down left
        col--;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //left
        row--;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        //up left
        row--;
        recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        
    }
    return foo;
}


set<string> findWords(set<string> dictionary, vector<vector<string>> board, int board_size)
{
    string word;
    set<string> words_found;
    
    for ( int row = 0; row < board_size; row++)
    {
        for ( int col = 0; col < board_size; col++)
        {
            vector<vector<bool>> have_been(board_size, vector<bool>(board_size));
            have_been[row][col] = false;
            
            recur(row, col, dictionary, board, have_been, board_size, word, words_found);
        }
    }
    
    return words_found;
}


 
 
int boardSize(string board_file)
{
    ifstream in;
    int board_size = 0;
    int count = 0;
    string temp;
    
    in.open(board_file);
    while (in >> temp)
        count++;
    board_size = sqrt(count);
    in.close();
    
    
    return board_size;
}


vector<vector<string>> loadBoard(string board_file, int board_size)
{
    ifstream in;
    vector<vector<string>> board(board_size);
    string letter;
    
    in.open(board_file);
    
    for ( int i = 0; i < board_size; i++)
    {
        for ( int j = 0; j < board_size; j++)
        {
            in >> letter;
            
            transform(letter.begin(), letter.end(), letter.begin(), ::tolower);
            
            board[i].push_back(letter);
        }
    }
    
    in.close();
    
    return board;
}



set <string> loadDictionary(string dictionary_file)
{
    ifstream in;
    set<string> dictionary;
    string word;
    
    in.open(dictionary_file);
    
    while (getline(in, word))
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
                
        string new_word = word;
        dictionary.insert(new_word);
        
    }
    
    in.close();
    
    return dictionary;
}

void checkPrefix(set<string> dictionary)
{
    
    
}


/*
void display(set<string> dictionary, vector<vector<string>> board, int board_size)
{
    set<string>::iterator it;
    
    cout << "\nDictionary: " << endl;
    for (it = dictionary.begin(); it != dictionary.end(); it++)
        cout << *it << endl;
    
    cout << "\nBoard: " << endl;
    for (unsigned int i = 0; i < board_size; i++)
    {
        for (unsigned int j = 0; j < board_size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}
*/

void print(string result, set<string> words_found, vector<vector<string>> board, int board_size)
{
    ofstream output;
    output.open(result);
    
    for ( int i = 0; i < board_size; i++) {
        for ( int j = 0; j < board_size; j++) {
            output << board[i][j] << " ";
        }
        output << endl;
    }
    
    output << endl;
    
    set<string>::iterator it;
    for (it = words_found.begin(); it != words_found.end(); it++)
        output << *it << endl;
    
    output.close();
}



int main(int argc, const char * argv[]) {
    
    string dictionary_file = argv[1];
    string board_file = argv[2];
    string result = argv[3];
    //string dictionary_file = "in30a.txt";
    //string board_file = "in30b.txt";
    
    set<string> dictionary = loadDictionary(dictionary_file);
    int board_size = boardSize(board_file);
    vector<vector<string>> board = loadBoard(board_file, board_size);
    
    set<string> words_found = findWords(dictionary, board, board_size);
    print(result, words_found, board, board_size);
    //display(dictionary, board, board_size);
    
    
    return 0;
}



