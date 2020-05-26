#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

#include "Board.h"
#include "AI.h"
#include "Player.h"
#include "Interface_handling.h"

std::vector<int> T_2nd_move;
std::vector<int> T_1st_move;

/*
	Funkcja wychwytuj¹ca iloœæ czasu potrzebnego komputerowi na obliczenie
	ruchu dla ró¿nego rozmiaru tablicy i warunków rozpoczêcia gry.
*/

void Driver() {
	int size[9] = { 3,4,5,6,7,8,9,10,15 };
	
	for (int i = 0; i < 9; i++) {
		Board* pBrd = new Board(size[i], size[i]);
		Put(pBrd);
		
		auto start = std::chrono::steady_clock::now();
		CPut(pBrd);
		auto end = std::chrono::steady_clock::now();
		T_2nd_move.push_back((int)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
		std::cout << "DONE \n";
		pBrd->~Board();
	}

	for (int i = 0; i < 9; i++) {
		Board* pBrd = new Board(size[i], size[i]);
		auto start = std::chrono::steady_clock::now();
		CPut(pBrd);
		auto end = std::chrono::steady_clock::now();
		T_1st_move.push_back((int)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
		std::cout << "DONE \n";
		pBrd->~Board();
	}

	std::ofstream file("results.txt");
	file << "AI -> 2nd move \n";
	for (int i = 0; i < 9; i++) {
		file << T_2nd_move[i] << "\n";
	}

	file << "AI -> 1st move \n";
	for (int i = 0; i < 9; i++) {
		file << T_1st_move[i] << "\n";
	}
	file.close();
}


int main() {
	
	//Driver();
	int round = 1;
	bool PvC = false;
	bool isLeft = true;
	
	int choice = Menu();
	int size = Get_Size();
	int range = Get_Range();

	if (choice == 2) PvC = true;

	Board* pBrd = new Board(size, range);
	pBrd->Show();

	while (isLeft) {
		MoveStatement(round);

		if (round % 2 == 1) {
			Put(pBrd, round);
			pBrd->Show();
		}
		
		else if (round % 2 == 0) {
			if (PvC) CPut(pBrd);
			else Put(pBrd, round);
			pBrd->Show();
		}

		if (pBrd->CheckWinner() == 10 or pBrd->CheckWinner() == -10) {
			break;
		}
		
		isLeft = pBrd->IsMovieLeft();
		round++;
	}

	Statement(pBrd, round);
	pBrd->~Board();
	
}