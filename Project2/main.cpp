// Participants: Gabriela Lopez, Andrew Thompson, Long Duong, Gia Minh Hoang, Duyen Tran and Lincoln Nguyen
// Date: 04-8-21
// Description: Chapter 7 Solution

#include<iostream>
#include <string>
#include "input.h"
#include "option1.h"
#include "option2.h"
#include "option3.h"
using namespace std;

//Precondition: being called
//Postcondition: starts the simple calculator program
void option1();
void option2();


//minh testing
double read_and_evaluate(istream& ins);
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);


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
			case 1: option1(); break;			// Simple Calculator *** not working with (1+1+1+1) 4 numbers together
			case 2: option2(); break;	// Translation of arithmetic expression
			case 3: option3(); break;	// n-Queens Problem
		}

		cout << '\n';
		system("pause");

	} while (true);

	return 0;

}

//page 365
void option1()
{
	using namespace Group1Option1;
	system("cls");
	cout << "\n 1> Simple Calculator\n";
	cout << string(100, char(196)) << '\n';

	double answer = 0.0;
	string expression = "";

	cout << " Type a fully parenthesized arithmetic expression: \n\n ";
	if (read_And_Evaluate(cin, expression, answer))
		if (answer == INFINITY)
			cout << "\nIt evaluates to inf.\n";
		else
		cout << "\n " << expression << " = " << answer << '\n';
}

void option2()
{
	char yes = 'y', no = 'n';
	do
	{
		arithmetic calc;
		string postfix;
		double number;
		bool valid = calc.findPostFix();
		if (valid)
		{
			postfix = calc.getPostFix();
			cout << "The translated postfix expression: " << postfix << '\n';
			calc.evaluate(postfix);
			number = calc.getNumber();
			cout << "The expression evaluates to " << number << '\n';
		}
		else
		{
			cout << "ERROR: unbalaced parentheses!";
		}
		char choice = toupper(inputChar("Run again?(Y or N): ", yes, no));
		if (choice == 'N')
			break;
	} while (true);
	return;
}

double read_and_evaluate(istream& ins)
{

	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';
	stack <double> numbers;
	stack <char> operations;
	double number;
	char symbol;

	// Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
	while (ins && ins.peek() != '\n')
	{
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL))
		{
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL)
		{
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHT_PARENTHESIS)
		{
			ins.ignore();
			evaluate_stack_tops(numbers, operations);
		}
		else
			ins.ignore();
	}
	return numbers.top();
}

void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
{
	double operand1, operand2;

	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();

	switch (operations.top())
	{
	case '+': numbers.push(operand1 + operand2); break;
	case '-': numbers.push(operand1 - operand2); break;
	case '*': numbers.push(operand1 * operand2); break;
	case '/': numbers.push(operand1 / operand2); break;
	}
	operations.pop();
}