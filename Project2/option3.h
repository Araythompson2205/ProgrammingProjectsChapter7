#pragma once
#include <vector>
#include <iostream>
#include"input.h"
#include "nqueens.h"
using namespace std;

void option3();

void option3()
{
	bool jim = true;
	int Q = 1;
	int NO_Q = 0;
	int INFLUENCE = -1;
	
	int dimensions = inputInteger("Enter the board's dimensions ", 0,100);
	vector<vector<int>> b1(dimensions, vector<int>(dimensions));
	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {
			b1[i][j] = NO_Q;
		}
	}
	b1[0][0] = Q;
	Nqueen q1(b1);

	bool found = q1.solve();
	if (!found) cout << "No solution" << endl;
	else cout << q1;
}
