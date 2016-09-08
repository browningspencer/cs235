//
//  main.cpp
//  lab_2
//
//  Created by Spencer Browning on 6/30/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//


/*
 Dictionary file
Best way to read in dictionary file: stringstream:
    string word;
    stringstream s;
    while(s >> word)
        myset.insert(word);
 
 
 Document File
    Use getline()
    
    int linenum;
    while(getline(...))
        linenum ++;
 
 
 
 
    stored in a map<string, list<int>>  //words, line numbers. It will need a list of all lines that word is on
 
    MAKE function that turns all letters lower case
        ss s(line);
        char c;
        int counter;
        while (s >> c) {
            counter ++;
            if(isalpha(c))
            {
                tolower(line[counter]);
            }
        }
 
    MAKE function that turns all puctuation (ex. don't. -> don t ) or anything that's not a letter into a space.
         make stringstream to hold the line:
         ss s(line)
         char c;
         int counter;
         while (s >> c)
         counter ++;
         if (isalpha(c))  //returns true if it is a letter
         { }
         else {
         line[counter] = " ";
         }

 
 Misspelled words
    map<string, list<int>>
 
    map[word].push_back(linenum);
 
 
 Comparing between dictionary and words I'm bringing in
    string word //word from document
    if (myset.count(word))  //myset would be the dictionary
 
 
 
    if(0) //gives back false
    if(1) //gives back true
 
 
 
 Output File/Print function
    word: 1, 2, 5, etc.
 
*/

#include <iostream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <sstream>
#include <ostream>
#include <istream>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <utility>
#include "Dictionary.h"
#include "Document.h"
//#include "newDocument.h"
using namespace std;


void print(string result, map<string, list<int>>& document)
{
    /*
    for (auto mapIterator : document) {
        cout << mapIterator.first << ": ";
        
        
        for (auto listIterator : mapIterator.second){
            cout << listIterator << " ";
        }
        
        cout << endl;
    }
    */
    
    ofstream output;
    output.open(result);
    
    for (auto mapIterator : document) {
        output << mapIterator.first << ": ";
        
        for (auto listIterator : mapIterator.second) {
            output << listIterator << " ";
        }
        
        output << endl;
    }
    output.close();
}




map<string, list<int>> find_misspelled(vector<Document> old_document, set<string> dictionary)
{
    list<int> line_num;
    map<string, list<int>> new_document;
    
    set<string>::iterator it;
    
    for (unsigned int i = 0; i < old_document.size(); i++)
    {
        it = dictionary.find(old_document[i].getWords());
        
        if (old_document[i].getWords() == " ")
        {
            //cout << "whitespace" << endl;
        }
        else if (*it != old_document[i].getWords()) //words that are in the dictionary file
        {
            
            new_document[old_document[i].getWords()].push_back(old_document[i].getLines());
            
        }
        else    //words that are misspelled
        {
            //cout << i << old_document[i].getWords() << endl;
        }
        
        
    }
    
    
    
    
    return new_document;
}

string spell_check(string old_words)
{
    string new_words;
    string result;
    
    transform(old_words.begin(), old_words.end(), old_words.begin(), ::tolower);
    remove_copy_if(old_words.begin(), old_words.end(), back_inserter(result), ptr_fun<int, int>(&ispunct));
    new_words = result;
    
    
    return new_words;
}


set <string> load_dictionary(string dictionary_file)
{
    ifstream in;
    set<string> dictionary;
    
    string word;
    
    in.open(dictionary_file);
    
    while (getline(in, word)) {
        
        
        transform(word.begin(), word.end(), word.begin(), ::tolower); //Converts word to lower case
        string result;
        remove_copy_if(word.begin(), word.end(), back_inserter(result), ptr_fun<int, int>(&ispunct)); //Removes punctuation
        word = result;
        
        //spell_check(word);
        
        string new_word = word;
        dictionary.insert(new_word);
    }
    
    in.close();
    
    return dictionary;
}



vector<Document> load_document(string document_file)
{
    ifstream in;
    vector<Document> document;
    
    string words;
    int line_num = 0;
    
    in.open(document_file);
    
    while (getline(in, words)) {
        line_num ++;
        
        
        transform(words.begin(), words.end(), words.begin(), ::tolower);
        string result;
        remove_copy_if(words.begin(), words.end(), back_inserter(result), ptr_fun<int, int>(&ispunct));
        words = result;
        
        //spell_check(words);
        
        istringstream iss(words);
        while (iss)
        {
            string word;
            iss >> word;
            Document new_line = Document(word, line_num);
            document.push_back(new_line);
        }
        
    }
    
    in.close();
    
    return document;
}


/*
void display(vector<Document> document, set<string> dictionary)
{
    for (unsigned int i = 0; i < document.size(); i++)
    {
        cout << document[i].getLines() << " " << document[i].getWords() << endl;
        
    }
    
    set<string>::iterator it;
    
    for (it=dictionary.begin(); it!=dictionary.end(); it++)
        cout <<  *it << endl;
    
}
*/



int main(int argc, const char* argv[]) {
    
    string dictionary_file = argv[1];
    string document_file = argv[2];
    string result = argv[3];
    //string dictionary_file = "in20a.txt";
    //string document_file = "in20b.txt";
    
    map<string, list<int>> document;
    document = find_misspelled(load_document(document_file), load_dictionary(dictionary_file));
    
    print(result, document);
    
    
    return 0;
}
