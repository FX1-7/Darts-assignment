#pragma once
#include "Player.h"

class GameCreation
{
public:
	// Functions to create menus, simulation games and manual games.
	void CreateGame(Player&, Player&);
	void Simulation301(Player&, Player&, int, int);
	void Simulation501(Player&, Player&, int);
	void Manual501(Player&, Player&, int);
	void Manual301(Player&, Player&, int, int);
};

