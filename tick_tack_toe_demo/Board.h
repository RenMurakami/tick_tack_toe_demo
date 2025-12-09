#pragma once

#include <iostream>
class Board
{
public:
	Board();
	
	// Memory Leak Prevention
	//Destructor
	~Board();

	void setBoard(char user_input, int index);
	char** getBoard();

	int* getRowCol(int index);

	int checkBoard(int index);

	void showBoard();

	bool winCheck();

private:
	char** board;
};

