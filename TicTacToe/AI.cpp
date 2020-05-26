#include "AI.h"

/*
	Funkcja umieszczaj¹ca znak w konkretnym
	miejscu na planszy
*/

void CPut(Board* pBoard) {
	Move cMove;
	cMove = bestMove(pBoard);

	pBoard->bPointer[cMove.row][cMove.col] = OPPONENT;
}

/*
	Algorytm minimax s³u¿¹cy do znalezienia naljepszego
	mo¿liwego ruchu przy zadanej g³êbokoœci i wykorzystuj¹cy
	obciêcia Alfa-Beta.
*/

int minimax(Board* pB, int depth, bool isMaximizing, int alpha, int beta) {
	int result = pB->CheckWinner();
	
	if (result == 10) {
		return result;
	}

	if (result == -10) {
		return result;
	}

	if (pB->IsMovieLeft() == false or depth == 0) {
		return 0;
	}

	if (isMaximizing) {
		int best = nINF;
		for (int i = 0; i < pB->b_size; i++) {
			for (int j = 0; j < pB->b_size; j++) {
				if (pB->bPointer[i][j] == ' ') {
					
					pB->bPointer[i][j] = PLAYER;
					int score = minimax(pB, depth - 1, !isMaximizing, alpha, beta);
					pB->bPointer[i][j] = ' ';
					
					best = std::max(score, best);
					alpha = std::max(alpha, score);
					if (beta <= alpha) break;
					
				}
			}
		}
		return best;
	}

	else {
		int best = INF;

		for (int i = 0; i < pB->b_size; i++) {
			for (int j = 0; j < pB->b_size; j++) {
				if (pB->bPointer[i][j] == ' ') {
					
					pB->bPointer[i][j] = OPPONENT;
					int score = minimax(pB, depth - 1, !isMaximizing, alpha, beta);
					pB->bPointer[i][j] = ' ';
					
					best = std::min(score, best);
					alpha = std::min(alpha, score);
					if (beta <= alpha) break;
				}
			}
		}
		return best;
	}
}

/*
	Funkcja szukaj¹ca najlepszego mo¿liwego ruchu w danym
	etapie rozgrywki
*/

Move bestMove(Board* pB) {
	int bestVal = INF;

	Move best;
	best.row = -1;
	best.col = -1;

	int depth = _Depth(pB);

	for (int i = 0; i < pB->b_size; i++) {
		for (int j = 0; j < pB->b_size; j++) {
			if (pB->bPointer[i][j] == ' ') {
				
				pB->bPointer[i][j] = OPPONENT;
				int move = minimax(pB, depth, true, nINF, INF);
				pB->bPointer[i][j] = ' ';

				if (move < bestVal) {
					bestVal = move;
					best.row = i;
					best.col = j;
				}
			}
		}
	}

	return best;
}

/*
	Funkcja zwracaj¹ca g³êbokoœæ szukania dla ró¿nego rozmiaru
	planszy.
*/

int _Depth(Board* pBrd) {
	int size = pBrd->b_size;

	if (size == 3) return 9;
	else if (size >= 4 and size < 7) return (9 - size + 1);
	else if (size >= 7 and size < 10) return 3;
	else return 2;

}