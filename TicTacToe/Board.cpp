#include "Board.h"

Board::Board(int nsize, int nrange) {
	this->size = nsize;
	this->range = nrange;

	this->mPointer = new std::string[this->size * this->size];

	this->bPointer = new char* [this->size];
	for (int i = 0; i < this->size; ++i) {
		this->bPointer[i] = new char[this->size];
	}

	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->bPointer[i][j] = ' ';
		}
	}

	for (int j = 0; j < this->size; j++) {
		this->mPointer[j] = " ";
	}
}

void Board::Show() {
	std::cout << std::endl;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			std::cout << this->bPointer[i][j];
			if (j != this->size - 1) std::cout << "|";
		}
		if (i != this->size - 1) {
			std::cout << std::endl;
			for (int k = 0; k < this->size + this->size - 1; k++) {
				if (k % 2 == 1) std::cout << "+";
				else if (k % 2 == 0) std::cout << "-";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Board::Put(std::string move, int round) {
	std::string tmp1, tmp2;

	this->mPointer[round - 1] = move;

	tmp1 = move.at(0);
	tmp2 = move.at(1);

	int row = std::stoi(tmp1);
	int col = std::stoi(tmp2);

	// Odd number of rounds -> Player1 move
	// Even number of rounds -> Player2 move

	if (round % 2 == 1) this->bPointer[row][col] = 'X';
	else if (round % 2 == 0) this->bPointer[row][col] = 'O';
}

std::string Board::GetMove() {
	std::string move, tmp1, tmp2;

	std::cout << "Your move: ";
	std::cin >> move;

	tmp1 = move.at(0);
	tmp2 = move.at(1);

	int row = std::stoi(tmp1);
	int col = std::stoi(tmp2);


	if (row >= this->size or col >= this->size) {
		std::cout << "Value off table. Try again. \nSize of gameboard is " << this->size << std::endl;
		move = GetMove();
	}

	if (IsAlready(move)) {
		std::cout << "Move already happened, try again" << std::endl;
		move = GetMove();
	}
	return move;
}

bool Board::IsAlready(std::string move) {
	for (int i = 0; i < this->size * this->size; i++) {
		if (move == this->mPointer[i]) return true;
	}
	return false;
}

Board::~Board() {
	delete[] this->mPointer;
	for (int i = 0; i < this->size; i++) {
		delete[] this->bPointer[i];
	}
}

/*
	CHECK CASES:
	1 -> across
	2 -> down
	3 -> right
	4 -> across reversed
*/

bool Board::IsTheSame(int r1, int c1, int c_case) {
	bool win = false;

	if (c_case == 1) {
		if (this->bPointer[r1][c1] != ' ') {
			for (int i = 1; i < this->range; i++) {
				if (this->bPointer[r1][c1] != this->bPointer[r1 + i][c1 + i]) {
					win = false;
					break;
				}
				else win = true;
			}
		}
	}

	else if (c_case == 2) {
		if (this->bPointer[r1][c1] != ' ') {
			for (int i = 1; i < this->range; i++) {
				if (this->bPointer[r1][c1] != this->bPointer[r1 + i][c1]) {
					win = false;
					break;
				}
				else win = true;
			}
		}
	}

	else if (c_case == 3) {
		if (this->bPointer[r1][c1] != ' ') {
			for (int i = 1; i < this->range; i++) {
				if (this->bPointer[r1][c1] != this->bPointer[r1][c1+i]) {
					win = false;
					break;
				}
				else win = true;
			}
		}
	}
	
	else if (c_case == 4) {
		if (this->bPointer[r1][c1] != ' ') {
			for (int i = 1; i < this->range; i++) {
				if (this->bPointer[r1][c1] != this->bPointer[r1 + i][c1 - i]) {
					win = false;
					break;
				}
				else win = true;
			}
		}
	}

	return win;
}

bool Board::CheckBoard() {
	bool win = false;

	if (this->size == this->range) {
		if (this->IsTheSame(0, 0, 1)) return true;

		for (int i = 0; i < this->size; i++) {
			if (this->IsTheSame(0, i, 2)) return true;
		}

		for (int i = 0; i < this->size; i++) {
			if (this->IsTheSame(i, 0, 3)) return true;
		}

		if (this->IsTheSame(0, this->size - 1, 4)) return true;
	}
	//Checking cell at index [0,0]
	else {
		int counter = this->size - this->range;
		
		for (int i = 0; i <= counter; i++) {
			for (int j = 0; j <= counter; j++) {
				if (this->IsTheSame(i, j, 1)) return true;
			}
		}

		for (int i = 0; i <= counter; i++) {
			for (int j = 0; j < this->size; j++) {
				if (this->IsTheSame(i, j, 2)) return true;
			}
		}

		for (int i = 0; i <this->size; i++) {
			for (int j = 0; j < counter; j++) {
				if (this->IsTheSame(i, j, 3)) return true;
			}
		}

		for (int i = 0; i <= counter; i++) {
			for (int j = this->range; j <= this->size - 1; j++) {
				if (this->IsTheSame(i, j, 4)) return true;
			}
		}
	}

	return false;
}