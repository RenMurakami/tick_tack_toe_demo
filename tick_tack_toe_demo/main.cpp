#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Npc.h"
#include "Human.h"


int main() {

	/*
	* State Machine
	* Check state -> Attack state -> Win check -> change player -> 
	*/

	Human playerO('o');
	Npc playerX('x');
	Player* players[] = {&playerO, &playerX};

	Board board;


	for (int i = 0; i < 9; i++) {
		int inputNum = -1;
		std::cout << "User Update\n";
		Player* currentPlayer = players[i % 2];

		// User Input Mode
		while (!(i % 2)) {
			Human* human = dynamic_cast<Human*>(currentPlayer);

			std::cout << "Get User Input (x)\n" << "Index (0 ~ 8)\n";
			inputNum =human->getInput();
			if (inputNum < 0) {
				continue;
			}
			
			inputNum = board.checkBoard(inputNum);
			if (inputNum == -1) {
				std::cout << "WARNING: There is already a mark there\n";
				continue;
			}
			board.setBoard(human->getMark(), inputNum);
			board.showBoard();
			break;
			
		}

		// NPC Input Mode
		while (i % 2) {
			Npc* npc = dynamic_cast<Npc*>(currentPlayer);
			int actionPos = npc->checkStage(board);

			npc->actionStage(board, actionPos);
			
			//Action

			board.showBoard();
			break; 
		}

		// Check winnning
		if (board.winCheck()) {
			exit(0);
		}
	}




	return 0;
}