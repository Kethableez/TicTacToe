#pragma once

#include <iostream>
#include <string>

class Board {
public:
	int size;
	char** bPointer;
	std::string* mPointer;

	Board(int nsize);
	void Show();
	void Put(std::string move, int round);
	std::string GetMove();
	bool IsAlready(std::string move);
	~Board();
};