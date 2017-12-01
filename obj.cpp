
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "obj.h"

OBJ::OBJ(){
	nums = {};
	lets = {};
}

OBJ::OBJ(std::vector<std::string> letters, std::vector<std::string> numbers) {
	lets = letters;
	nums = numbers;
}

OBJ::OBJ(std::ifstream &infile) {
	std::string s = "";
	for (std::string line; std::getline(infile, line); ){
		s += line;
	}
	
}

std::string OBJ::getLine(int i){
	return lets[i];
}

int OBJ::getNum(int i){
	return nums[i];
}

OBJ OBJ::sortContent(OBJ inp){
	//just sorts the content. feel free to adapt it to a void. make sure to swap the respective nums as well.
}

void OBJ::add(std::string b){
	bool found = false;
	for(int i = 0;i < lets.size() - 1; i++){
		if(b == lets[i]){
			nums[i] += 1;
			found = true;
			break;
		}
	}
	if(found = false){
		lets.push_back(b);
		nums.push_back(1);
	}
}