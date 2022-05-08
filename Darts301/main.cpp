#include <iostream>
#include <string>
#include "Player.h"
#include "GameCreation.h"


int main() {
	// Create player and game objects.
	Player player1;
	Player player2;
	GameCreation Game;
	// Declare variables needed for the menu.
	int sims;
	int PlayerChoice301;
	int GameChoice;
	int SimOrManual;
	// Create a game, passing player1 and 2 in as references.
	Game.CreateGame(player1, player2);
	// Find out details about the game they will be playing
	std::cout << "What game will " << player1.getName() << " and " << player2.getName() << " be playing?" << std::endl;
	std::cout << "1. Darts 301" << std::endl << "2. Darts 501" << std::endl;
	std::cin >> GameChoice;
	// Error checking to make sure the user inputs values we expect.
	while (GameChoice != 1 && GameChoice != 2) {
		std::cout << "Please enter a value of 1 or 2." << std::endl;
		std::cin >> GameChoice;
	}
	// Check what game they chose.
	if (GameChoice == 1) {
		std::cout << std::endl << "Darts 301 Selected!" << std::endl;
		player1.setScore(301);
		player2.setScore(301);
		std::cout << "Please enter who is going first." << std::endl << "1. Player 1" << std::endl << "2. Player 2" << std::endl;
		std::cin >> PlayerChoice301;
		while (PlayerChoice301 != 1 && PlayerChoice301 != 2) {
			std::cout << "Please enter a value of 1 or 2." << std::endl;
			std::cin >> PlayerChoice301;
		}
		// Ask if they want to play it manually or simulate the game
		std::cout << "If this game is going to be simulated please enter 1, if it is going to be manual please press 2." << std::endl;
		std::cin >> SimOrManual;
		// Error handling, request specific values.
		while (SimOrManual != 1 && SimOrManual != 2) {
			std::cout << "Please enter a value of 1 or 2." << std::endl;
			std::cin >> SimOrManual;
		}
		// Check and execute their choice.
		if (SimOrManual == 1) {
			std::cout << "Please enter how many games you'd like to simulate" << std::endl;
			std::cin >> sims;
			Game.Simulation301(player1, player2, sims, PlayerChoice301);
		}
		else if (SimOrManual == 2) {
			std::cout << "How many games would you like to play?" << std::endl;
			std::cin >> sims;
			Game.Manual301(player1, player2, sims, PlayerChoice301);
		}
	}
	// They chose 501 instead.
	else if (GameChoice == 2) {
		// Ask if they want to play it manually or simulate it.
		std::cout << std::endl << "Darts 501 Selected!" << std::endl;
		std::cout << "If this game is going to be simulated please enter 1, if it is going to be manual please press 2." << std::endl;
		player1.setScore(301);
		player2.setScore(301);
		std::cin >> SimOrManual;
		// Error handling, request specific values.
		while (SimOrManual != 1 && SimOrManual != 2) {
			std::cout << "Please enter a value of 1 or 2." << std::endl;
			std::cin >> SimOrManual;
		}
		// Check and execute their choice.
		if (SimOrManual == 1) {
			std::cout << "Please enter how many games you'd like to simulate" << std::endl;
			std::cin >> sims;
			Game.Simulation501(player1, player2, sims);
		}
		else if (SimOrManual == 2) {
			std::cout << "Please enter how many games you'd like to play" << std::endl;
			std::cin >> sims;
			Game.Manual501(player1, player2, sims);
		}
	}
}