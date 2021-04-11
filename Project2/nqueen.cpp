#include "nqueens.h"
#include <algorithm>

Nqueen::Nqueen(std::vector<std::vector<bool>> board):board {board}
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

bool Nqueen::solve() 
{
	std::stack<int> col;

	col.push(0);
	bool success = false;
	while (!success && !col.empty()) {
		if (isConflict()) {
			int row = col.top();
			col.pop();
			if (row == board.size() - 1) {
				col.pop();
				continue;
			}
			else {
				col.push(row + 1);
				continue;
			}
		}
		else
		{
			if (col.size() == board.size()) {
				success = true;
				continue;
			}
			col.push(0);
		}
	}
	return false;
}