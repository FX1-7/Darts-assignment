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
	void setSetWins(int);
	void setGameWins(int);
	void setMatchWins(int);
	int getSetWins();
	int getGameWins();
	int getMatchWins();
	float getWinRate();
	int getWins();
	std::string getName();
	void setName(std::string);
private:
	float winrate;
	int setsWon;
	int gamesWon;
	int matchesWon;
	int wins;
	int turns;
	int score;
	int SuccessRate;
	std::string name;
};
