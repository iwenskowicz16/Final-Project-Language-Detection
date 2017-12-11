#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "obj.h"

int main(int argc, char *argv[]){
	if(argc < 2){exit(EXIT_FAILURE);}			//checks to make sure there is only 1 input
	for(int i = 1; i <= argc; i++){
		ifstream myFile(argv[i]);
		if(myFile.fail()){
			return 1;
		}
	}
	OBJ::OBJ inp = OBJ(toStr(argv[argc - 1]));
	long big = 0;
	int pos = 1;
	for(int i = 1; i < argc - 1; i++){
		OBJ::OBJ comp = OBJ(toStr(argv[i]));
		long h = compare(inp.getNum(),comp.getNum());
		if(big < h){
			big = h;
			pos = i;
		}
	}
	std::cout << argv[pos] << std::endl;		//prints the result
	return 0;
}

long compare(std::vector<int> a, std::vector<int> b){
	unsigned long top = 0.0;
	for(int i = 0; i < (int)length(a) - 1; i++){
		top += (a[i] * b[i]);
	}
	unsigned long a2 = 0.0;
	for(int i = 0; i < (int)length(a) - 1; i++){
		a2 += (a[i] * a[i]);
	}
	unsigned long b2 = 0.0;
	for(int i = 0; i < (int)length(b) - 1; i++){
		b2 += (b[i] * b[i]);
	}
	return (top/(a2*b2));
}

std::string toStr(std::string name){
	ifstream infile;
	infile.open(name);
	std::string s;
	std::getline(infile, s);
	infile.close();
	return s;
}