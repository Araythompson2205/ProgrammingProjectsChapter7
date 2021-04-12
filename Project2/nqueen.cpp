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
	while (!col.empty()) {
		std::cout << isConflict() << std::endl
			<< *this << std::endl;
		int row_ = col.top();
		int col_ = col.size() - 1;

		if (!isConflict() && col_ == board.size() - 1) return true;
		else if (!isConflict() && col_ < board.size() - 1) {
			col.push(0);
			board[col.top()][col.size() - 1] = true;
		}
		else {
			board[col.top()][col.size() - 1] = false;
			col.pop();
			if (row_ + 1 == board.size())
			{
				if (col.empty()) return false;
				do {
					board[col.top()][col.size() - 1] = false;
					col.pop();
				} while (!col.empty() && col.top() == board.size() - 1);
				if (col.empty()) return false;
				else {
					board[col.top()][col.size() - 1] = false;
					int prev = col.top();
					col.pop();
					col.push(prev + 1);
					board[col.top()][col.size() - 1] = true;
				}
				continue;
			}
			col.push(row_ + 1);
			board[col.top()][col.size() - 1] = true;
		}
	}
	return false;
}