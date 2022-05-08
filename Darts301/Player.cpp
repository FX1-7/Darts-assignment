#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {
	// Set to 0 as users can play both 301 and 501, the score is set in their choice.
	score = 0;

	turns = 0;
	wins = 0;
	winrate = 0;
	SuccessRate = 0;

	// These variables are only for 501.
	setsWon = 0;
	gamesWon = 0;
	matchesWon = 0;
}

// Function to return score
int Player::getScore() {
	return score;
}

// Function to return success rate
int Player::getSuccessRate() {
	return SuccessRate;
}

// Function to return name
std::string Player::getName() {
	return name;
}

// Function to set name
void Player::setName(std::string tName) {
	name = tName;
}

// Function to set score
void Player::setScore(int tScore) {
	score = tScore;
}

// Function to set success rate
void Player::setSuccessRate(int tScr) {
	SuccessRate = tScr;
}

// Function to return turns
int Player::getTurns() {
	return turns;
}

// Function to set turns
void Player::setTurns(int tTrns) {
	turns = tTrns;
}

// Function to set wins
void Player::setWins(int tWins) {
	wins = tWins;
}

// Function to return wins
int Player::getWins() {
	return wins;
}

// Function to set winrate
void Player::setWinRate(float tWinRate) {
	winrate = tWinRate;
}

// Function to return winrate
float Player::getWinRate() {
	return winrate;
}

// Function to set game wins (501)
void Player::setGameWins(int tGameWins) {
	gamesWon = tGameWins;
}

// Function to set match wins (501)
void Player::setMatchWins(int tMatchWins) {
	matchesWon = tMatchWins;
}

// Function to set set wins (501)
void Player::setSetWins(int tSetWins) {
	setsWon = tSetWins;
}

// Function to return game wins (501)
int Player::getGameWins() {
	return gamesWon;
}

// Function to return match wins (501)
int Player::getMatchWins() {
	return matchesWon;
}

// Function to return set wins (501)
int Player::getSetWins() {
	return setsWon;
}

Player::~Player() {

}