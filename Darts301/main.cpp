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
	Game.CreateGame(player1, player2);
	std::cout << "Please enter how many games you'd like to simulate" << std::endl;
	std::cin >> sims;
	Game.Simulation(player1, player2, sims);
}