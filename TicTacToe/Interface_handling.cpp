#include "Interface_handling.h"

/*int Get_Size() {
	int size;

	std::cout << "Enter Board size: ";
	std::cin >> size;

	if (size < MIN_BOARD) {
		std::cout << "Size too small, minimal size of the gameboard is 3 \nPlease, enter correct value!\n";
		size = Get_Size();
	}
	return size;
}

int Get_Range() {
	int range;

	std::cout << "Enter range: ";
	std::cin >> range;

	if (range < MIN_RANGE) {
		std::cout << "Range too small, minimal size of range is 3 \nPlease, enter correct value!\n";
		range = Get_Range();
	}
	return range;
}

void Statement(int round, int size, bool win, int choice) {
	if (choice == 1) {
		std::cout << "------------------------------\n";
		std::cout << "ROUND " << round << "\n";
		std::cout << "------------------------------\n";
	}

	if (choice == 2) {
		std::cout << "------------------------------\n";
		if (round == (size * size) + 1) {
			std::cout << "Game over, none of players win!\n";
		}
		else if (win and (round - 1) % 2 == 1) {
			std::cout << "Game over, Player 1 win! \n";
		}
		else if (win and (round - 1) % 2 == 0) {
			std::cout << "Game over, Player 2 win! \n";
		}
		std::cout << "------------------------------\n";
	}
}*/