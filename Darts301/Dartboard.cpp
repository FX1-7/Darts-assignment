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
		return bd[0][aim];
	}
	else if (r <= p + p * .3f)
		return bd[1][aim];
	else if (r <= p + p * .4f) {
		return 50;
	}
	else {
		return 0;
	}
}

int Dartboard::manualThrow301(int p, int aim) {
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	if (r <= p) {
		return aim;
	}
	else if (r <= p + p * .2f && aim != 50) {
		return bd[0][aim];
	}
	else if (r <= p + p * .3f && aim != 50) {
		return bd[1][aim];
	}
	else if (r <= p + p * .4f && aim != 50) {
		return 50;
	}
	else {
		return 0;
	}
}

int Dartboard::Throw501(int p, bool &doubleCheck) {
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;
	int aim = rand() % 20 + 1;

	if (r <= p) {
		return aim;
	}
	else if (r <= p + p * .2f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .3f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .4f) {
		return 50;
	}
	else if (r <= p + p * .7f) {
		return 25;
	}
	else if (r <= p + p * .8f) {
		doubleCheck = true;
		return 2 * aim;
	}
	else if (r <= p + p * .9f) {
		return 3 * aim;
	}
	else {
		return 0;
	}
}

int Dartboard::throwDouble501(int p, bool &doubleCheck) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;
	int aim = rand() % 20 + 1;

	if (r <= p){
		doubleCheck = true;
		return 2 * aim;
		}
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
		doubleCheck = true;
		return 2 * bd[1][aim];
	}
	else if (r <= p + p * .7f) {
		doubleCheck = true;
		return 2 * bd[0][aim];
	}
	else if (r <= p + p * .8f) {
		return aim;
	}
	else {
		return 0;
	}
}

int Dartboard::throwTreble501(int p, bool &doubleCheck) {
	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100;
	int aim = rand() % 20 + 1;

	if (r <= p)
		return 3 * aim;
	else if (r <= p + p * .2f) {
		return 3 * bd[0][aim];
	}
	else if (r <= p + p * .3f) {
		return 3 * bd[1][aim];
	}
	else if (r <= p + p * .4f) {
		return aim;
	}
	else if (r <= p + p * .5f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .6f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .7f) {
		return 25;
	}
	else if (r <= p + p * .8f) {
		return 50;
	}
	else {
		return 0;
	}
}

int Dartboard::manualThrow501(int p, int aim, bool& doubleCheck) {
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	if (r <= p) {
		return aim;
	}
	else if (r <= p + p * .2f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .3f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .4f) {
		return 50;
	}
	else if (r <= p + p * .7f) {
		return 25;
	}
	else if (r <= p + p * .8f) {
		doubleCheck = true;
		return 2 * aim;
	}
	else if (r <= p + p * .9f) {
		return 3 * aim;
	}
	else {
		return 0;
	}
}

int Dartboard::manualThrowTreble501(int p, int aim, bool& doubleCheck) {
	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100;

	if (r <= p)
		return 3 * aim;
	else if (r <= p + p * .2f) {
		return 3 * bd[0][aim];
	}
	else if (r <= p + p * .3f) {
		return 3 * bd[1][aim];
	}
	else if (r <= p + p * .4f) {
		return aim;
	}
	else if (r <= p + p * .5f) {
		return bd[0][aim];
	}
	else if (r <= p + p * .6f) {
		return bd[1][aim];
	}
	else if (r <= p + p * .7f) {
		return 25;
	}
	else if (r <= p + p * .8f) {
		return 50;
	}
	else {
		return 0;
	}
}

int Dartboard::manualThrowDouble501(int p, int aim, bool& doubleCheck) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;

	if (r <= p) {
		doubleCheck = true;
		return 2 * aim;
	}
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
		doubleCheck = true;
		return 2 * bd[1][aim];
	}
	else if (r <= p + p * .7f) {
		doubleCheck = true;
		return 2 * bd[0][aim];
	}
	else if (r <= p + p * .8f) {
		return aim;
	}
	else {
		return 0;
	}
}

int Dartboard::manualThrowBull501(int p) {
	int r = rand() % 100;

	if (r <= (p - p * .2f)) {
		return 50;
	}
	else if (r <= (p - p * .4f)) {
		return 25;
	}
	else {
		return rand() % 20 + 1;
	}
}