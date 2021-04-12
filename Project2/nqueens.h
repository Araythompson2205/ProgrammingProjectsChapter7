#pragma once

#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#define TF(e) [](const int& v) {return e; }

class Nqueen {
public:
	// accepts 2d array with queen = true;
	Nqueen(std::vector<std::vector<bool>> board);

	bool solve();
	bool isConflict();
	bool isConflictFast(int col, int row, std::vector<std::vector<bool>>& board);
	template <typename Xtf, typename Ytf>
	inline bool isPathFree(int x, int y, Xtf&& xtf, Ytf&& ytf)
	{
		int size = board.size();
		while (x >= 0 && x < size && y >= 0 && y < size)
		{
			x = xtf(x);
			y = ytf(y);
			if (x >= size || y >= size || x < 0 || y < 0)
				break;
			if (board[x][y]) 
				return false;
		}
		return true;
	}
	friend ostream& operator << (ostream& outs, const Nqueen& obj)
	{
		for (int i = 0; i < obj.board.size(); i++) {
			for (int j = 0; j <obj.board.size(); j++) {
				outs << '|';
				if (obj.board[j][i] == false)
					outs << '_';
				else if (obj.board[j][i] == true)
					outs << 'Q';
				else
					outs << "Error!";

			}
			outs << '|' << '\n';
		}
		return outs;
	}

private:
	std::vector<std::vector<bool>> board;
};
