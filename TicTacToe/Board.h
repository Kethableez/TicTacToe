#pragma once

#define MIN_BOARD 3
#define MIN_RANGE 3

#include <iostream>
#include <string>

#include "Move.h"

class Board {
public:
	char** bPointer;
	int b_size;
	int c_range;

	Board(int size, int range);
	~Board();

	void Show();
	int CheckWinner();
	
	bool IsMovieLeft();
};