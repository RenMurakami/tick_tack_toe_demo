#pragma once
#include <iostream>
#include "Board.h"
#include <string>

class Player
{
public:
	Player(); // Default constructor
	Player(char mark); // Constructor
	virtual ~Player();

	int getInput();

	char getMark();


private:
	const char MARK;
};

