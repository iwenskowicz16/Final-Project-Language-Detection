
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
			nums[h] += 1;
			}
		}
	}
}


std::vector<int> OBJ::getNum(){
	return nums;
}

std::string OBJ::ntl(int i){
	if(i == 0){
		return " ";
	}
	else if(i == 1){
		return "a";
	}
	else if(i == 2){
		return "b";
	}
	else if(i == 3){
		return "c";
	}
	else if(i == 4){
		return "d";
	}
	else if(i == 5){
		return "e";
	}
	else if(i == 6){
		return "f";
	}
	else if(i == 7){
		return "g";
	}
	else if(i == 8){
		return "h";
	}
	else if(i == 9){
		return "i";
	}
	else if(i == 10){
		return "j";
	}
	else if(i == 11){
		return "k";
	}
	else if(i == 12){
		return "l";
	}
	else if(i == 13){
		return "m";
	}
	else if(i == 14){
		return "n";
	}
	else if(i == 15){
		return "o";
	}
	else if(i == 16){
		return "p";
	}
	else if(i == 17){
		return "q";
	}
	else if(i == 18){
		return "r";
	}
	else if(i == 19){
		return "s";
	}
	else if(i == 20){
		return "t";
	}
	else if(i == 21){
		return "u";
	}
	else if(i == 22){
		return "v";
	}
	else if(i == 23){
		return "w";
	}
	else if(i == 24){	
		return "x";
	}
	else if(i == 25){
		return "y";
	}
	else{
		return "z";
	}
}	
	
std::string OBJ::ltn(std::string i){
	if(i == " "){
		return 0;
	}
	else if(i == "a"){
		return 1;
	}
	else if(i == "b"){
		return 2;
	}
	else if(i == "c"){
		return 3;
	}
	else if(i == "d"){
		return 4;
	}
	else if(i == "e"){
		return 5;
	}
	else if(i == "f"){
		return 6;
	}
	else if(i == "g"){
		return 7;
	}
	else if(i == "h"){
		return 8;
	}
	else if(i == "i"){
		return 9;
	}
	else if(i == "j"){
		return 10;
	}
	else if(i == "k"){
		return 11;
	}
	else if(i == "l"){
		return 12;
	}
	else if(i == "m"){
		return 13;
	}
	else if(i == "n"){
		return 14;
	}
	else if(i == "o"){
		return 15;
	}
	else if(i == "p"){
		return 16;
	}
	else if(i == "q"){
		return 17;
	}
	else if(i == "r"){
		return 18;
	}
	else if(i == "s"){
		return 19;
	}
	else if(i == "t"){
		return 20;
	}
	else if(i == "u"){
		return 21;
	}
	else if(i == "v"){
		return 22;
	}
	else if(i == "w"){
		return 23;
	}
	else if(i == "x"){	
		return 24;
	}
	else if(i == "y"){
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