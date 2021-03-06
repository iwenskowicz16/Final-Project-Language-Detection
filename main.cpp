#include <vector>
#include <iostream>
#include <string>
#include "obj.h"

int main(int argc, char *argv[]){
	if(argc != 2){exit(EXIT_FAILURE);}			//checks to make sure there is only 1 input
	std::string testString = argv[1];
	OBJ::OBJ test = OBJ(testString);			//runs the functions
	std::vector<int> freq = test.getNum();		//extracts the result
	for(int i = 0; i < 19683; i++){
		std::cout << freq[i] << " ";	
	}										//prints the result
	std::cout << std::endl;
	return 0;
}
