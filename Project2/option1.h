// Participants: Prof. Quach (Textbook)
// Date: 04-8-21
// Description: simple calculator header

#pragma once
#include <iostream>
#include <string>
#include <stack> // STL
using namespace std;

namespace Group1Option1
{
	//Precondition : an expression(string)
	//PostCondition: A true return value indicates that the parentheses in the given expression
	// are balanced. Otherwise the return value is false.
	bool is_Balanced_Parenthesis(const string& expression);

	// Precondition: The top of the operations stack contains +, -, *, or /, and the numbers stack
	// contains at least two numbers.
	// Postcondition: The top two numbers have been popped from the numbers stack, and the top
	// operation has been popped from the operations stack. The two numbers have been
	// combined using the operation (with the second number popped as the left operand). The
	// result of the operation has then been pushed back onto the numbers stack.
	void evaluate_Stack_Tops(stack<double>& operands, stack<char>& operators);

	// Precondition: The next line of characters in the istream ins is a fully parenthesized
	// expression formed from non-negative numbers and the four operations +, -, *, and /.
	// Postcondition: A line has been read from the istream ins, and this line has been evaluated
	// as an arithmetic expression. The value of the expression has been returned by the function.
	bool read_And_Evaluate(istream& ins, string& expression, double& answer);
};