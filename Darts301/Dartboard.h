#pragma once
class Dartboard
{
public:
	int Throw301(int);
	int manualThrow301(int, int);
	int manualThrow501(int, int, bool&);
	int manualThrowDouble501(int, int, bool&);
	int manualThrowTreble501(int, int, bool&);
	int manualThrowBull501(int);
	int Throw501(int, bool&);
	int throwDouble501(int, bool&);
	int throwTreble501(int, bool&);
};

