#pragma once

#include <algorithm>
#include "Move.h"
#include "Board.h"

#define INF 10000000
#define nINF -10000000

int minimax(Board* pB, int depth, bool isMaximizing);
Move bestMove(Board* pB);

void CPut(Board* pBoard);

