#include "Player.h"


void Put(Board* pBoard, int round) {
	std::string move, tmp1, tmp2;
	Move pMove;
	std::cout << "Your move: ";
	std::cin >> move;

	tmp1 = move.at(0);
	tmp2 = move.at(1);

	pMove.row = std::stoi(tmp1);
	pMove.col = std::stoi(tmp2);

	if(round % 2 == 1)	pBoard->bPointer[pMove.row][pMove.col] = PLAYER;
	else if(round % 2 == 0 )	pBoard->bPointer[pMove.row][pMove.col] = COMPUTER;



}
/*
bool IsAlready(Board* pBoard, Move pMove) {
	if (pBoard->bPointer[pMove.row][pMove.col] == ' ') return true;
	else return false;
}*/