#include "Dartboard.h"
#include <stdlib.h>

int Dartboard::Throw301(int p) {
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for single score with accuracy passed in by player success rate

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	
	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;

	// Generate what they're aiming for (simulation mode)
	int aim = rand() % 20 + 1;

	// return aim if it's less than or equal to their accuracy
	if (r <= p) {
		return aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	//  return result of throwing for single score with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;

	// return aim if it's less than or equal to their accuracy
	if (r <= p) {
		return aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for single score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.


	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	
	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;
	// Generate what they're aiming for (simulation mode)
	int aim = rand() % 20 + 1;

	// return aim if r less than or equal to accuracy
	if (r <= p) {
		return aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// If a double is hit set to true.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for double score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.


	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;
	// Generate what they are aiming for (simulation mode)
	int aim = rand() % 20 + 1;

	if (r <= p){
		doubleCheck = true;
		return 2 * aim;
		}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for treble score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;
	// Generate what they are aiming for (Simulation mode)
	int aim = rand() % 20 + 1;

	if (r <= p) {
		return 3 * aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for single score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.


	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	// Generate a random number between 1 and 100
	int r = rand() % 100 + 1;

	// if r is less than or equal to accuracy then return aim
	if (r <= p) {
		return aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for treble score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	// Generate a random number between 1 and 100
	int r = rand() % 100;

	// If r is less than or equal to accuracy then return aim
	if (r <= p) {
		return 3 * aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for double score with accuracy passed in by player success rate
	// Double check is also passed in as 501 requires games to end on a double.


	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	// Generate a random number between 1 and 100
	int r = rand() % 100;

	// if r is less than or equal to accuracy then set doublecheck to true and return a double score of aim.
	if (r <= p) {
		doubleCheck = true;
		return 2 * aim;
	}
	// If not, then calculate higher accuracy range, I've used .fs to avoid using static numbers.
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
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	// Return result of throwing for bull with accuracy passed in by player success rate


	int r = rand() % 100;

	// If r <= accuracy + a number generated by .f (to avoid static numbers) this makes it slightly harder to hit a bull
	if (r <= (p - p * .2f)) {
		return 50;
	}
	// If it's a miss, calculate a higher accuracy range.
	else if (r <= (p - p * .4f)) {
		return 25;
	}
	// if not generate a random single to hit instead.
	else {
		return rand() % 20 + 1;
	}
}