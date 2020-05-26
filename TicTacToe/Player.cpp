#include "Player.h"

/*
	Funkcja rekurencyjna, pobieraj¹ca od gracza ruch.
	Wychwytuje wyjœcie poza granicê planszy oraz miejsce w
	którym stoi ju¿ jakiœ znak.
*/

Move GetMove(Board* pBrd) {
	Move pMove;

	std::cin >> pMove;

	if (pMove.row < pBrd->b_size and pMove.col < pBrd->b_size) {
		if (pBrd->bPointer[pMove.row][pMove.col] != ' ') {
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
	else if(round % 2 == 0 )	pBoard->bPointer[pMove.row][pMove.col] = OPPONENT;
}

/*
	Funkcja u¿ywana w funkcji Dirver()
*/

void Put(Board* pBrd) {
	pBrd->bPointer[1][1] = PLAYER;
}
