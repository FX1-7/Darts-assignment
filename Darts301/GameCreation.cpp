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

void GameCreation::Simulation301(Player& player1, Player& player2, int sims, int choice) {
	int FinalHit;
	Dartboard Throws;
	do {
		do {
			if (choice == 1) {
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				FinalHit = Throws.Throw301(player1.getSuccessRate());
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					if (FinalHit != 50 && FinalHit != 0) {
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					else if (FinalHit == 50) {
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
						else if (player1.getScore() != 0) {
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
				}
				if (FinalHit == 0) {
					std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				else if (player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player1.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				FinalHit = Throws.Throw301(player2.getSuccessRate());
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					if (FinalHit != 50 && FinalHit != 0) {
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					else if (FinalHit == 50) {
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						}
						else if (player2.getScore() != 0) {
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
				}
				if (FinalHit == 0) {
					std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player1.getTurns() + 1);
				}
				else if (player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
			}
			else {
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				FinalHit = Throws.Throw301(player2.getSuccessRate());
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					if (FinalHit != 50) {
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					else if (FinalHit == 50 && FinalHit != 0) {
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
						else if (player2.getScore() != 0) {
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
					if (FinalHit == 0) {
						std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
				}
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				else if (player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				FinalHit = Throws.Throw301(player1.getSuccessRate());
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					if (FinalHit != 50 && FinalHit != 0) {
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					else if (FinalHit == 50) {
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						}
						else if (player1.getScore() != 0) {
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
					if (FinalHit == 0) {
						std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
				}
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				else if (player1.getScore() !=0) {
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
			}
		} while (player1.getScore() > 0 || player2.getScore() > 0);
		if (player1.getTurns() > player2.getTurns()) {
			std::cout << player2.getName() << " has won the game!" << std::endl;
			std::cout << player1.getName() << " has lost!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		else {
			std::cout << player1.getName() << " has won the game!" << std::endl;
			std::cout << player2.getName() << " has lost" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		float GamesPlayed = player1.getWins() + player2.getWins();
		player1.setWinRate(player1.getWins() / GamesPlayed);
		player2.setWinRate(player2.getWins() / GamesPlayed);
		std::cout << player1.getName() << " has an average winrate of: " << player1.getWinRate() << " they had: " << player1.getTurns() << " turns across this simulation." << std::endl;
		std::cout << player2.getName() << " has an average winrate of: " << player2.getWinRate() << " they had: " << player2.getTurns() << " turns across this simulation." << std::endl;
		player1.setScore(301);
		player2.setScore(301);
		sims = sims - 1;
	} while (sims > 0);
}

void GameCreation::Simulation501(Player& player1, Player& player2, int sims) {
	Dartboard Throw; // single throw.
	int FinalHit; // Final hit variable to get what the users hit.
	// Match loop start
	do {
			// Set loop start
		do {
			// Both players throw once and see who gets closest to 50, that player goes first. (bool var, true = player1, false = player2).
		bool playerTurn;
		int player1ThrowTemp;
		int player2ThrowTemp;
		bool doubleCheck = false;
		player1ThrowTemp = abs(50 - (Throw.Throw501(player1.getSuccessRate(), doubleCheck)));
		player2ThrowTemp = abs(50 - (Throw.Throw501(player2.getSuccessRate(), doubleCheck)));
		if (player2ThrowTemp > player1ThrowTemp) {
			playerTurn = false;
		}
		else {
			playerTurn = true;
		}

		// Game loop start
			do {
				bool roundFinished = false;
				// Round loop start
				do {
					// Create player pointer called currentPlayer that checks the bool variable from before, if false set to reference of player2, if true a reference of player1).
					Player* currentPlayer = (playerTurn) ? (&player1) : (&player2);
					int roundScore = 0;
					// Turn loop start
					for (int i = 0; i < 3; i++) {
						int turnScore = 0;
						bool doubleCheck = false;
						if (currentPlayer->getScore() > 100) {
							int cf = rand() % 3 + 1;
							if (cf == 1) {
								FinalHit = Throw.throwTreble501(currentPlayer->getSuccessRate(), doubleCheck);
								std::cout << currentPlayer->getName() << " has hit a treble score of: " << FinalHit << std::endl;
							}
							else if (cf == 2) {
								FinalHit = Throw.throwDouble501(currentPlayer->getSuccessRate(), doubleCheck);
								std::cout << currentPlayer->getName() << " has hit a double score of: " << FinalHit << std::endl;
							}
							else {
								FinalHit = Throw.Throw501(currentPlayer->getSuccessRate(), doubleCheck);
								std::cout << currentPlayer->getName() << " has hit a single score of: " << FinalHit << std::endl;
							}
						}
						else {
							bool cf = rand() % 2;
							if (cf) {
								FinalHit = Throw.throwDouble501(currentPlayer->getSuccessRate(), doubleCheck);
								std::cout << currentPlayer->getName() << " has hit a double score of: " << FinalHit << std::endl;
							}
							else {
								FinalHit = Throw.Throw501(currentPlayer->getSuccessRate(), doubleCheck);
								std::cout << currentPlayer->getName() << " has hit a single score of: " << FinalHit << std::endl;
							}
						}
						if (currentPlayer->getScore() == 50 && FinalHit == 50) {
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has hit the bullseye whilst having a remaining score of 50! They win this game!" << std::endl;
							std::cout << currentPlayer->getName() << " has now won " << currentPlayer->getGameWins() << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck) {
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has won by hitting a double!" << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck == false) {
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has reached 0 however the last throw wasn't a double, so their score is the same as it was before their turn!" << std::endl;
							break;
						}
						else if ((currentPlayer->getScore() - FinalHit) < 0) {
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " had hit " << FinalHit << " however their score is: " << currentPlayer->getScore() << " so they must hit another double to finish!" << std::endl;
							break;
						}
						else if ((currentPlayer->getScore() - FinalHit) == 1) {
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has ended up on 1 so their score will be the same as it was before their turn!" << std::endl;
							break;
						}
						else {
							roundScore = turnScore + FinalHit; // Add up the round score.
						}
					}
					// Turn loop finish
					currentPlayer->setScore(currentPlayer->getScore() - roundScore); // remove the rounds score from player score as it has passed checks above to ensure it is a valid score.
					playerTurn = !playerTurn; // Set to the opposite player
				// Round loop finish
				} while (roundFinished == false);
				// Set score to 501
				player1.setScore(501);
				player2.setScore(501);
				std::cout << "Game finished!" << std::endl;
			// Game loop finish
			} while (player1.getGameWins() != 3 && player2.getGameWins() != 3);
			std::cout << "Set finished!" << std::endl;
			if (player1.getGameWins() > player2.getGameWins()) {
				player1.setSetWins(player1.getSetWins() + 1);
			}
			else {
				player2.setSetWins(player2.getSetWins() + 1);
			}
			player1.setGameWins(0);
			player2.setGameWins(0);
		// Set loop finish
		} while (player1.getSetWins() != 7 && player2.getSetWins() != 7);
		// sim = sim - 1
		// 
		// Put stats here. 
		//
		sims = sims - 1;
	} while (sims > 0);
	// Match loop end
}
