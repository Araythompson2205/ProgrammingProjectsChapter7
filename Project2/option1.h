#pragma once
#include <iostream>
#include <string>
#include <stack> // STL
using namespace std;

//Precondition : page 357
//PostCondition: page 357
bool is_Balanced_Parenthesis(const string& expression)
{
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';

	stack<char> store;
	char next;

	bool failed = false;

	for (unsigned int i = 0; !failed && i < expression.length(); i++)
	{
		next = expression[i];
		if (next == LEFT_PARENTHESIS)
			store.push(next);
		else if (next == RIGHT_PARENTHESIS && !store.empty())
			store.pop();
		else if (next == RIGHT_PARENTHESIS && store.empty())
			failed =  true;
	}

	return (store.empty() && !failed);

}

//Precondition : page 364
//PostCondition: page 364
void evaluate_Stack_Tops(stack<double>& operands, stack<char>& operators)
{
	double operand2 = operands.top();
	operands.pop();

	double operand1 = operands.top();
	operands.pop();

	switch (operators.top())
	{
	case '+':
		operands.push(operand1 + operand2); break;
	case '-':
		operands.push(operand1 - operand2); break;
	case '*':
		operands.push(operand1 * operand2); break;
	case '/':
		operands.push(operand1 / operand2); break;
	case '^':
		operands.push(pow(operand1, operand2)); break;
	}

	operators.pop();
}

//Precondition : page 364
//PostCondition: page 364
bool read_And_Evaluate(istream& ins, string& expression, double& answer)
{
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';

	stack<double> operands;
	stack<char> operators;

	double number;
	char symbol;

	bool error = false;
	expression = "";
	int errorCount = 0;
	
	while (ins && ins.peek() != '\n')
	{
		errorCount++;
		ins >> ws;
		if (isspace(ins.peek()))
			ins.ignore();
		else if (ins.peek() == LEFT_PARENTHESIS)
		{
			expression += '(';
			ins.ignore();
		}
		else if (isdigit(ins.peek()) || ins.peek() == DECIMAL)
		{
			ins >> number;
			expression += to_string(number);
			operands.push(number);
		}
		else if (strchr("+-*/^", ins.peek()) != NULL)
		{
			ins >> symbol;
			expression += symbol;
			operators.push(symbol);
		}
		else if (ins.peek() == RIGHT_PARENTHESIS)
		{
			expression += ')';
			ins.ignore();
			evaluate_Stack_Tops(operands, operators);
		}
		else
		{
			ins.ignore();
			error = true;
		}
	}

	if (!is_Balanced_Parenthesis(expression))
	{
		cout << "\n ERROR: Parentheses don't match.\n";
		return false;
	}
	else if (!error)
	{
		if (!operands.empty())
		{
			evaluate_Stack_Tops(operands, operators);
			answer = operands.top();
			return true;
		}
	}
	else
	{
		cout << " ERROR: Invalid arithmetic expression.\n";
		answer = 0.0;
		return false;
	}
}

//page 365
void option1()
{
	system("cls");
	cout << "\n 1> Simple Calculator\n";
	cout << string(100, char(196)) << '\n';

	double answer = 0.0;
	string expression = "";

	cout << " Type a fully parenthesized arithmetic expression: \n\n ";
	if (read_And_Evaluate(cin, expression, answer))
		cout << "\n " << expression << " = " << answer << '\n';
}