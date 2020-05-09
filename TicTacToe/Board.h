#pragma once

#define MIN_BOARD 3
#define MIN_RANGE 3

#include <iostream>
#include <string>

class Board {
public:
	int size;
	int range;
	char** bPointer;
	std::string* mPointer;

	Board(int nsize, int nrange);
	~Board();

	void Show();
	void Put(std::string move, int round);
	bool CheckBoard();

	bool IsAlready(std::string move);
	bool IsTheSame(int r1, int c1, int c_case);

	std::string GetMove();
};