#include <iostream>
#include <string>
#include <chrono>
#include "Player.h"
#include "GameCreation.h"

// Make it a little neater when needing delays
#define Sleep5Sec std::this_thread::sleep_for(std::chrono::milliseconds(5000))
#define Sleep2Sec std::this_thread::sleep_for(std::chrono::milliseconds(2000))

int main() {

	// Start tracking the time since the program was run.
	auto start = std::chrono::system_clock::now();
	Player player1;
	Player player2;
	GameCreation Game;
	int sims;
	int TempMenuVar;
	Game.CreateGame(player1, player2);
	std::cout << "Please enter how many games you'd like to simulate" << std::endl;
	std::cin >> sims;
	std::cout << "Please enter who is going first." << std::endl << "1. Player 1" << std::endl << "2. Player 2" << std::endl;
	std::cin >> TempMenuVar;
	do {
		if (TempMenuVar == 1) {
			Game.Simulation301P1(player1, player2, sims);
		}
		else if (TempMenuVar == 2) {
			Game.Simulation301P2(player1, player2, sims);
		}
	} while (TempMenuVar != 1 || TempMenuVar != 2);
}