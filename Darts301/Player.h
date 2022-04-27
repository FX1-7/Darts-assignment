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
	int setTurns(int);
	int setWins(int);
	int getWins();
	std::string getName();
	void setName(std::string);
private:
	int wins;
	int turns;
	int score;
	int SuccessRate;
	std::string name;
};
