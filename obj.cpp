
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "obj.h"

OBJ::OBJ(){
	nums = {};
	lets = {};
}

OBJ::OBJ(std::vector<std::string> letters, std::vector<std::string> numbers) {
	lets = letters;
	nums = numbers;
}

OBJ::OBJ(std::ifstream &infile) {
	std::string s = "";
	for (std::string line; std::getline(infile, line); ){
		s += line;
	}
	
}

std::string OBJ::getLine(int i){
	return lets[i];
}

int OBJ::getNum(int i){
	return nums[i];
}

//Comparison to see if one trigram goes before another
bool comparator(std::string string1, std::string string2){
	if(string1[0] < string2[0]) {return true;}
	else if(string1[0] == string2[0] and string1[1] < string2[1]) {return true;}
	else if(string1[0] == string2[0] and string1[1] == string2[1] and string1[2] < string2[2]) {return true;}
	else {return false;}
}

template <typename T> void swap(std::vector<T> &v, size_t i, size_t j) {
	T temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(std::vector<std::string>& letters, std::vector<std::string>& numbers, low, high, bool comparator(std::string&, std::string&){
	std:string pivot = letters[high];
	int i = low -1;
	for(int j = low; j++; j < high){
		if(comparator(letters[j], pivot)){
			i++;
			swap(letters, i, j);
			swap(numbers, i, j);
		}
	}
	if(letters[high] < letters[i +1]){
		swap(letters, i+1, high);
	}
	return i +1
}

//void quicksort

OBJ OBJ::sortContent(OBJ inp){
	//just sorts the content. feel free to adapt it to a void. make sure to swap the respective nums as well.
	std::vector<std:: string> sortLetters;
	std::vector<std:: string> sortNums;
	
}

void OBJ::add(std::string b){
	bool found = false;
	for(int i = 0;i < lets.size() - 1; i++){
		if(b == lets[i]){
			nums[i] += 1;
			found = true;
			break;
		}
	}
	if(found = false){
		lets.push_back(b);
		nums.push_back(1);
	}
}