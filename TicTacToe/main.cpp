#include <iostream>

#include "Board.h"
#include "Interface_handling.h"

int main() {
	int size;
	int range;
	int round = 1;
	
	bool win = false;

	size = Get_Size();
	range = Get_Range();

	Board* b = new Board(size, range);
	b->Show();

	while (round < (size * size) + 1 and !win) {
		Statement(round, size, win, 1);

		if (round % 2 == 1) std::cout << "Player 1: \n";
		else if (round % 2 == 0) std::cout << "Player 2: \n";

		b->Put(b->GetMove(), round);
		
		b->Show();
		std::cout << std::endl;
		win = b->CheckBoard();
		
		round++;
	}

	Statement(round, size, win, 2);
	
	b->~Board();
}