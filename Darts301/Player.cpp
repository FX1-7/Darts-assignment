#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {
	score = 301;
	turns = 0;
	wins = 0;
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
void Player::setTurns(int tTrns) {
	turns = tTrns;
}

void Player::setWins(int tWins) {
	wins = tWins;
}

int Player::getWins() {
	return Player::wins;
}

Player::~Player() {

}