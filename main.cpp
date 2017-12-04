#include <vector>
#include <iostream>
#include <string>
#include "obj.h"

int main(int argc, char *a[]){
	argc++;
	OBJ::OBJ test = OBJ(a[1]);
	std::vector<int> freq = test.getNum();
	for(int i = 0; i < 19682; i++){
		std::cout << freq[i] << " " << std::endl; 
	}
	return 0;
}
