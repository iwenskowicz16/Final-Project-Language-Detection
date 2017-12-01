#include "obj.h"
#include "partone.h"
#include <vector>

std::vector<int> partone::makeIntVec(){
	std::vector<int> h = {};
	for(int i = 0; i < 19682; i++){
		h.push_back(0);
	}
	return h;
}

std::vector<std::string> partone::make19kVec(){
	std::vector<std::string> h = {};
	std::string e = "hhh";
	for(int i = 0; i < 26; i++){
		e.replace(0,1,ntl(i));
		for(int i = 0; i < 26; i++){
			e.replace(1,1,ntl(i));
			for(int i = 0; i < 26; i++){
				e.replace(2,1,ntl(i));
				h.push_back(e);
			}
		}
	}
}

std::string ntl(int i){
	if(i = 0){
		return "a";
	}
	else if(i = 1){
		return "b";
	}
	else if(i = 2){
		return "c";
	}
	else if(i = 3){
		return "d";
	}
	else if(i = 4){
		return "e";
	}
	else if(i = 5){
		return "f";
	}
	else if(i = 6){
		return "g";
	}
	else if(i = 7){
		return "h";
	}
	else if(i = 8){
		return "i";
	}
	else if(i = 9){
		return "j";
	}
	else if(i = 10){
		return "k";
	}
	else if(i = 11){
		return "l";
	}
	else if(i = 12){
		return "m";
	}
	else if(i = 13){
		return "n";
	}
	else if(i = 14){
		return "o";
	}
	else if(i = 15){
		return "p";
	}
	else if(i = 16){
		return "q";
	}
	else if(i = 17){
		return "r";
	}
	else if(i = 18){
		return "s";
	}
	else if(i = 19){
		return "t";
	}
	else if(i = 20){
		return "u";
	}
	else if(i = 21){
		return "v";
	}
	else if(i = 22){
		return "w";
	}
	else if(i = 23){
		return "x";
	}
	else if(i = 24){	
		return "y";
	}
	else if(i = 25){
		return "z";
	}
	else if(i = 26){
		return " ";
	}
}

std::vector<int> doProb(OBJ comparator){
	std::vector<int> toReturn = makeIntVec();
	std::vector<std::string> allCases = make19kVec();
	int a = 0;
	for(int i = 0; i < 19682; i++){
		if(comparator.getLet(a) == allCases[i]){
			toReturn[i] = comparator.getNum(a);
			a++;
		}
	}
	return toReturn;
}