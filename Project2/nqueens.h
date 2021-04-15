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

		//preconditions:a 2d vector of integers
		//postconditions: creates a Nqueens object with its board as the passed in vector
		Nqueen(std::vector<std::vector<int>> board);
		//preconditions: a Nqueens object, and a first move
		//postcondtions: returns true when a solution is found and false when it is not
		bool solve();
		//preconditions: an Nqueens object, and solve is running
		//postconditions: returns true if a generated queen conflicts with another, false if not	
		bool isConflict();
		//preconditions: an Nqueens object, and solve is running
		//postconditions: returns true if a generated queen conflicts with another, false if not, but faster
		bool isConflictFast(int col, int row, std::vector<std::vector<int>>& board);
		//preconditions: an nqueens object
		//postconditions: returns true if the path is free, false if not
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
		//preconditions: a Nqueens object
		//postconditions: displays the board, and locations of all present queens
		friend ostream& operator << (ostream& outs, const Nqueen& obj);

	private:
		std::vector<std::vector<int>> board;
};
