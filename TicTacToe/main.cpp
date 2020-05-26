#include <iostream>
#include <chrono>

#include "Board.h"
#include "AI.h"
#include "Player.h"
#include "Interface_handling.h"



int main() {
	int round = 1;
	bool PvC = false;
	bool isLeft = true;
	
	int choice = Menu();
	int size = Get_Size();
	int range = Get_Range();

	if (choice == 2) PvC = true;

	Board* pBrd = new Board(size, range);
	pBrd->Show();

	while (isLeft) {
		if (round % 2 == 1) {
			Put(pBrd, round);
			pBrd->Show();
		}
		
		else if (round % 2 == 0) {
			auto start = std::chrono::steady_clock::now();
			if (PvC) CPut(pBrd);
			else Put(pBrd, round);
			auto end = std::chrono::steady_clock::now();
			std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us \n";
			pBrd->Show();
		}

		if (pBrd->CheckWinner() == 10 or pBrd->CheckWinner() == -10) {
			break;
		}
		
		isLeft = pBrd->IsMovieLeft();
		round++;
	}

	Statement(pBrd, round);
	pBrd->~Board();
}