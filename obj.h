#ifndef _obj_h
#define _obj_h

#include <iostream>
#include <string>
#include <vector>

class OBJ {

public:

	//OBJ();

	//OBJ(std::vector<std::string> letters, std::vector<std::string> numbers);

	OBJ(std::string s);			//all of these above are basic object declarations

	std::string getLet(int i);				//returns the string of 3 letters at position i
	
	std::vector<int> getNum(int i);				//returns the value at position i
	
	int OBJ::ltn(std::string i);
	
	std::string OBJ::ntl(int i);
	
	std::vector<int> OBJ::makeIntVec();
	
private:

	std::vector<int> nums;			//vector of how many of each respective string set

};


#endif 