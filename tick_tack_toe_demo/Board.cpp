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
		if (number[(i - 1) / 3][(i - 1) % 3] == 'o') {
			number[(i - 1) / 3][(i - 1) % 3] = 1;
		}
		else if (number[(i - 1) / 3][(i - 1) % 3] == 'x') {
			number[(i - 1) / 3][(i - 1) % 3] = -1;
		}
		else {
			number[(i - 1) / 3][(i - 1) % 3] = 0;
		}
		//check the row
		for (int i = 0; i < 3; i++) {
			if (number[i][0] + number[i][1] + number[i][2] == 3) {
				cout << "winner is the o!" << endl;
				return true;
				
			}
			else if (number[i][0] + number[i][1] + number[i][2] == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the col
		for (int i = 0; i < 3; i++) {
			if (number[0][i] + number[1][i] + number[2][i] == 3) {
				cout << "winner is the o!" << endl;
				return true;
			}
			else if (number[0][i] + number[1][i] + number[2][i] == -3) {
				cout << "winner is the x!" << endl;
				return true;
			}
		}
		//check the upper right diagonal
		if (number[0][2] + number[1][1] + number[2][0] == 3) {
			cout << "winner is the o!" << endl;
			return true;
		}
		else if (number[0][2] + number[1][1] + number[2][0] == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}
		//check the upper left diagonal
		if (number[0][0] + number[1][1] + number[2][2] == 3) {
			cout << "winner is the o!" << endl;
			return true;
		}
		else if (number[0][0] + number[1][1] + number[2][2] == -3) {
			cout << "winner is the x!" << endl;
			return true;
		}

	}
	return false;
}