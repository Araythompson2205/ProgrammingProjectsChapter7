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

	
	int dimensions = inputInteger("Enter the board's dimensions ", 0,100);
	vector<vector<bool>> b1(dimensions, vector<bool>(dimensions));
	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {
			b1[i][j] = false;
		}
	}
	b1[0][0] = true;
	Nqueen q1(b1);

	q1.solve();
	cout << q1;
}
