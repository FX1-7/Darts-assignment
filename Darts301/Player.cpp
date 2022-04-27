#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {
	score = 301;
}

int Player::getScore() {
	return Player::score;
}

int Player::getSuccessRate() {
	return Player::SuccessRate;
}

std::string Player::getName() {
	return Player::name;
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
	return Player::turns;
}

int Player::setTurns(int tTrns) {
	turns = tTrns;
}

int Player::setWins(int tWins) {
	wins = tWins;
}

Player::~Player() {

}