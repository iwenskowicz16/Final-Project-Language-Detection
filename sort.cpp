#include "dna.h"
#include "swap.h"
#include "sort.h"
#include <vector>


bool seqLenLessThan(DNA& item1, DNA& item2) {
	return item1.getSequence().length() < item2.getSequence().length();
}

bool headerLessThan(DNA& item1, DNA& item2) {
	return item1.getHeader() < item2.getHeader();
}

/*
Chooses a pivot (the first element in the vector v).
Partitions the vector v such that the elements that compare less than pivot
(based on the comparator function) are placed to the left of pivot, and the
remaining items (which are not less than pivot based on the comparator) are
placed to the right of pivot.

Returns the index of the pivot after partitioning.
*/
int partition(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	DNA pivot = v[start];
	int lh = start + 1;
	int rh = finish;
	/*
	invariant: everything to the left of lh is less than the pivot.
	and everything to the right of rh is not less than the pivot.
	*/
	while (true) {
		/*
		walk the lh to the right and rh to the left until we find
		a swappable pair of elements. Then, swap them.
		*/
		while (lh < rh && !comparator(v[rh], pivot)) rh--;
		while (lh < rh && comparator(v[lh], pivot)) lh++;
		if (lh == rh) break;
		swap(v, lh, rh);
	}
	/*
	cleanup: if the pivot still belongs at the beginning of the vector, return that position
	*/
	if (!comparator(v[lh], pivot)) return start;
	/*
	otherwise, we swap the pivot with the rightmost of the left-side elements, so it's
	in the 'middle.'
	And return the index of the pivot (which is lh).
	*/
	v[start] = v[lh];
	v[lh] = pivot;
	return lh;
}

void quicksort(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	if(start < finish){				//stops the program if the entire list has been looped
		int a = partition(v, comparator, start, finish);		//if v[start] isn't in the correct place, it finds what should be there
		if(a == start){				//moves on to the next one
			quicksort(v, comparator, start + 1, finish);		
		}
		else{						//Looks for things
			quicksort(v, comparator, start, finish);
		}
	}


}

std::vector<DNA> sort(std::vector<DNA> v, bool comparator(DNA&, DNA&)) {
	std::vector<DNA> vcopy = v;
	quicksort(vcopy, comparator, 0, vcopy.size() - 1);
	return vcopy;
}
