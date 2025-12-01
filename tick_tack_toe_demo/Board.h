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

	/*
		Get what is in the specific index
		Index starts from 0 ~ 8
		Return the data in the board.
	*/
	char getIndexBoard(int index);

	
	int checkBoard(int index);

	void showBoard();

	void winCheck();

private:
	char** board;
};

