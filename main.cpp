#include <vector>
#include <iostream>
#include <string>
#include "obj.h"

int main(int argc, char *argv[]){
	if(argc != 2){exit(EXIT_FAILURE);}
	std::string testString = argv[1];
	OBJ::OBJ test = OBJ(testString);
	std::vector<int> freq = test.getNum();
	for(int i = 0; i < 19683; i++){
		std::cout << freq[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
