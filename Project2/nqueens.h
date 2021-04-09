#pragma once

#include <vector>
#include <stack>

#define TF(e) [](int v) {return e; }

class Nqueen {
public:
	// accepts 2d array with queen = true;
	Nqueen(std::vector<std::vector<bool>> board);

	bool solve();
	bool isConflict();
	template <typename Xtf, typename Ytf>
	bool isPathFree(int x, int y, Xtf&&, Ytf&&)
	{
		while (x >= 0 && x < board.size()
			&& y >= 0 && y < board[0].size())
		{
			x = Xtf(x);
			y = Ytf(y);
			if (board[x][y]) return false;
		}
		return true;
	}

private:
	std::vector<std::vector<bool>> board;
};
