#include "Dartboard.h"
#include <stdlib.h>

int Dartboard::Throw(int p) {
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int bdwb[22] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,50 };
	int r = rand() % 100 + 1;
	int h = rand() % 20 + 1;

	if (h == 20) {
		int cf = rand() % 20 + 1;
		return bdwb[cf];
		}
	else {
		if (r <= p) {
			return h;
		}
		else if (r <= 92)
			return bd[0][h];
		else {
			return bd[1][h];
		}
	}
}
