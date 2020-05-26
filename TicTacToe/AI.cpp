#include "AI.h"


void CPut(Board* pBoard) {
	Move cMove;
	cMove = bestMove(pBoard);

	pBoard->bPointer[cMove.row][cMove.col] = COMPUTER;
}

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
					
					pB->bPointer[i][j] = COMPUTER;
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

Move bestMove(Board* pB) {
	int bestVal = INF;

	Move best;
	best.row = -1;
	best.col = -1;

	int depth = 1.4 * pB->b_size;

	for (int i = 0; i < pB->b_size; i++) {
		for (int j = 0; j < pB->b_size; j++) {
			if (pB->bPointer[i][j] == ' ') {
				
				pB->bPointer[i][j] = COMPUTER;
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