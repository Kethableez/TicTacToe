#include <iostream>
#include <chrono>

#include "Board.h"
#include "AI.h"
#include "Player.h"
#include "Interface_handling.h"



int main() {
	int size = Get_Size();
	int range = Get_Range();
	int choice;
	bool PvC = false;

	std::cout << "1. Player vs Player \n";
	std::cout << "2. Playr vs Computer \n";
	std::cin >> choice;
	if (choice == 2) PvC = true;

	Board* pBrd = new Board(size, range);
	
	pBrd->Show();
	bool isLeft = true;

	int round = 1;
	
	while (isLeft) {
		if (round % 2 == 1) {
			Put(pBrd, round);
			pBrd->Show();
		}
		else if (round % 2 == 0) {
			if (PvC) CPut(pBrd);
			else Put(pBrd, round);
			pBrd->Show();

		}

		if (pBrd->CheckWinner() == 10 or pBrd->CheckWinner() == -10) {
			break;
		}
		
		isLeft = pBrd->IsMovieLeft();
		round++;
	}
	

	if (pBrd->CheckWinner() == 10 or pBrd->CheckWinner() == -10) {
		if (round % 2 == 1) std::cout << "Player 1 wins";
		else std::cout << "Player 2 wins";
	}
	else std::cout << "Tie!";

	pBrd->~Board();
}