#include <vector>
#include <iostream>
#include <string>
#include "obj.h"
#include <fstream>

int main(int argc, char *argv[]){
	if(argc < 2){exit(EXIT_FAILURE);}			//checks to make sure there is only 1 input
	for(int i = 1; i <= argc; i++){
		std::string s = "";
		s += argv[i];
		s += ".txt"
		ifstream myFile(s);
		if(myFile.fail()){
			return 1;
		}
	}
	OBJ::OBJ inp = OBJ(toStr(argv[argc - 1]));
	int big = 0;
	int pos = 0;
	for(int i = 1; i < argc; i++){
		OBJ::OBJ comp = OBJ(toStr(argv[i]));
		int l = compare(inp.getNum(),comp.getNum());
		if(big < l){
			big = l;
			pos = i;
		}
	}
	std::cout << argv[big] << std::endl;		//prints the result
	return 0;
}

double compare(std::vector<int> a, std::vector<int> b){
	double *a, double *b, unsigned int len
    double idk = 0.0, da = 0.0, db = 0.0 ;
     for(unsigned int i = 0u; i < len; ++i) {
        idk += a[i] * b[i] ;
        da += a[i] * a[i] ;
        db += b[i] * b[i] ;
    }
    return idk / (sqrt(da) * sqrt(db)) ;
}

std::string toStr(std::string name){
	ifstream infile;
	infile.open(name);
	std::string s;
	std::getline(infile, s);
	infile.close();
	return s;
}