#include "nqueens.h"
#include <algorithm>

Nqueen::Nqueen(std::vector<std::vector<bool>> board)
	: board {board}
{
}

bool Nqueen::isConflict() {
	std::vector<bool> possibilities;
	for (const auto& col : board) {
		if (
			std::all_of(col.begin(), col.end(), [](bool e) {return !e;})
			) continue;
		int y = std::distance(col.begin(), std::find(col.begin(), col.end(), true));
		int x = &col - &board[0];

		possibilities.push_back(isPathFree(x, y, TF(v + 1), TF(v)));
		possibilities.push_back(isPathFree(x, y, TF(v - 1), TF(v)));
		possibilities.push_back(isPathFree(x, y, TF(v), TF(v + 1)));
		possibilities.push_back(isPathFree(x, y, TF(v), TF(v - 1)));
		possibilities.push_back(isPathFree(x, y, TF(v + 1), TF(v + 1)));
		possibilities.push_back(isPathFree(x, y, TF(v - 1), TF(v - 1)));
		possibilities.push_back(isPathFree(x, y, TF(v + 1), TF(v - 1)));
		possibilities.push_back(isPathFree(x, y, TF(v - 1), TF(v + 1)));
	}
	return std::any_of(
		possibilities.begin(), possibilities.end(),
		[](bool e) {return !e;}
	);
}

bool Nqueen::solve() {
	std::stack<int> col;

	bool stop = false;
	while (!stop && !col.empty()) {
	}
}