#include <iostream>

#include "Board.h"

int main() {
	int size;
	int round = 1;

	std::cout << "Enter Board size: ";
	std::cin >> size;

	Board* b = new Board(size);
	b->Show();

	while (round < (size * size) + 1) {
		std::cout << "------------------------------\n";
		std::cout << "ROUND " << round << "\n";
		std::cout << "------------------------------\n";


		if (round % 2 == 1) std::cout << "Player 1: \n";
		else if (round % 2 == 0) std::cout << "Player 2: \n";

		b->Put(b->GetMove(), round);
		b->Show();
		round++;
	}
	std::cout << "Game over, end of rounds!";
	b->~Board();
}