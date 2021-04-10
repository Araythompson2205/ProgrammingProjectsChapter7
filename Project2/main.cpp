#include<iostream>
#include <string>
#include "input.h"
#include "option1.h"
using namespace std;

// driver function/program
int main()
{
	do
	{
		system("cls");
		cout << "\n\t\t  CMPR131 Chapter 7: Applications using Stacks by ";
		cout << "\n\t\t" << string(70, char(205));
		cout << "\n\t\t  1> Simple Calculator (problem 9, pg 391)";
		cout << "\n\t\t  2> Translation of arithmetic expression (problem 10, pg 391)";
		cout << "\n\t\t  3> n-Queens Problem (problem 11, pg 391-292)";
		cout << "\n\t\t" << string(70, char(196));
		cout << "\n\t\t  0> Exit";
		cout << "\n\t\t" << string(70, char(205)) << '\n';
		int option = inputInteger("\t\t  Option: ", 0, 3);

		switch (option)
		{
			case 0: exit(1);
			case 1: option1(); break;			// Simple Calculator
			case 2: cout << "\nTBD\n"; break;	// Translation of arithmetic expression
			case 3: cout << "\nTBD\n"; break;	// n-Queens Problem
		}

		cout << '\n';
		system("pause");

	} while (true);

	return 0;

}