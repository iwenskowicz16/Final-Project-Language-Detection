#ifndef _dna_h
#define _dna_h

#include <iostream>
#include <string>
#include <vector>

/*
A class to represent DNA sequences, related to the FASTA format.
A DNA object has two member fields: a header, which is a sequence of characters beginning with the `>` character,
and a sequence, which is a sequence of characters containing only A, C, T, G, and N.
*/

class DNA {

public:

	DNA();

	DNA(std::vector<std::string> letters, std::vector<std::string> numbers);

	DNA(std::ifstream &infile);

	std::string getLet();
	
	int getNum();
	
	DNA sortContent(DNA inp);
	
	DNA add(int a, std::string b);

private:

	std::vector<int> nums;
	
	std::vector<std::string> lets;

};


#endif