#include "GameCreation.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Dartboard.h"

void GameCreation::CreateGame(Player& player1, Player& player2) {
	// Menu to get names and success rates.
	std::string TempName;
	int TempSuccess;
	// Ask for Player 1's name
	std::cout << "Please Enter Player 1's name:" << std::endl;
	std::cin >> TempName;
	std::cout << std::endl;
	// Ask for their succeess rate.
	std::cout << "Please enter " << TempName << "'s success rate in hitting their target: " << std::endl;
	std::cin >> TempSuccess;
	std::cout << std::endl;
	// Set these details
	player1.setName(TempName);
	player1.setSuccessRate(TempSuccess);
	// Ask for Player 2's name
	std::cout << "Please enter Player 2's name:" << std::endl;
	std::cin >> TempName;
	std::cout << std::endl;
	// Ask for their success rate
	std::cout << "Please enter " << TempName << "'s success rate in hitting their target: " << std::endl;
	std::cin >> TempSuccess;
	std::cout << std::endl;
	// set these details
	player2.setName(TempName);
	player2.setSuccessRate(TempSuccess);

}

void GameCreation::Simulation301(Player& player1, Player& player2, int sims, int choice) {
	// Initalise variables and objects
	int FinalHit;
	Dartboard Throws;
	// Loop that runs off sims variable to ensure the game simulates enough times.
	do {
		// Loop that ensures game finishes when player scores hit 0.
		do {
			// Player 1 has been chosen to go first.
			if (choice == 1) {
				// If the score isn't 0 it announces player 1's turn.
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				// Player 1 throws.
				FinalHit = Throws.Throw301(player1.getSuccessRate());
				// If player1's score is 50 and not 0.
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					// If the throw isn't 50 and also not 0;
					if (FinalHit != 50 && FinalHit != 0) {
						// Then they need a bullseye to finsih the game, their score is unchanged and turns is increased by 1.
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					// If they hit the bullseye.
					else if (FinalHit == 50) {
						// Check to see if their score is under 100, not 50 and not 0.
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							// They hit the bullseye but they can't go below 50, so their score is unchanged and turns increased by 1.
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
						// If they hit the bullseye and their score isn't 0
						else if (player1.getScore() != 0) {
							// Then they hit as expected and their score is changed. Turns is also increased by 1.
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
				}
				// If the throw misses increase turns by 1 and tell the user they missed.
				if (FinalHit == 0) {
					std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// If the hit would bring their score below 50, then tell them that their score is unchanged and to aim for another area, turns is also increased by 1.
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// if their score isn't 0, tell the user that they hit and that their score has been altered. Turns increases by 1.
				else if (player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player1.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// It's player 2's turn.
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				// Player 2 throws.
				FinalHit = Throws.Throw301(player2.getSuccessRate());
				// If player1's score is 50 and not 0
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					// If the throw isn't 50 and also not 0;
					if (FinalHit != 50 && FinalHit != 0) {
						// Then they need a bullseye to finsih the game, their score is unchanged and turns is increased by 1.
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					// If they hit the bullseye.
					else if (FinalHit == 50) {
						// Check to see if their score is under 100, not 50 and not 0.
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							// They hit the bullseye but they can't go below 50, so their score is unchanged and turns increased by 1.
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						}
						// If they hit the bullseye and their score isn't 0
						else if (player2.getScore() != 0) {
							// Then they hit as expected and their score is changed. Turns is also increased by 1.
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
				}
				// If the throw misses increase turns by 1 and tell the user they missed.
				if (FinalHit == 0) {
					std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// If the hit would bring their score below 50, then tell them that their score is unchanged and to aim for another area, turns is also increased by 1.
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player1.getTurns() + 1);
				}
				// if their score isn't 0, tell the user that they hit and that their score has been altered. Turns increases by 1.
				else if (player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// Loop round until their scores are 0.
			}
			// If player 2 is chosen to go first.
			else {
				// As long as their score is over 0, tell them when it's their turn
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				// Player 2 throws.
				FinalHit = Throws.Throw301(player2.getSuccessRate());
				// If player1's score is 50 and not 0
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					// If the throw isn't 50 and also not 0;
					if (FinalHit != 50) {
						// Then they need a bullseye to finsih the game, their score is unchanged and turns is increased by 1.
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					// If they hit the bullseye.
					else if (FinalHit == 50 && FinalHit != 0) {
						// Check to see if their score is under 100, not 50 and not 0.
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							// They hit the bullseye but they can't go below 50, so their score is unchanged and turns increased by 1.
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
						// If they hit the bullseye and their score isn't 0
						else if (player2.getScore() != 0) {
							// Then they hit as expected and their score is changed. Turns is also increased by 1.
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
					// If the throw misses increase turns by 1 and tell the user they missed.
					if (FinalHit == 0) {
						std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
				}
				// If the hit would bring their score below 50, then tell them that their score is unchanged and to aim for another area, turns is also increased by 1.
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// if their score isn't 0, tell the user that they hit and that their score has been altered. Turns increases by 1.
				else if (player2.getScore() != 0) {
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// It's player 1's turn.
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				// Player 1 throws.
				FinalHit = Throws.Throw301(player1.getSuccessRate());
				// If player1's score is 50 and not 0
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					// If the throw isn't 50 and also not 0;
					if (FinalHit != 50 && FinalHit != 0) {
						// Then they need a bullseye to finsih the game, their score is unchanged and turns is increased by 1.
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					// If they hit the bullseye
					else if (FinalHit == 50) {
						// Check to see if their score is under 100, not 50 and not 0.
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							// They hit the bullseye but they can't go below 50, so their score is unchanged and turns increased by 1.
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						}
						// If they hit the bullseye and their score isn't 0
						else if (player1.getScore() != 0) {
							// Then they hit as expected and their score is changed. Turns is also increased by 1.
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
					// If the throw misses increase turns by 1 and tell the user they missed.
					if (FinalHit == 0) {
						std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
				}
				// If the hit would bring their score below 50, then tell them that their score is unchanged and to aim for another area, turns is also increased by 1.
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// if their score isn't 0, tell the user that they hit and that their score has been altered. Turns increases by 1.
				else if (player1.getScore() !=0) {
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
			}
		} while (player1.getScore() > 0 || player2.getScore() > 0);
		// If player 1 has had more turns than player 2
		if (player1.getTurns() > player2.getTurns()) {
			// Then player 2 has won the game, adding 1 win to player2
			std::cout << player2.getName() << " has won the game!" << std::endl;
			std::cout << player1.getName() << " has lost!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		// If not
		else {
			// Then player 1 has won the game, adding 1 win to player1
			std::cout << player1.getName() << " has won the game!" << std::endl;
			std::cout << player2.getName() << " has lost" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		// Getting the amount of games played overall
		float GamesPlayed = player1.getWins() + player2.getWins();
		// Setting each players winrate.
		player1.setWinRate(player1.getWins() / GamesPlayed);
		player2.setWinRate(player2.getWins() / GamesPlayed);
		// Print this
		std::cout << player1.getName() << " has an average winrate of: " << player1.getWinRate() << " they had: " << player1.getTurns() << " turns across this simulation." << std::endl;
		std::cout << player2.getName() << " has an average winrate of: " << player2.getWinRate() << " they had: " << player2.getTurns() << " turns across this simulation." << std::endl;
		// reset the score.
		player1.setScore(301);
		player2.setScore(301);
		// Take one away from the sims var
		sims = sims - 1;
	} while (sims > 0);
}

void GameCreation::Simulation501(Player& player1, Player& player2, int sims) {
	Dartboard Throw; // Dartboard object
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
						// Keep a track of the turn score
						int turnScore = 0;
						// Boolean to check if a double has been hit.
						bool doubleCheck = false;
						// If the current players score is over 100
						if (currentPlayer->getScore() > 100) {
							// generate a random number between 1 and 3, to decide whether they aim for a single, double or teble.
							int cf = rand() % 3 + 1;
							if (cf == 1) {
								// Throw for a teble
								FinalHit = Throw.throwTreble501(currentPlayer->getSuccessRate());
								// output the score they have hit
								std::cout << currentPlayer->getName() << " has aimed for a treble score and hit: " << FinalHit << std::endl;
							}
							else if (cf == 2) {
								// Throw for a double
								FinalHit = Throw.throwDouble501(currentPlayer->getSuccessRate(), doubleCheck);
								// output the score that they hit
								std::cout << currentPlayer->getName() << " has aimed for a double score and hit: " << FinalHit << std::endl;
							}
							else {
								// Throw for a single
								FinalHit = Throw.Throw501(currentPlayer->getSuccessRate(), doubleCheck);
								// output the score that they hit
								std::cout << currentPlayer->getName() << " has aimed for a single score and hit: " << FinalHit << std::endl;
							}
						}
						else {
							// Random chance between 1 and 2
							bool cf = rand() % 2;
							if (cf) {
								// Throw for a double
								FinalHit = Throw.throwDouble501(currentPlayer->getSuccessRate(), doubleCheck);
								// output the score that they hit
								std::cout << currentPlayer->getName() << " has aimed for a double score and hit: " << FinalHit << std::endl;
							}
							else {
								// throw for a single
								FinalHit = Throw.Throw501(currentPlayer->getSuccessRate(), doubleCheck);
								// output the score that they hit.
								std::cout << currentPlayer->getName() << " has aimed for a single score and hit: " << FinalHit << std::endl;
							}
						}
						// If the players score is 50 and final hit is 50
						if (currentPlayer->getScore() == 50 && FinalHit == 50) {
							// alter their score and turns, output that they win, update their game wins, set round to finished and break out of the turn loop.
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has hit the bullseye whilst having a remaining score of 50! They win this game!" << std::endl;
							std::cout << currentPlayer->getName() << " has now won " << currentPlayer->getGameWins() << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						// If the players score - Final hit  would be 0 and they did hit a double
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck) {
							// Alter their score and turns, output they have won, update their game wins, set round to finished and break out of the turn loop.
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has won by hitting a double!" << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						// If the players score - Final hit would be 0 and they did NOT hit a double
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck == false) {
							// Alter their turn, output they did not hit a double and their score has not been changed and then break out of the turn loop.
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has reached 0 however the last throw wasn't a double, so their score is the same as it was before their turn!" << std::endl;
							break;
						}
						// If the players score - Final hit is going to be less than 0
						else if ((currentPlayer->getScore() - FinalHit) < 0) {
							// Alter their turns,  output that they must hit another double to finish and break out of the turn loop.
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " had hit " << FinalHit << " however their score is: " << currentPlayer->getScore() << " so they must hit another double to finish!" << std::endl;
							break;
						}
						// If the players score - Final hit is going to be one
						else if ((currentPlayer->getScore() - FinalHit) == 1) {
							// Alter their turns and output that since they ended on one their score is going to be un altered and break out of the turn loop.
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has ended up on 1 so their score will be the same as it was before their turn!" << std::endl;
							break;
						}
						// If the throw is good, add it to the round score
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
				// Output that a game has finished.
				std::cout << "Game finished!" << std::endl;
			// Game loop finish
			} while (player1.getGameWins() < 3 && player2.getGameWins() < 3);
			// Output that the set has finished
			std::cout << "Set finished!" << std::endl;
			// If player 1 has more game wins than player 2
			if (player1.getGameWins() > player2.getGameWins()) {
				// set player1 set wins to + 1
				player1.setSetWins(player1.getSetWins() + 1);

			}
			// If not
			else {
				// set player2 set wins to + 1
				player2.setSetWins(player2.getSetWins() + 1);
			}
		// Set loop finish
		} while (player1.getSetWins() < 7 && player2.getSetWins() < 7);
		// If player 1 set wins > player 2 set wins
		if (player1.getSetWins() > player2.getSetWins()) {
			// set player1 match wins to + 1
			player1.setMatchWins(player1.getMatchWins() + 1);
		}
		// if not
		else {
			// set player 2 match wins to + 1
			player2.setMatchWins(player2.getMatchWins() + 1);
		}
		// Calculate the amount of games, sets and matches played.
		float GamesPlayed = player1.getGameWins() + player2.getGameWins();
		float SetsPlayed = player1.getSetWins() + player2.getSetWins();
		float MatchesPlayed = player1.getMatchWins() + player2.getMatchWins();
		// Output player 1 game, set and match stats.
		std::cout << player1.getName() << " has won: " << player1.getGameWins() << " games, " << player1.getSetWins() << " sets and " << player1.getMatchWins() << " matches." << std::endl;
		std::cout << "This means " << player1.getName() << " has a game winrate of: " << (player1.getGameWins() / GamesPlayed) << ". And a set winrate of: "
			<< (player1.getSetWins() / SetsPlayed) << ". And a match winrate of: " << (player1.getMatchWins() / MatchesPlayed) << std::endl;
		// Output player 2 game, set and match stats.
		std::cout << player2.getName() << " has won: " << player2.getGameWins() << " games, " << player2.getSetWins() << " sets and " << player2.getMatchWins() << " matches." << std::endl;
		std::cout << "This means " << player2.getName() << " has a game winrate of: " << (player2.getGameWins() / GamesPlayed) << ". And a set winrate of: "
			<< (player2.getSetWins() / SetsPlayed) << ". And a match winrate of: " << (player2.getMatchWins() / MatchesPlayed) << std::endl;
		// sim = sim - 1
		sims = sims - 1;
	} while (sims > 0);
	// Reset wins
	player1.setSetWins(0);
	player2.setSetWins(0);
	player1.setGameWins(0);
	player2.setGameWins(0);
	player1.setMatchWins(0);
	player2.setMatchWins(0);
	// Match loop end
}

void GameCreation::Manual501(Player& player1, Player& player2, int sims) {
	Dartboard Throw; // Dartboard object
	int FinalHit; // Final hit variable to get what the users hit.
	// Match loop start
	do {
		// Set loop start
		do {
			// Initalise variables
			bool playerTurn;
			int player1ThrowTemp;
			int player2ThrowTemp;
			int player1TempScore;
			int player2TempScore;
			bool doubleCheck = false;
			// Both players throw once and see who gets closest to 50, that player goes first. (bool var, true = player1, false = player2).
			std::cout << "================================================" << std::endl;
			std::cout << "Both players will try to hit a bullseye, closest goes first!" << std::endl;
			std::cout << player1.getName() << " is aiming for the bullseye..." << std::endl;
			// Throw for a bull
			player1TempScore = Throw.manualThrowBull501(player1.getSuccessRate());
			// Find the absolute distance from 50
			player1ThrowTemp = abs(50 - player1TempScore);
			// Print what they hit
			std::cout << player1.getName() << " has hit " << player1TempScore << std::endl;
			std::cout << player2.getName() << " is aiming for the bullseye..." << std::endl;
			// Throw for a bull
			player2TempScore = Throw.manualThrowBull501(player2.getSuccessRate());
			// Find the absolute distance from 50
			player2ThrowTemp = abs(50 - player2TempScore);
			// Print what they hit
			std::cout << player2.getName() << " has hit " << player2TempScore << std::endl;
			std::cout << "================================================" << std::endl;
			// If player 2s distance from 50 is smaller than player 1's
			if (player2ThrowTemp < player1ThrowTemp) {
				// set to false (player 2 will go first)
				playerTurn = false;
			}
			// If not
			else {
				// set to true (player 1 will go first)
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
						int aim;
						int choice;
						// Ask the user what they would like to aim for.
						std::cout << "What number would " << currentPlayer->getName() << " like to aim for? 1-20 or 25 for the outer bullseye, 50 for the inner." << std::endl;
						std::cin >> aim;
						// Error check the values to ensure they can't aim for numbers outwith the dartboard.
						while (aim != 25 && aim != 50 && (aim > 20 || aim < 1)) {
							std::cout << "please enter a value between 1 and 20. Or 25 for the outer bullseye, 50 for the inner." << std::endl;
							std::cin >> aim;
						}
						// If aim is 50 (inner bullseye)
						if (aim == 50) {
							// Throw for a bullseye
							FinalHit = Throw.manualThrowBull501(currentPlayer->getSuccessRate());
							// If they hit it
							if (FinalHit == 50) {
								// Woop woop you hit the bullseye
								std::cout << currentPlayer->getName() << " has hit the inner bullseye!" << std::endl;
							}
							// otherwise
							else {
								// whup wha, you hit something else
								std::cout << currentPlayer->getName() << " has hit: " << FinalHit << std::endl;
							}
						}
						// If they're aiming for the outer bullseye
						else if (aim == 25) {;
							// Throw for a bull
							FinalHit = Throw.manualThrowBull501(currentPlayer->getSuccessRate());
							// If they hit it
							if (FinalHit == 25) {
								// Nice shot
								std::cout << currentPlayer->getName() << " has hit the outer bullseye!" << std::endl;
							}
							// Otherwise
							else {
								// They missed, but output what they hit
								std::cout << currentPlayer->getName() << " has hit: " << FinalHit << std::endl;
							}
						}
						// If they're aiming for a number between 20 and 1.
						else if (aim <= 20 && aim >= 1) {
							// Ask if they're aiming for a sinle double or treble.
							std::cout << std::endl << "Would " << currentPlayer->getName() << " like to aim for:" << std::endl << "1. A single" << std::endl << "2. A double" << std::endl << "3. A treble" << std::endl;
							std::cin >> choice;
							// Error handling to get a value we want.
							while (choice != 1 && choice != 2 && choice != 3) {
								std::cout << std::endl << "Please enter a value of 1, 2 or 3." << std::endl;
								std::cin >> choice;
							}
							// If they chose a single
							if (choice == 1) {
								// Throw for a signle
								FinalHit = Throw.manualThrow501(currentPlayer->getSuccessRate(), aim, doubleCheck);
								// output the points they hit.
								std::cout << currentPlayer->getName() << " has hit " << FinalHit << " points" << std::endl;
							}
							// If they chose a double
							else if (choice == 2) {
								// Throw for a double
								FinalHit = Throw.manualThrowDouble501(currentPlayer->getSuccessRate(), aim, doubleCheck);
								// Output the points they hit
								std::cout << currentPlayer->getName() << " has hit " << FinalHit << " points" << std::endl;
							}
							// if they chose a teble	
							else if (choice == 3) {
								// Throw for a treble
								FinalHit = Throw.manualThrowTreble501(currentPlayer->getSuccessRate(), aim);
								// output the points they hit.
								std::cout << currentPlayer->getName() << " has hit " << FinalHit << " points" << std::endl;
							}
						}
						// If their score is 50 and their final hit was 50.
						if (currentPlayer->getScore() == 50 && FinalHit == 50) {
							// Alter their score and turns, output they have won, change the round to finished and break out of the turn loop.
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has hit the bullseye whilst having a remaining score of 50! They win this game!" << std::endl;
							std::cout << currentPlayer->getName() << " has now won " << currentPlayer->getGameWins() << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						// if their score - Final hit is 0 and they hit a double.
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck) {
							// Alter the score, turn count, output they won, set the round to finished and break out of the turn loop.
							currentPlayer->setScore(currentPlayer->getScore() - FinalHit);
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has won by hitting a double!" << std::endl;
							currentPlayer->setGameWins(currentPlayer->getGameWins() + 1);
							roundFinished = true;
							break;
						}
						// If their score - final hit is 0 but they did NOT hit a double
						else if ((currentPlayer->getScore() - FinalHit) == 0 && doubleCheck == false) {
							// Alter their turns but output that their score will remain unchanged. Break out of the turn loop
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has reached 0 however the last throw wasn't a double, so their score is the same as it was before their turn!" << std::endl;
							break;
						}
						// If their score - Final hit is less than 0
						else if ((currentPlayer->getScore() - FinalHit) < 0) {
							// Alter turns, output that they must hit another double to finish and break out of the turn loop
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " had hit " << FinalHit << " however their score is: " << currentPlayer->getScore() << " so they must hit another double to finish!" << std::endl;
							break;
						}
						// If their score - Final hit would be 1 
						else if ((currentPlayer->getScore() - FinalHit) == 1) {
							// Alter turns but output that they have ended up on one so their score will be un altered. Break out of the turn loop
							currentPlayer->setTurns(currentPlayer->getTurns() + 1);
							std::cout << currentPlayer->getName() << " has ended up on 1 so their score will be the same as it was before their turn!" << std::endl;
							break;
						}
						// If the throw is good, add to the round score.
						else {
							roundScore = turnScore + FinalHit; // Add up the round score.
						}
					}
					// Turn loop finish
					currentPlayer->setScore(currentPlayer->getScore() - roundScore); // remove the rounds score from player score as it has passed checks above to ensure it is a valid score.
					std::cout << currentPlayer->getName() << "'s points are now: " << currentPlayer->getScore() << "!" << std::endl;
					playerTurn = !playerTurn; // Set to the opposite player
				// Round loop finish
				} while (roundFinished == false);
				// Set score to 501
				player1.setScore(501);
				player2.setScore(501);
				// output the a game is finished
				std::cout << "Game finished!" << std::endl;
				// Game loop finish
			} while (player1.getGameWins() < 3 && player2.getGameWins() < 3);
			// Output that a set has finsihed
			std::cout << "Set finished!" << std::endl;
			// If player 1 has more game wins than player 2
			if (player1.getGameWins() > player2.getGameWins()) {
				// Add 1 to player1s set wins
				player1.setSetWins(player1.getSetWins() + 1);

			}
			// If not
			else {
				// Add 1 to player2's set wins
				player2.setSetWins(player2.getSetWins() + 1);
			}
			// Set loop finish
		} while (player1.getSetWins() < 7 && player2.getSetWins() < 7);
		// If player 1 has more set wins than player 2
		if (player1.getSetWins() > player2.getSetWins()) {
			// Add 1 to player1's match wins
			player1.setMatchWins(player1.getMatchWins() + 1);
		}
		// if not
		else {
			// add one to player2's match wins.
			player2.setMatchWins(player2.getMatchWins() + 1);
		}
		// Find the total games, sets and matches played
		float GamesPlayed = player1.getGameWins() + player2.getGameWins();
		float SetsPlayed = player1.getSetWins() + player2.getSetWins();
		float MatchesPlayed = player1.getMatchWins() + player2.getMatchWins();
		// Calculate and output the stats for games, sets and matches won for each player along with the winrates for each.
		std::cout << player1.getName() << " has won: " << player1.getGameWins() << " games, " << player1.getSetWins() << " sets and " << player1.getMatchWins() << " matches." << std::endl;
		std::cout << "This means " << player1.getName() << " has a game winrate of: " << (player1.getGameWins() / GamesPlayed) << ". And a set winrate of: "
			<< (player1.getSetWins() / SetsPlayed) << ". And a match winrate of: " << (player1.getMatchWins() / MatchesPlayed) << std::endl;
		// Calculate and output the stats for games, sets and matches won for each player along with the winrates for each.
		std::cout << player2.getName() << " has won: " << player2.getGameWins() << " games, " << player2.getSetWins() << " sets and " << player2.getMatchWins() << " matches." << std::endl;
		std::cout << "This means " << player2.getName() << " has a game winrate of: " << (player2.getGameWins() / GamesPlayed) << ". And a set winrate of: "
			<< (player2.getSetWins() / SetsPlayed) << ". And a match winrate of: " << (player2.getMatchWins() / MatchesPlayed) << std::endl;
		// sim = sim - 1
		sims = sims - 1;
	} while (sims > 0);
	// reset wins
	player1.setSetWins(0);
	player2.setSetWins(0);
	player1.setGameWins(0);
	player2.setGameWins(0);
	player1.setMatchWins(0);
	player2.setMatchWins(0);
	// Match loop end
}


void GameCreation::Manual301(Player& player1, Player& player2, int sims, int choice) {
	// Initalise variables and objects
	int FinalHit;
	Dartboard Throws;
	int aim;
	// Simulation loop 
	do {
		// Play until players reach 0
		do {
			// If player 1 is going first
			if (choice == 1) {
				// If player 1's score is not 0 announce it is their turn to throw.
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				// Ask what they want to aim at.
				std::cout << "What does " << player1.getName() << " want to aim at? A value between 1 and 20, or alternatively a 50 to aim at the bullseye." << std::endl;
				std::cin >> aim;
				// Error handling to ensure that we're aiming at a bullseye or number on the dartboard.
				while (aim != 50 && (aim > 20 || aim < 1)) {
					std::cout << "Please enter a value between 1 and 20, or alternatively enter 50 in order to aim for the bullseye." << std::endl;
					std::cin >> aim;
				}
				// Throw
				FinalHit = Throws.manualThrow301(player1.getSuccessRate(), aim);
				// If their score is 50 and not 0
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					// If Finalhit is not 50 and not 0
					if (FinalHit != 50 && FinalHit != 0) {
						// They hit x however a bull is needed to finish the game, plus 1 to their turn and dont edit their score.
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					// If they hit the bull
					else if (FinalHit == 50) {
						// If their score is under 100 but not 50 or 0
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							// They need to aim for another area so that their score isn't brought below 50. +1 to their turns but dont alter score
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
						// If their score is not 0
						else if (player1.getScore() != 0) {
							// They have hit the bullseye, alter their score and +1 to the turns.
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
				}
				// If the throw missed
				if (FinalHit == 0) {
					// Tell the user they missed. +1 to turns
					std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// If the players score - Final hit would be lower than 50 and their score is not 0
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					// They have hit x but it'd bring them below 50, score un altered but _+1 to turns
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// If the players score is not 0
				else if (player1.getScore() != 0) {
					// they have hit points, alter score, output the new score and +1 to turns
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player1.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// It's the next players turn
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				// Ask what they want to aim at.
				std::cout << "What does " << player2.getName() << " want to aim at? A value between 1 and 20, or alternatively a 50 to aim at the bullseye." << std::endl;
				std::cin >> aim;
				// Error handling to ensure we get a value we want.
				while (aim != 50 && (aim > 20 || aim < 1)) {
					std::cout << "Please enter a value between 1 and 20, or alternatively enter 50 in order to aim for the bullseye." << std::endl;
					std::cin >> aim;
				}
				// Throw
				FinalHit = Throws.manualThrow301(player2.getSuccessRate(), aim);
				// If their score is 50 and not 0
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					// If Finalhit is not 50 and not 0
					if (FinalHit != 50 && FinalHit != 0) {
						// They hit x however a bull is needed to finish the game, plus 1 to their turn and dont edit their score.
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					// If they hit the bull
					else if (FinalHit == 50) {
						// If their score is under 100 but not 50 or 0
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							// They need to aim for another area so that their score isn't brought below 50. +1 to their turns but dont alter score
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						}
						// If their score is not 0
						else if (player2.getScore() != 0) {
							// They have hit the bullseye, alter their score and +1 to the turns.
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
				}
				// If the throw missed
				if (FinalHit == 0) {
					// Tell the user they missed. +1 to turns
					std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// If the players score - Final hit would be lower than 50 and their score is not 0
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					// They have hit x but it'd bring them below 50, score un altered but _+1 to turns
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player1.getTurns() + 1);
				}
				// If the players socre is not 0
				else if (player2.getScore() != 0) {
					// they have hit points, alter score, output the new score and +1 to turns
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
			}
			// If player 2 was selected to go first
			else {
				// Announce it's their turn as long astheir score is not 0
				if (player2.getScore() != 0) {
					std::cout << "It is " << player2.getName() << "'s turn to throw!" << std::endl;
				}
				// Ask what they want to aim at
				std::cout << "What does " << player2.getName() << " want to aim at? A value between 1 and 20, or alternatively a 50 to aim at the bullseye." << std::endl;
				std::cin >> aim;
				// Error handling to ensure we get a value we want.
				while (aim != 50 && (aim > 20 || aim < 1)) {
					std::cout << "Please enter a value between 1 and 20, or alternatively enter 50 in order to aim for the bullseye." << std::endl;
					std::cin >> aim;
				}
				// Throw
				FinalHit = Throws.manualThrow301(player2.getSuccessRate(), aim);
				// If their score is 50 and not 0
				if (player2.getScore() == 50 && player2.getScore() != 0) {
					// If Finalhit is not 50 and not 0
					if (FinalHit != 50) {
						// They hit x however a bull is needed to finish the game, plus 1 to their turn and dont edit their score.
						std::cout << player2.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
					// If Finalhit is not 50 and not 0
					else if (FinalHit == 50 && FinalHit != 0) {
						// They hit x however a bull is needed to finish the game, plus 1 to their turn and dont edit their score.
						if (player2.getScore() < 100 && player2.getScore() != 50 && player2.getScore() != 0) {
							std::cout << player2.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
						// If they hit the bull
						else if (player2.getScore() != 0) {
							// Output they have hit the bullseye, alter the score and +1 the turn
							std::cout << player2.getName() << " has hit the bullseye!" << std::endl;
							player2.setScore(player2.getScore() - FinalHit);
							std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
							player2.setTurns(player2.getTurns() + 1);
						}
					}
					// If final hit is 0
					if (FinalHit == 0) {
						// They have missed +1 to turns.
						std::cout << player2.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
						player2.setTurns(player2.getTurns() + 1);
					}
				}
				// If the players score - Final hit is less than 50 and their score isn't 0
				else if (player2.getScore() - FinalHit < 50 && player2.getScore() != 0) {
					// Output what they hit and that it would bring their score below 50 so they must try again. +1 to turns
					std::cout << player2.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// If their score is not 0
				else if (player2.getScore() != 0) {
					// Output what they hit, alter the score and +1 to turns
					std::cout << player2.getName() << " has hit " << FinalHit << "!" << std::endl;
					player2.setScore(player2.getScore() - FinalHit);
					std::cout << player2.getName() << "'s score is now: " << player2.getScore() << std::endl;
					player2.setTurns(player2.getTurns() + 1);
				}
				// It is player1s turn
				if (player1.getScore() != 0) {
					std::cout << "It is " << player1.getName() << "'s turn to throw!" << std::endl;
				}
				// Ask what they want to aim at
				std::cout << "What does " << player1.getName() << " want to aim at? A value between 1 and 20, or alternatively a 50 to aim at the bullseye." << std::endl;
				std::cin >> aim;
				// Error handling to ensure we get a value that we want.
				while (aim != 50 && (aim > 20 || aim < 1)) {
					std::cout << "Please enter a value between 1 and 20, or alternatively enter 50 in order to aim for the bullseye." << std::endl;
					std::cin >> aim;
				}
				// Throw
				FinalHit = Throws.manualThrow301(player1.getSuccessRate(), aim);
				// If their score is 50 and not 0
				if (player1.getScore() == 50 && player1.getScore() != 0) {
					// If Finalhit is not 50 and not 0
					if (FinalHit != 50 && FinalHit != 0) {
						// They hit x however a bull is needed to finish the game, plus 1 to their turn and dont edit their score.
						std::cout << player1.getName() << " has hit " << FinalHit << " as they are on 50, this needs to a bullseye! Unlucky!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
					// If Final hit is 50
					else if (FinalHit == 50) {
						// If player 1 score is less than 100 and not 50 or 0, output theymust aim for another area, +1 to turns
						if (player1.getScore() < 100 && player1.getScore() != 50 && player1.getScore() != 0) {
							std::cout << player1.getName() << " has hit the bullseye, however - their score is under 100, so their score lower than 50! They must aim at another area!" << std::endl;
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
						// If players score is not 0
						else if (player1.getScore() != 0) {
							// They have hit the bullseye, alter score and +1 turns
							std::cout << player1.getName() << " has hit the bullseye!" << std::endl;
							player1.setScore(player1.getScore() - FinalHit);
							std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
							player1.setTurns(player1.getTurns() + 1);
						}
					}
					// If they missed
					if (FinalHit == 0) {
						// Output the user missed and +1 to turns
						std::cout << player1.getName() << " has missed the all the areas!" << std::endl;
						std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
						player1.setTurns(player1.getTurns() + 1);
					}
				}
				// If the score - Final hit would be less than 50 and not 0
				else if (player1.getScore() - FinalHit < 50 && player1.getScore() != 0) {
					// They have hit x but it'd bring their score below 50 so aim for another area. Do not alter score but + 1 turn.
					std::cout << player1.getName() << " has hit " << FinalHit << " However this would bring their score below 50 so they must aim for another area!" << std::endl;
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
				// If they hit an area and their score is not 0
				else if (player1.getScore() != 0) {
					// Output what they hit and edit score, +1 turns
					std::cout << player1.getName() << " has hit " << FinalHit << "!" << std::endl;
					player1.setScore(player1.getScore() - FinalHit);
					std::cout << player1.getName() << "'s score is now: " << player1.getScore() << std::endl;
					player1.setTurns(player1.getTurns() + 1);
				}
			}
		} while (player1.getScore() > 0 || player2.getScore() > 0);
		// If player1 has more turns than player 2
		if (player1.getTurns() > player2.getTurns()) {
			// Player 2 won the game. + 1 win for player2
			std::cout << player2.getName() << " has won the game!" << std::endl;
			std::cout << player1.getName() << " has lost!" << std::endl;
			player2.setWins(player2.getWins() + 1);
		}
		// If not
		else {
			// Player 1 has won, + 1 win for player1
			std::cout << player1.getName() << " has won the game!" << std::endl;
			std::cout << player2.getName() << " has lost" << std::endl;
			player1.setWins(player1.getWins() + 1);
		}
		// Get total games played
		float GamesPlayed = player1.getWins() + player2.getWins();
		// calculate and set winrates
		player1.setWinRate(player1.getWins() / GamesPlayed);
		player2.setWinRate(player2.getWins() / GamesPlayed);
		// output winrates
		std::cout << player1.getName() << " has an average winrate of: " << player1.getWinRate() << " they had: " << player1.getTurns() << " turns across this simulation." << std::endl;
		std::cout << player2.getName() << " has an average winrate of: " << player2.getWinRate() << " they had: " << player2.getTurns() << " turns across this simulation." << std::endl;
		// reset score
		player1.setScore(301);
		player2.setScore(301);
		// -1 sims
		sims = sims - 1;
	} while (sims > 0);
}