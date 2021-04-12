#include "nqueens.h"
#include <algorithm>
#include <array>

Nqueen::Nqueen(std::vector<std::vector<bool>> board):board {board}
{
}

bool Nqueen::isConflict() {
	std::vector<bool> possibilities;
	possibilities.reserve(10);
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

bool Nqueen::isConflictFast(int y, int x, std::vector<std::vector<bool>>& board) {
	std::array<bool, 8> possibilities;
	for (int i = 0; i < 8; i++) possibilities[i] = true;
	possibilities[0] = (isPathFree(x, y, TF(v + 1), TF(v)));
	possibilities[1] = (isPathFree(x, y, TF(v - 1), TF(v)));
	possibilities[2] = (isPathFree(x, y, TF(v), TF(v + 1)));
	possibilities[3] = (isPathFree(x, y, TF(v), TF(v - 1)));
	possibilities[4] = (isPathFree(x, y, TF(v + 1), TF(v + 1)));
	possibilities[5] = (isPathFree(x, y, TF(v - 1), TF(v - 1)));
	possibilities[6] = (isPathFree(x, y, TF(v + 1), TF(v - 1)));
	possibilities[7] = (isPathFree(x, y, TF(v - 1), TF(v + 1)));
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
		int row_ = col.top();
		int col_ = col.size() - 1;
		// std::cout << isConflictFast(col_, row_, board) << " " << col_ << " " << row_ << std::endl << *this << std::endl;
		
		bool isConflict_ = isConflictFast(col_, row_, board);
		if (!isConflict_ && col_ == board.size() - 1) return true;
		else if (!isConflict_ && col_ < board.size() - 1) {
			col.push(0);
			board[col.top()][col.size() - 1] = true;
		}
		else {
			while (!col.empty() && col.top() == board.size() - 1)
			{
				board[col.top()][col.size() - 1] = false;
				col.pop();
			}
			if (col.empty()) return false;
			else {
				board[col.top()][col.size() - 1] = false;
				col.top()++;
				board[col.top()][col.size() - 1] = true;
			}
		}
	}
	return false;
}