#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {
	score = 301;
	turns = 0;
	wins = 0;
	winrate = 0;
}

int Player::getScore() {
	return score;
}

int Player::getSuccessRate() {
	return SuccessRate;
}

std::string Player::getName() {
	return name;
}

void Player::setName(std::string tName) {
	name = tName;
}

void Player::setScore(int tScore) {
	score = tScore;
}

void Player::setSuccessRate(int tScr) {
	SuccessRate = tScr;
}

int Player::getTurns() {
	return turns;
}
void Player::setTurns(int tTrns) {
	turns = tTrns;
}

void Player::setWins(int tWins) {
	wins = tWins;
}

int Player::getWins() {
	return wins;
}

void Player::setWinRate(float tWinRate) {
	winrate = tWinRate;
}
float Player::getWinRate() {
	return winrate;
}

Player::~Player() {

}