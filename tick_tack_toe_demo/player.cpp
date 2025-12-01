#include "Player.h"

Player::Player() : MARK(NULL) {}; 
//                     constructor initializer list
Player::Player(char mark) : MARK(mark) {}

Player::~Player() {}

char Player::getMark() {
	return MARK;
}

int Player::getInput() {
	std::string index = "";
	std::cin >> index;

	// Check Input data 
	if (index.size() != 1) {
		std::cerr << "WARNING: Input is too long.\n";
		return -1;
	}
	if (!std::isdigit(index[0])) {
		std::cerr << "WARNING: Input is not digit.\n";
		return -2;
	}
	int inputNum = stoi(index);
	if (inputNum > 8 && inputNum < 0) {
		std::cerr << "WARNING: Input is out of index.\n";
		return -3;
	}

	return inputNum;
}
