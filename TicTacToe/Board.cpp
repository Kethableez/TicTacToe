#include "Board.h"

Board::Board(int nsize) {
	this->size = nsize;
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
		std::cout << "Value off table. Try again. \n Size of gameboard is " << this->size << std::endl;
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