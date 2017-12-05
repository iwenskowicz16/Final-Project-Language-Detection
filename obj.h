#ifndef _obj_h
#define _obj_h

#include <iostream>
#include <string>
#include <vector>

class OBJ {

public:

	OBJ(std::string s);			//all of these above are basic object declarations

	std::string getLet(int i);				//returns the string of 3 letters at position i
	
	std::vector<int> getNum();				//returns the value at position i
	
	int ltn(char i);			//retunrs a number based on the input
	
	std::vector<int> makeIntVec();			//creates a giant vector
	
private:

	std::vector<int> nums;			//vector of how many of each respective string set

};


#endif 