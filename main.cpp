#include <vector>
#include <iostream>
#include <string>
#include "dna.h"
#include "swap.h"
#include "sort.h"

int main() {
	//std::vector<int> v = {1, 2, 3, 4, 5};
	//swap(v, 2, 3);
	//for (auto i: v) std::cout << i << ' '; std::cout << std::endl;
	//std::vector<std::string> w = {"one", "two", "three", "four", "five"};
	//swap(w, 1, 2);
	//for (auto i: w) std::cout << i << ' '; std::cout << std::endl;
	DNA::DNA l1;
	l1 = DNA("> eade","TTTTTT");
	
	DNA::DNA l2;
	l2 = DNA("> rder","CCCCCC");
	
	DNA::DNA l3;
	l3 = DNA("> meak","GGGGGG");
	
	DNA::DNA l4;
	l4 = DNA("> csse","AAAAAA");
	
	DNA::DNA l5;
	l5 = DNA("> beal","NNNNNN");
	
	DNA::DNA l6;
	l6 = DNA("> iles","NNNNNN");
	
	DNA::DNA l7;
	l7 = DNA("> fren","NNNNNN");
	
	DNA::DNA l8;
	l8 = DNA("> hhhh","NNNNNN");
	
	std::vector<DNA> v = {l1, l2, l3, l4, l5, l6, l7, l8};
	v = sort(v, headerLessThan);
	std::cout << "hhh" << std::endl;
	for(int i = 0; i < 8; i++){
		std::cout << v[i].getHeader() << std::endl;
	}
}