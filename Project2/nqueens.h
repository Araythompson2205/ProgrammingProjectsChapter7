// Participants: Andrew Thompson, Long Duong and Gabriela Lopez
// Date: 04-11-21
// Description: nqueen header

#pragma once

#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#define TF(e) [](const int& v) {return e; }

class Nqueen
{
	public:
		static const int Q = 1;
		static const int NO_Q = 0;
		static const int INFLUENCE = -1;

		// accepts 2d array with queen = true;
		Nqueen(std::vector<std::vector<int>> board);
		// finds where to place queens to win
		bool solve();

		// determines if there is a queen already
		bool isConflict();

		// fastest way to determine if there is a queen already
		bool isConflictFast(int col, int row, std::vector<std::vector<int>>& board);


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
				if (board[x][y] == Q)
					return false;
			}
			return true;
		}

		friend ostream& operator << (ostream& outs, const Nqueen& obj)
		{
			for (int i = 0; i < obj.board.size(); i++) {
				for (int j = 0; j < obj.board.size(); j++) {
					outs << '|';
					if (obj.board[j][i] == Nqueen::NO_Q)
						outs << '_';
					else if (obj.board[j][i] == Nqueen::Q)
						outs << 'Q';

				}
				outs << '|' << '\n';
			}
			return outs;
		}

	private:
		std::vector<std::vector<int>> board;
};
