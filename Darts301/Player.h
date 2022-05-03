#pragma once
#include <string>

class Player
{
public:
	Player();
	~Player();
	int getScore();
	int getSuccessRate();
	void setScore(int);
	void setSuccessRate(int);
	int getTurns();
	void setTurns(int);
	void setWins(int);
	void setWinRate(float);
	float getWinRate();
	int getWins();
	std::string getName();
	void setName(std::string);
private:
	float winrate;
	int wins;
	int turns;
	int score;
	int SuccessRate;
	std::string name;
};
