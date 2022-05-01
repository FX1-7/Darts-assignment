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

void GameCreation::Simulation301P1(Player& player1, Player& player2, int sims) {
	int FinalHit;
	Dartboard Throws;
	do {
		do {
			std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
			FinalHit = Throws.Throw(player1.getSuccessRate());
			if (player1.getScore() == 50) {
				if (FinalHit != 50) {
					std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				else if (FinalHit == 50) {
					if (player1.getScore() < 100 && player1.getScore() != 50) {
						std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					else {
						std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
						player1.setScore(player1.getScore() - FinalHit);
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
				}
				else {
					std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
					player1.setTurns(player1.getTurns() + 1);
					player1.setScore(player1.getScore() - FinalHit);
				}
			}
			else if (player1.getScore() - FinalHit < 50) {
				std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
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
			FinalHit = Throws.Throw(player2.getSuccessRate());
			if (player2.getScore() == 50) {
				if (FinalHit != 50) {
					std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				else if (FinalHit == 50) {
					if (player2.getScore() < 100 && player2.getScore() != 50) {
						std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					}
					else {
						std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
						player2.setScore(player2.getScore() - FinalHit);
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
				}
				else {
					std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
					player2.setTurns(player2.getTurns() + 1);
					player2.setScore(player2.getScore() - FinalHit);
				}
			}
			else if (player2.getScore() - FinalHit < 50) {
				std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player1.getTurns() + 1);
			}
			else {
				std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
				player2.setScore(player2.getScore() - FinalHit);
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player2.getTurns() + 1);
			}
		} while (player1.getScore() > 0 && player2.getScore() > 0);
		if (player1.getScore() == 0) {
			std::cout << player1.getName() << " has won the game! They won in " << player1.getTurns() << " turns!" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		else {
			std::cout << player2.getName() << " has won the game! They won in " << player2.getTurns() << " turns!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		player1.setScore(301);
		player2.setScore(301);
		sims = sims - 1;
	} while (sims > 0);
}

void GameCreation::Simulation301P2(Player& player1, Player& player2, int sims) {
	int FinalHit;
	Dartboard Throws;
	do {
		do {
			std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
			FinalHit = Throws.Throw(player2.getSuccessRate());
			if (player2.getScore() == 50) {
				if (FinalHit != 50) {
					std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				else if (FinalHit == 50) {
					if (player2.getScore() < 100 && player2.getScore() != 50) {
						std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					else {
						std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
						player2.setScore(player2.getScore() - FinalHit);
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
				}
				else {
					std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
					player2.setTurns(player2.getTurns() + 1);
					player2.setScore(player2.getScore() - FinalHit);
				}
			}
			else if (player2.getScore() - FinalHit < 50) {
				std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player2.getTurns() + 1);
			}
			else {
				std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
				player2.setScore(player2.getScore() - FinalHit);
				std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
				player2.setTurns(player2.getTurns() + 1);
			}
			std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
			FinalHit = Throws.Throw(player1.getSuccessRate());
			if (player1.getScore() == 50) {
				if (FinalHit != 50) {
					std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				else if (FinalHit == 50) {
					if (player1.getScore() < 100 && player1.getScore() != 50) {
						std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					}
					else {
						std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
						player1.setScore(player1.getScore() - FinalHit);
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
				}
				else {
					std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
					player1.setTurns(player1.getTurns() + 1);
					player1.setScore(player1.getScore() - FinalHit);
				}
			}
			else if (player1.getScore() - FinalHit < 50) {
				std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
				std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
				player1.setTurns(player1.getTurns() + 1);
			}
			else {
				std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
				player2.setScore(player1.getScore() - FinalHit);
				std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
				player1.setTurns(player1.getTurns() + 1);
			}
		} while (player1.getScore() > 0 && player2.getScore() > 0);
		if (player1.getScore() == 0) {
			std::cout << player1.getName() << " has won the game! They won in " << player1.getTurns() << " turns!" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		else {
			std::cout << player2.getName() << " has won the game! They won in " << player2.getTurns() << " turns!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		player1.setScore(301);
		player2.setScore(301);
		sims = sims - 1;
	} while (sims > 0);
}