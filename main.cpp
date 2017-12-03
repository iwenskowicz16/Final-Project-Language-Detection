#include <vector>
#include <iostream>
#include <string>
#include "obj.h"
#include "partone.h"

int main(int argc, std::string a){
	OBJ::OBJ test;
	test.add(a);
	test.sortContent();
	std::vector<int> freq = doProb(test);
	for(int i = 0; i < 19682; i++){
		std::cout << freq[i] << " " << std::endl; 
	}