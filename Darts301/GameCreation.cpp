#include "GameCreation.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Dartboard.h"

void GameCreation::CreateGame(Player& player1, Player& player2) {
	std::string TempName;
	int TempSuccess;
	std::cout << "Please Enter Player 1's name:" << std::endl;
	std::cin >> TempName;
	std::cout << std::endl;
	std::cout << "Please enter " << TempName << "'s success rate in hitting their target: " << std::endl;
	std::cin >> TempSuccess;
	std::cout << std::endl;
	player1.setName(TempName);
	player1.setSuccessRate(TempSuccess);
	std::cout << "Please enter Player 2's name:" << std::endl;
	std::cin >> TempName;
	std::cout << std::endl;
	std::cout << "Please enter " << TempName << "'s success rate in hitting their target: " << std::endl;
	std::cin >> TempSuccess;
	std::cout << std::endl;
	player2.setName(TempName);
	player2.setSuccessRate(TempSuccess);

}

void GameCreation::Simulation(Player& player1, Player& player2, int sims) {
	int TempTarget;
	int FinalHit;
	Dartboard Throws;
	do {
		do {
			std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
			std::cout << "Please enter what " << player1.getName() << " is throwing at: " << std::endl;
			std::cin >> TempTarget;
			while (TempTarget > 20 && TempTarget != 25) {
				std::cout << "Please enter a value 20 or less, or 25 if you wish to aim for the bull!" << std::endl;
				std::cin >> TempTarget;
			}
			FinalHit = Throws.throw_single(TempTarget, player1.getSuccessRate());
			if (FinalHit == 25) {
				std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
				player1.setScore(player1.getScore() - FinalHit);
				std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
				player1.setTurns(player1.getTurns() + 1);
			}
			else {
				std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
				player1.setScore(player1.getScore() - FinalHit);
				std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
				player1.setTurns(player1.getTurns() + 1);
			}
			std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
			std::cout << "Please enter what " << player2.getName() << " is throwing at: " << std::endl;
			std::cin >> TempTarget;
			while (TempTarget > 20 && TempTarget != 25) {
				std::cout << "Please enter a value 20 or less, or 25 if you wish to aim for the bull!" << std::endl;
				std::cin >> TempTarget;
			}
			FinalHit = Throws.throw_single(TempTarget, player2.getSuccessRate());
			if (FinalHit == 25) {
				std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
				player2.setScore(player2.getScore() - FinalHit);
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player2.getTurns() + 1);
			}
			else {
				std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
				player2.setScore(player2.getScore() - FinalHit);
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player2.getTurns() + 1);
			}
		} while (player1.getScore() > 0 && player2.getScore() > 0);
		if (player1.getScore() == 0) {
			std::cout << player1.getName() << "Has won the game! They won in " << player1.getTurns() << " turns!" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		else {
			std::cout << player2.getName() << "Has won the game! They won in " << player2.getTurns() << " turns!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		player1.setScore(301);
		player2.setScore(301);
		sims = sims - 1;
	} while (sims > 0);
}