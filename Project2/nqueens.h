#pragma once

#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#define TF(e) [](int v) {return e; }

class Nqueen {
public:
	// accepts 2d array with queen = true;
	Nqueen(std::vector<std::vector<bool>> board);

	bool solve();
	bool isConflict();
	template <typename Xtf, typename Ytf>
	bool isPathFree(int x, int y, Xtf&& xtf, Ytf&& ytf)
	{
		while (x >= 0 && x < board.size() && y >= 0 && y < board.size())
		{
			x = xtf(x);
			y = ytf(y);
			if (x >= board.size() || y >= board.size())
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
				if (obj.board[i][j] == false)
					outs << '_';
				else if (obj.board[i][j] == true)
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
