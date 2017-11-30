/*
Implementation for the DNA class
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "dna.h"

/*
Implements the standard genetic code.
Given a string representing a valid DNA sequence, return the appropriate amino acid sequence.
This assumes the reading frame starts with character 0 of the string,
and is in the forward direction.
If a STOP codon is encountered, return only the translated sequence up to that point.
*/
std::string trans(std::string seq) {
	std::string result;
	for (int i = 0; i < (int) seq.length() - 2; i+=3) {
		std::string codon = seq.substr(i,3);
		if (codon == "TTT" || codon == "TTC") result += 'F';
		if (codon == "TTA" || codon == "TTG" || codon.substr(0,2) == "CT") result += 'L';
		if (codon == "ATT" || codon == "ATA" || codon == "ATA") result += 'I';
		if (codon == "ATG") result += 'M';
		if (codon.substr(0,2) == "GT") result += 'V';
		if (codon.substr(0,2) == "TC") result += 'S';
		if (codon.substr(0,2) == "CC") result += 'P';
		if (codon.substr(0,2) == "AC") result += 'T';
		if (codon.substr(0,2) == "GC") result += 'A';
		if (codon == "TAT" || codon == "TAC") result += 'Y';
		if (codon == "CAT" || codon == "CAC") result += 'H';
		if (codon == "CAA" || codon == "CAG") result += 'Q';
		if (codon == "AAT" || codon == "AAC") result += 'N';
		if (codon == "AAA" || codon == "AAG") result += 'K';
		if (codon == "GAT" || codon == "GAC") result += 'D';
		if (codon == "GAA" || codon == "GAG") result += 'E';
		if (codon == "TGT" || codon == "TGC") result += 'C';
		if (codon == "TGG") result += 'W';
		if (codon == "AGA" || codon == "AGG" || codon.substr(0,2) == "CG") result += 'R';
		if (codon == "AGT" || codon == "AGC") result += 'S';
		if (codon.substr(0,2) == "GG") result += 'G';
		if (codon == "TAA" || codon == "TAG" || codon == "TGA") return result;
	}
	return result;
}

/*

		CGT, CGC, CGA, CGG, AGA, AGG : R (Argenine)
		AGT, AGC : S (Serine)
		GGT, GGC, GGA, GGG : G (Glycine)

		TAA, TAG, TGA : STOP
*/

std::string rc(std::string seq) {
	std::string result = "";
	/*
	iterate backwards through the string
	so the result is in the proper order
	*/
	for (int i=seq.length()-1; i >= 0; i--) {
		switch (seq[i]) {
			case 'A': result += 'T'; break;
			case 'T': result += 'A'; break;
			case 'C': result += 'G'; break;
			case 'G': result += 'C'; break;
			case 'N': result += 'N'; break;
		}
	}
	return result;
}

bool validseq(std::string seq) {
	for (int i=0; i < (int)seq.length(); i++) {
		switch (seq[i]) {
			case 'A' : break;
			case 'C' : break;
			case 'T' : break;
			case 'G' : break;
			case 'N' : break;
			default : return false;
		}
	}
	return true;
}

bool validhdr(std::string hdr) {
	if (hdr.length() > 0 && hdr[0] == '>')
		return true;
	else return false;
}

DNA::DNA() {
	seq = "";
	hdr = ">";
}

DNA::DNA(std::string header, std::string sequence) {
	seq = sequence;
	hdr = header;
	if (! validseq(seq)) throw std::runtime_error("Invalid sequence");
	if (! validhdr(hdr)) throw std::runtime_error("Invalid header, must start with '>'");
}

DNA::DNA(std::ifstream &infile) {
	bool header_found = false;
	for (std::string line; std::getline(infile, line); ) {
		if (! header_found && line[0] == '>') {
			header_found = true;
			hdr = line;
		} else {
			seq += line;
		}
	}
	if (! validseq(seq)) throw std::runtime_error("Invalid sequence");
	if (! validhdr(hdr)) throw std::runtime_error("Invalid header, must start with '>'");
}



std::string DNA::getSequence() {
	return seq;
}

std::string DNA::getHeader() {
	return hdr;
}



std::string DNA::toFasta(int columns) {
	std::string result = hdr + "\n";
	int i = 0;
	while (i < (int)seq.length()) {
		if (i + columns < (int)seq.length()) {
			result += seq.substr(i, columns) + "\n";
			i += columns;
		} else {
			result += seq.substr(i) + "\n";
			break;
		}

	}

	return result;
}

DNA DNA::revcomp() {
	std::string result = rc(seq);
	return DNA(hdr, result);
}

size_t DNA::find(std::string query, size_t start) {
	std::string rq = DNA::DNA(">", query).revcomp().getSequence();
	size_t fwd = seq.find(query, start);
	size_t bck = seq.find(rq, start);
	if (fwd != std::string::npos && bck == std::string::npos) return fwd;
	if (bck != std::string::npos && fwd == std::string::npos) return bck;
	return (fwd < bck) ? fwd : bck;

}

std::vector<std::string> DNA::translate() {
	std::vector<std::string> results;
	std::string rev = rc(seq);
	for (int offset = 0; offset <= 2; offset++) {
		
		int seqlen = seq.length();
		// largest multiple of 3 <= (seqlen - offset)
		std::string fwdframe = seq.substr(offset, (seqlen - offset) / 3 * 3);
		std::string revframe = rev.substr(offset, (seqlen - offset) / 3 * 3);
		// for (int i = 0; i < (int) seq.length() - 2; i++) {
		// 	// not correct yet.
		// 	aa += trans(fwdframe.substr(i,3));
		// 	raa += trans(rev.substr(i,3));
		// }
		std::string aas = trans(fwdframe);
		std::string raas = trans(revframe);
		results.push_back(aas);
		results.push_back(raas);
	}
	return results;
}

bool operator==(DNA d1, DNA d2) {
	return d1.seq == d2.seq;
}
