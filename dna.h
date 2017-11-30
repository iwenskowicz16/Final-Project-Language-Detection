#ifndef _dna_h
#define _dna_h

#include <iostream>
#include <string>
#include <vector>

class DNA {

public:

	DNA();

	DNA(std::vector<std::string> letters, std::vector<std::string> numbers);

	DNA(std::ifstream &infile);			//all of these above are basic object declarations

	std::string getLet(int i);				//returns the string of 3 letters at position i
	
	int getNum(int i);				//returns the value at position i
	
	DNA sortContent(DNA inp);			//self explanatory
	
	DNA add(std::string b);		//adds the string to the vector. incriments the respective vector if already present.

private:

	std::vector<int> nums;			//vector of how many of each respective string set
	
	std::vector<std::string> lets;		//vector of string sets

};


#endif