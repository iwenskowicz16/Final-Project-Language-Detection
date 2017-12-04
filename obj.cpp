
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "obj.h"

//OBJ::OBJ(){
//	nums = {};
//	lets = {};
//}

//OBJ::OBJ(std::vector<std::string> letters, std::vector<std::string> numbers){
//	lets = letters;
//	nums = numbers;
//}

OBJ::OBJ(std::string s){
	nums = {};
	lets = {};
	for(int offset = 0; offset < 3; offset++){
		for(int i = offset; i < (int)(s.size()) - 2; i += 3){
			std::string h = "";
			h += s[i];
			h += s[i+1];
			h += s[i+2];
			bool found = false;
			for(int b = 0;b < (int)(lets.size()) - 1; b++){
				if(h == lets[b]){
					nums[b] += 1;
					found = true;
					break;
				}
			}
			if(found == false){
				lets.push_back(h);
				nums.push_back(1);
			}
		}
	}
}

//std::string OBJ::getLine(int i){
//	return lets[i];
//}

int OBJ::getNum(int i){
	return nums[i];
}

bool compare(std::string string1, std::string string2){
	if (string1[0] < string2[0]) {return true;}
	else if(string1[0] == string2[0] and string1[1] < string2[1]) {return true;}
	else if(string1[0] == string2[0] and string1[1] == string2[1] and string1[2] < string2[2]) {return true;}
	else {return false;}
}

template <typename T> void swap(std::vector<T> &v, size_t i, size_t j) {
	T temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(std::vector<std::string>& letters, std::vector<int>& numbers,int low,int high, bool comparator(std::string&, std::string&)){
	std::string pivot = letters[high];
	int i = low -1;
	for(int j = low; j < high; j++){
		if(comparator(letters[j], pivot)){
			i++;
			swap(letters, i, j);
			swap(numbers, i, j);
		}
	}
	if(letters[high] < letters[i +1]){
		swap(letters, i+1, high);
	}
	return i + 1;
}

void quicksort(std::vector<std::string>& letters, std::vector<int>& numbers,int low,int high, bool comparator(std::string&, std::string&)){
	if(low < high){
		int p = partition(letters, numbers, low, high, comparator);
		quicksort(letters, numbers, low, p-1, comparator);
		quicksort(letters, numbers, p+1, high, comparator);
	}
}

void OBJ::sortContent(){
	int length = lets.size() -1;
	quicksort(lets, nums, 0, length, compare);
}
