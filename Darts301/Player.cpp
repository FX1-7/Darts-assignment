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

void Player::setSuccessRate(int tscr) {
	SuccessRate = tscr;
}

Player::~Player() {

}