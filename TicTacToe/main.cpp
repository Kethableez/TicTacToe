#include <iostream>
#include <chrono>

#include "Board.h"
#include "AI.h"
#include "Player.h"
//#include "Interface_handling.h"



int main() {
	

	Board* pBrd = new Board(3, 3);
	pBrd->Show();
	bool isLeft = true;

	int round = 1;
	
	while (isLeft) {
		if (round % 2 == 1) {
			Put(pBrd, round);
			pBrd->Show();
		}
		else if (round % 2 == 0) {
		CPut(pBrd);
			//Put(pBrd, round);
			pBrd->Show();

		}

		std::cout << pBrd->CheckWinner() << std::endl;
		isLeft = pBrd->IsMovieLeft();
		round++;
	}

	pBrd->~Board();
}