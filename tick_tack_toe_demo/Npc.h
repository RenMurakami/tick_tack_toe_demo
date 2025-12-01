#pragma once
#include "player.h"
class Npc : public Player
{
public:
	Npc(char mark);

	int checkStage(Board& board);
	int actionStage(Board& board, int actionPos);

	/*function used in actionStage*/
	
	//Block opponets winning patterns
	
	void block(Board& board, int pos);

	
	//Put my mark on the board.
	
	void attack(Board& board, int pos);

	//Find where 2 opponet marks on the board.
	//return action position
	
	int checkOpponetWinning(Board& board);

	
	//Find where 2 my marks on the board.
	//return action position
	
	int checkMyWinning(Board& board);

	int randomMove(Board& board);

private:
};

