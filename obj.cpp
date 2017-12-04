
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "obj.h"


OBJ::OBJ(std::string s){
	nums = makeIntVec();
	for(int offset = 0; offset < 3; offset++){
		for(int i = offset; i < (int)(s.size()) - 2; i += 3){
			int h = 0;
			h += ltn(s[i]) * 27 * 27;
			h += ltn(s[i+1]) * 27;
			h += ltn(s[i+2]);
			nums[h] ++;
		}
	}
}

std::vector<int> OBJ::getNum(){
	return nums;
}

int OBJ::ltn(char i){
	if(i == ' '){
		return 0;
	}
	else if(i == 'a'){
		return 1;
	}
	else if(i == 'b'){
		return 2;
	}
	else if(i == 'c'){
		return 3;
	}
	else if(i == 'd'){
		return 4;
	}
	else if(i == 'e'){
		return 5;
	}
	else if(i == 'f'){
		return 6;
	}
	else if(i == 'g'){
		return 7;
	}
	else if(i == 'h'){
		return 8;
	}
	else if(i == 'i'){
		return 9;
	}
	else if(i == 'j'){
		return 10;
	}
	else if(i == 'k'){
		return 11;
	}
	else if(i == 'l'){
		return 12;
	}
	else if(i == 'm'){
		return 13;
	}
	else if(i == 'n'){
		return 14;
	}
	else if(i == 'o'){
		return 15;
	}
	else if(i == 'p'){
		return 16;
	}
	else if(i == 'q'){
		return 17;
	}
	else if(i == 'r'){
		return 18;
	}
	else if(i == 's'){
		return 19;
	}
	else if(i == 't'){
		return 20;
	}
	else if(i == 'u'){
		return 21;
	}
	else if(i == 'v'){
		return 22;
	}
	else if(i == 'w'){
		return 23;
	}
	else if(i == 'x'){	
		return 24;
	}
	else if(i == 'y'){
		return 25;
	}
	else{
		return 26;
	}
}	

std::vector<int> OBJ::makeIntVec(){
	std::vector<int> h = {};
	for(int i = 0; i < 19682; i++){
		h.push_back(0);
	}
	return h;
}