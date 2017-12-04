#include "obj.h"
#include "partone.h"
#include <vector>



std::vector<int> doProb(OBJ comparator){
	std::vector<int> toReturn = makeIntVec();
	std::vector<std::string> allCases = make19kVec();
	int a = 0;
	for(int i = 0; i < (int)(; i++){
		if(comparator.getLet(a) == allCases[i]){
			toReturn[i] = comparator.getNum(a);
			a++;
		}
	}
	return toReturn;
}