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
	int PlayerChoice301;
	int GameChoice;
	Game.CreateGame(player1, player2);
	std::cout << "What game will " << player1.getName() << "and " << player2.getName() << " be playing?" << std::endl;
	std::cout << "1. Darts 301" << std::endl << "2. Darts 501" << std::endl;
	std::cin >> GameChoice;
	while (GameChoice != 1 && GameChoice != 2) {
		std::cout << "Please enter a value of 1 or 2." << std::endl;
		std::cin >> GameChoice;
	}
	if (GameChoice == 1) {
		std::cout << std::endl << "Darts 301 Selected!" << std::endl;
		std::cout << "Please enter how many games you'd like to simulate" << std::endl;
		std::cin >> sims;
		std::cout << "Please enter who is going first." << std::endl << "1. Player 1" << std::endl << "2. Player 2" << std::endl;
		std::cin >> PlayerChoice301;
		while (PlayerChoice301 != 1 && PlayerChoice301 != 2) {
			std::cout << "Please enter a value of 1 or 2." << std::endl;
			std::cin >> PlayerChoice301;
		}
		Game.Simulation301(player1, player2, sims, PlayerChoice301);
	}
	else if (GameChoice == 2) {
		std::cout << std::endl << "Darts 501 Selected!" << std::endl;
		std::cout << "Please enter how many games you'd like to simulate" << std::endl;
		std::cin >> sims;
		Game.Simulation501(player1, player2, sims);
	}
}