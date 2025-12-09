#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
	board = new char*[3];
	for (int i = 0; i < 3; i++) {
		board[i] = new char[3];

		for (int j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
}

Board::~Board() {
	for (int i = 0; i < 3; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void Board::setBoard(char user_input, int index) {
	int* coord = getRowCol(index);
	board[coord[0]][coord[1]] = user_input;
}

char** Board::getBoard() {
	return board;
}

int* Board::getRowCol(int index) {
	int x = index / 3;
	int y = index % 3;
	int arr[2] = { x,y };
	return arr;
}

int Board::checkBoard(int index) {
	int* coord= getRowCol(index);
	if (board[coord[0]][coord[1]] != '-') {
		// return -1 for mark is there situation.
		return -1;
	}
	return index;
}

void Board::showBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "| " << board[i][j];
		}
		std::cout << "|\n";
	}
}

bool Board::winCheck() {
	// board's data change to number
	char number[3][3] = {
		{board[0][0],board[0][1],board[0][2] },
		{board[1][0],board[1][1],board[1][2] },
		{board[2][0],board[2][1],board[2][2] }
	};

	for (int i = 1; i < 10; i++) {
		char* current_pos = &number[(i - 1) / 3][(i - 1) % 3];

		if (*current_pos == 'o') {
			*current_pos = 1;
		}
		else if (*current_pos == 'x') {
			*current_pos = -1;
		}
		else {
			*current_pos = 0;
		}

		//check the row
		for (int i = 0; i < 3; i++) {
			int row = number[i][0] + number[i][1] + number[i][2];
			if (row == 3) {
				cout << "winner is the o!" << endl;
				return true;
				
			}
			else if (row == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the col
		for (int i = 0; i < 3; i++) {
			int col = number[0][i] + number[1][i] + number[2][i];
			if (col == 3) {
				cout << "winner is the o!" << endl;
				return true;
			}
			else if (col == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the upper right diagonal
		int diago = number[0][2] + number[1][1] + number[2][0];
		if (diago == 3) {
			cout << "winner is the o!" << endl;
			return true;
		}
		else if (diago == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}

		diago = number[0][0] + number[1][1] + number[2][2];
		//check the upper left diagonal
		if (diago == 3) {
			cout << "winner is the o!" << endl;
			return true;
		}
		else if (diago == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}

	}
	return false;
}