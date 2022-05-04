#include "Dartboard.h"
#include <stdlib.h>

int Dartboard::Throw301(int p) {
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;
	int aim = rand() % 20 + 1;

	if (r <= p) {
		return aim;
	}
	else if (r <= p + p * .2f) {
		return 50;
	}
	else if (r <= p + p * .3f)
		return bd[0][aim];
	else if (r <= p + p * .4f) {
		return bd[1][aim];
	}
	else {
		return 0;
	}
}

int Dartboard::Throw501(int p) {
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;
	int aim = rand() % 20 + 1;

	if (r <= p) {
		return aim;
	}
	else if (r <= p + p * .2f) {
		return 50;
	}
	else if (r <= p + p * .3f) {
		return 25;
	}
	else if (r <= p + p * .4f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .7f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .8f) {
		return 2 * bd[0][aim];
	}
	else if (r <= p + p * .9f) {
		return 3 * bd[0][aim];
	}
	else {
		return 0;
	}
}

int throwDouble501(int p) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;
	int aim = rand() % 20 + 1;

	if (r < p)
		return 2 * aim;
	else if (r <= p + p * .2f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .3f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .4f) {
		return 3 * bd[1][aim];
	}
	else if (r <= p + p * .5f) {
		return 3 * bd[0][aim];
	}
	else if (r <= p + p * .6f) {
		return 2 * bd[1][aim];
	}
	else if (r <= p + p * .7f) {
		return 2 * bd[0][aim];
	}
	else if (r <= p + p * .8f) {
		return aim;
	}
	else {
		return 0;
	}
}
