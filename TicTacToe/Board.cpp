#include "Board.h"

/*
	Konstruktor parametryczny klasy
*/

Board::Board(int size, int range) {
	this->c_range = range;
	this->b_size = size;

	this->bPointer = new char* [this->b_size];
	
	for (int i = 0; i < this->b_size; i++) {
		this->bPointer[i] = new char[this->b_size];
	}

	for (int i = 0; i < this->b_size; i++) {
		for (int j = 0; j < this->b_size; j++) {
			this->bPointer[i][j] = ' ';
		}
	}
}

/*
	Destruktor klasy
*/

Board::~Board() {
	for (int i = 0; i < this->b_size; i++) {
		delete[] this->bPointer[i];
	}
}

/*
	Metoda odpowiadaj¹ca za rysowanie planszy
	w terminalu
*/

void Board::Show() {
	for (int i = 0; i < this->b_size; i++) {
		for (int j = 0; j < this->b_size; j++) {
			std::cout << this->bPointer[i][j];
			if (j != this->b_size - 1) std::cout << "|";
		}
		if (i != this->b_size - 1) {
			std::cout << std::endl;
			for (int k = 0; k < this->b_size + this->b_size - 1; k++) {
				if (k % 2 == 1) std::cout << "+";
				else if (k % 2 == 0) std::cout << "-";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

/*
	Metoda sprawdzaj¹ca czy zosta³ jakikolwiek
	ruch do wykonania
*/

bool Board::IsMovieLeft() {
	int counter = 0;
	
	for (int i = 0; i < this->b_size; i++) {
		for (int j = 0; j < this->b_size; j++) {
			if (this->bPointer[i][j] == ' ') {
				counter++;
			}
		}
	}
	if (counter > 0) return true;
	else return false;
}

/*
	Metoda sprawdzaj¹ca czy któryœ z graczy umieœci³
	wyrywaj¹c¹ iloœæ znaków w rzêdzie.
	Zwraca 10 w przypadku zwyciêstwa X
	Zwraca -10 w przypadku zwyciêstwa O
	Zwraca 0 w ka¿dym innym przypadku
*/

int Board::CheckWinner() {
	if (this->c_range == this->b_size) {
		if (this->bPointer[0][0] != ' ') {
			for (int i = 1; i < this->b_size; i++) {
				if (this->bPointer[0][0] != this->bPointer[i][i]) {
					break;
				}
				else if (i == this->b_size - 1) {
					if (this->bPointer[0][0] == PLAYER) return 10;
					else if (this->bPointer[0][0] == COMPUTER) return -10;
				}
			}
		}

		for (int j = 0; j < this->b_size; j++) {
			if (this->bPointer[0][j] != ' ') {
				for (int i = 0; i < this->b_size; i++) {
					if (this->bPointer[0][j] != this->bPointer[i][j]) {
						break;
					}
					else if (i == this->b_size - 1) {
						if (this->bPointer[0][j] == PLAYER) return 10;
						else if (this->bPointer[0][j] == COMPUTER) return -10;
					}
				}
			}
		}

		for (int i = 0; i < this->b_size; i++) {
			if (this->bPointer[i][0] != ' ') {
				for (int j = 0; j < this->b_size; j++) {
					if (this->bPointer[i][0] != this->bPointer[i][j]) {
						break;
					}
					else if (j == this->b_size - 1) {
						if (this->bPointer[i][0] == PLAYER) return 10;
						else if (this->bPointer[i][0] == COMPUTER) return -10;
					}
				}
			}
		}

		if (this->bPointer[0][this->b_size - 1] != ' ') {
			int j = this->b_size - 1;
			for (int i = 0; i < this->b_size; i++) {
				if (this->bPointer[0][this->b_size - 1] != this->bPointer[i][j - i]) {
					break;
				}
				else if (i == this->b_size - 1) {
					if (this->bPointer[0][this->b_size - 1] == PLAYER) return 10;
					else if (this->bPointer[0][this->b_size - 1] == COMPUTER) return -10;
				}
			}
		}
	}

	else {
		int counter = this->b_size - this->c_range;

		for (int i = 0; i <= counter; i++) {
			for (int j = 0; j <= counter; j++) {
				if (this->bPointer[i][j] != ' ') {
					for (int k = 0; k < this->c_range; k++) {
						if (this->bPointer[i][j] != this->bPointer[i + k][j + k]) break;

						else if (k == this->c_range - 1) {
							if (this->bPointer[i][j] == PLAYER) return 10;
							else if (this->bPointer[i][j] == COMPUTER) return -10;
						}
					}
				}
			}
		}
		
		for (int i = 0; i <= counter; i++) {
			for (int j = 0; j < this->b_size; j++) {
				if (this->bPointer[i][j] != ' ') {
					for (int k = 0; k < this->c_range; k++) {
						if (this->bPointer[i][j] != this->bPointer[i + k][j]) break;

						else if (k == this->c_range - 1) {
							if (this->bPointer[i][j] == PLAYER) return 10;
							else if (this->bPointer[i][j] == COMPUTER) return -10;
						}
					}
				}
			}
		}

		for (int i = 0; i < this->b_size; i++) {
			for (int j = 0; j <= counter; j++) {
				if (this->bPointer[i][j] != ' ') {
					for (int k = 0; k < this->c_range; k++) {
						if (this->bPointer[i][j] != this->bPointer[i][j+k]) break;

						else if (k == this->c_range - 1) {
							if (this->bPointer[i][j] == PLAYER) return 10;
							else if (this->bPointer[i][j] == COMPUTER) return -10;
						}
					}
				}
			}
		}

		for (int i = 0; i <= counter; i++) {
			for (int j = this->b_size - 1; j >= counter; j--) {
				if (this->bPointer[i][j] != ' ') {
					for (int k = 0; k < this->c_range; k++) {
						if (this->bPointer[i][j] != this->bPointer[i + k][j - k]) break;

						else if (k == this->c_range - 1) {
							if (this->bPointer[i][j] == PLAYER) return 10;
							else if (this->bPointer[i][j] == COMPUTER) return -10;
						}
					}
				}
			}
		}
	}

	return 0;
}