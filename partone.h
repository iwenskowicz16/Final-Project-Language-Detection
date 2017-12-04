#ifndef _partone_h
#define _partone_h
#include <vector>
#include "obj.h"

std::vector<int> makeIntVec();		//creates a vector filled with 0's at the size of 19.4k

std::vector<int> doProb(OBJ comparator);
												//merges the object that keeps track of the file contents with the vector filled with 0's
#endif