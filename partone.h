#ifndef _partone_h
#define _partone_h
#include <vector>
#include "obj.h"

std::vector<int> makeIntVec();		//creates a vector filled with 0's at the size of 19.4k

std::vector<std::string> make19kVec();		//creates all possible 3 letter combinations using a triple nested loop

std::vector<int> doProb(std::vector<std::string> gnk, std::vector<int> git, OBJ comparator);
												//merges the object that keeps track of the file contents with the vector filled with 0's
OBJ getData(filename);		//gets the data

#endif