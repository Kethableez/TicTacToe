#pragma once

#include <iostream>

#define PLAYER 'X'
#define OPPONENT 'O'

struct Move {
	int row;
	int col;
};

std::istream& operator >> (std::istream& stream, Move& move);
std::ostream& operator << (std::ostream& stream, Move& move);
