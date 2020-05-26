#include "Interface_handling.h"

int Get_Size() {
	int size;

	std::cout << "Enter Board size: ";
	std::cin >> size;

	if (size < MIN_BOARD) {
		std::cout << "Size too small, minimal size of the gameboard is 3 \nPlease, enter correct value!\n";
		size = Get_Size();
	}
	return size;
}

void MoveStatement(int round) {
	if (round % 2 == 1) {
		std::cout << "----------------\n";
		std::cout << "X player's turn \n";
		std::cout << "----------------\n";
	}
	else {
		std::cout << "----------------\n";
		std::cout << "O player's turn \n";
		std::cout << "----------------\n";
	}
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

void Statement(Board* pBrd, int round) {
	if (pBrd->CheckWinner() == 10 or pBrd->CheckWinner() == -10) {
		if (round % 2 == 1) {
			std::cout << "-------------\n";
			std::cout << "Player 1 wins\n";
			std::cout << "-------------";
		}

		else {
			std::cout << "-------------\n";
			std::cout << "Player 2 wins\n";
			std::cout << "-------------";
		}
	}
	else std::cout << "Tie!";
}

int Menu() {
	int choice;
	std::cout << "--------------------------\n";
	std::cout << "        TIC TAC TOE     \n";
	std::cout << "--------------------------\n";
	std::cout << "1. Player vs Player \n";
	std::cout << "2. Player vs Computer \n";
	std::cout << "> ";
	std::cin >> choice;
	
	if (choice == 1 or choice == 2) return choice;
	else {
		std::cout << "Incorrect option! Try again \n";
		choice = Menu();
	}
}