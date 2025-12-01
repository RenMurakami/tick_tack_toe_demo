#include "Board.h"
#include <iostream>
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

void Board::winCheck() {
	//TODO
}