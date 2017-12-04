#include <vector>
#include <iostream>
#include <string>
#include "obj.h"
#include "partone.h"

int main(int argc, char *a[]){
	argc = argc + 1;
	OBJ::OBJ test = OBJ(a[1]);
	test.sortContent();
	std::vector<int> freq = doProb(test);
	for(int i = 0; i < 19682; i++){
		std::cout << freq[i] << " " << std::endl; 
	}
}