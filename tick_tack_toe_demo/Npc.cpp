#include "Npc.h"
#include "player.h"

Npc::Npc(char mark) : Player(mark){}

// void might be ok
int Npc::checkStage(Board& board) {
	//Find opponet reach
    int attackPos = checkMyWinning(board);
    if (attackPos != -1) return attackPos;

    int blockPos = checkOpponetWinning(board);
    if (blockPos != -1) return blockPos;
    
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
    board.setBoard(getMark(), actionPos);
    return actionPos;
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

void Npc::block(Board& board,int pos){
    board.setBoard(getMark(), pos); 
}

int Npc::checkMyWinning(Board& board) {
    char** b = board.getBoard();
    char myMark = ' ';
    if (getMark() == 'o') {
        myMark = 'o';
    }
    else {
        myMark = 'x';
    }

    // --- Check rows ---
    for (int r = 0; r < 3; r++) {
        int countOpp = 0;
        int empty = -1;

        for (int c = 0; c < 3; c++) {
            if (b[r][c] == myMark) countOpp++;
            else if (b[r][c] == '-') empty = r * 3 + c;
        }

        if (countOpp == 2 && empty != -1)
            return empty;  // Attack win
    }

    // --- Check columns ---
    for (int c = 0; c < 3; c++) {
        int countOpp = 0;
        int empty = -1;

        for (int r = 0; r < 3; r++) {
            if (b[r][c] == myMark) countOpp++;
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

            if (b[r][c] == myMark) countOpp++;
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

            if (b[r][c] == myMark) countOpp++;
            else if (b[r][c] == '-') empty = i;
        }

        if (countOpp == 2 && empty != -1)
            return empty;
    }

    return -1;  // No attack
}

void Npc::attack(Board& board, int pos) {
    board.setBoard(getMark(), pos);
}

int Npc::randomMove(Board& board) {
    char** b = board.getBoard();

    srand(time(nullptr));

    while (true) {
        int pos = rand() % 9; 

        int r = pos / 3;
        int c = pos % 3;

        if (b[r][c] == '-') {
            return pos;       
        }
       }
    return 0;
}