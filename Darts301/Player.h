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
	std::string getName();
	void setName(std::string);
private:
	int score;
	int SuccessRate;
	std::string name;
};
