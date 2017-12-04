#include <vector>
#include <iostream>
#include <string>
#include "obj.h"

int main(int argc, char *a[]){
	if(argc > 2 or argc < 2){exit(EXIT_FAILURE);}
	OBJ::OBJ test = OBJ(a[1]);
	std::vector<int> freq = test.getNum();
	for(int i = 0; i < 19682; i++){
		std::cout << freq[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
