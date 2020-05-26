#include "Player.h"

/*
	Funkcja rekurencyjna, pobieraj¹ca od gracza ruch.
	Wychwytuje wyjœcie poza granicê planszy oraz miejsce w
	którym stoi ju¿ jakiœ znak.
*/

Move GetMove(Board* pBrd) {
	std::string move, tmp1, tmp2;
	Move pMove;

	std::cout << "Your move: ";
	std::cin >> move;

	tmp1 = move.at(0);
	tmp2 = move.at(1);

	int row = std::stoi(tmp1);
	int col = std::stoi(tmp2);

	if (row < pBrd->b_size and col < pBrd->b_size) {
		if (pBrd->bPointer[row][col] == ' ') {
			pMove.row = row;
			pMove.col = col;
		}
		else {
			std::cout << "Move already happened. Try again! \n";
			pMove = GetMove(pBrd);
		}
	}
	else {
		std::cout << "Move out of range. Try again! \n";
		pMove = GetMove(pBrd);
	}

	return pMove;
}

/*
	Funkcja umieszczaj¹ca na planszy znak gracza.
*/

void Put(Board* pBoard, int round) {
	Move pMove = GetMove(pBoard);
	
	if(round % 2 == 1)	pBoard->bPointer[pMove.row][pMove.col] = PLAYER;
	else if(round % 2 == 0 )	pBoard->bPointer[pMove.row][pMove.col] = COMPUTER;
}

/*
	Funkcja u¿ywana w funkcji Dirver()
*/

void Put(Board* pBrd) {
	pBrd->bPointer[1][1] = PLAYER;
}