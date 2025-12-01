#include "Npc.h"
#include "player.h"

Npc::Npc(char mark) : Player(mark){}

// void might be ok
int Npc::checkStage(Board& board) {
	//Find opponet reach
	int blockPos = checkOpponetWinning(board);
    if (blockPos != -1) return blockPos;
    
    int attackPos = checkMyWinning(board);
    if (attackPos != -1) return attackPos;

    return randomMove(board);

    //Block opponet from winning
    //if (blockPos != -1) {
    //    block(board, blockPos);
    //    return 0; // Return with no error.
    //}

    //Attack opponet.
    //if (attackPos != -1) {
    //    attack(board, attackPos);
    //    return 0; // Return with no error.
    //}

    // Go to Random
    // Random move
    // Make some strategy for it.

}

// it might be ok with void.
int Npc::actionStage(Board& board, int actionPos) {
    attack(board, actionPos);
    // TODO
    return 0;
}

int Npc::checkOpponetWinning(Board& board){
    char** b = board.getBoard();
    char opponentMark = ' ';
    if (getMark() == 'o') {
        opponentMark = 'x';
    }
    else {
        opponentMark = 'o';
    }

    // --- Check rows ---
    for (int r = 0; r < 3; r++) {
        int countOpp = 0;
        int empty = -1;

        for (int c = 0; c < 3; c++) {
            if (b[r][c] == opponentMark) countOpp++;
            else if (b[r][c] == '-') empty = r * 3 + c;
        }

        if (countOpp == 2 && empty != -1)
            return empty;  // Block win
    }

    // --- Check columns ---
    for (int c = 0; c < 3; c++) {
        int countOpp = 0;
        int empty = -1;

        for (int r = 0; r < 3; r++) {
            if (b[r][c] == opponentMark) countOpp++;
            else if (b[r][c] == '-') empty = r * 3 + c;
        }

        if (countOpp == 2 && empty != -1)
            return empty;
    }

    // --- Check diagonal 1 (0,4,8) ---
    {
        int countOpp = 0;
        int empty = -1;
        int diag[3] = { 0, 4, 8 };

        for (int i : diag) {
            int r = i / 3;
            int c = i % 3;

            if (b[r][c] == opponentMark) countOpp++;
            else if (b[r][c] == '-') empty = i;
        }

        if (countOpp == 2 && empty != -1)
            return empty;
    }

    // --- Check diagonal 2 (2,4,6) ---
    {
        int countOpp = 0;
        int empty = -1;
        int diag[3] = { 2, 4, 6 };

        for (int i : diag) {
            int r = i / 3;
            int c = i % 3;

            if (b[r][c] == opponentMark) countOpp++;
            else if (b[r][c] == '-') empty = i;
        }

        if (countOpp == 2 && empty != -1)
            return empty;
    }

    return -1;  // No block needed
}

void Npc::block(Board& board,int position){
    board.setBoard(getMark(), position); 
}

int Npc::checkMyWinning(Board& board) {

    // No attack position found
    return -1;
}

void Npc::attack(Board& board, int pos) {
    //TODO
}

int Npc::randomMove(Board& board) {
    //TODO
}