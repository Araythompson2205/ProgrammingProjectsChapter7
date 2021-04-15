#pragma once
#include <cctype> // Provides isdigit
#include <cstdlib> // Provides EXIT_SUCCESS
#include <cstring> // Provides strchr
#include <iostream> // Provides cout, cin, peek, ignore
#include <stack> // Provides the stack template class

using namespace std;

//class arithmetic
//{
//private:
//	const char DECIMAL = '.';
//	const char RIGHT_PARENTHESIS = ')';
//	stack <double> numbers;
//	stack <char> operations;
//	double number;
//	char symbol;
//public:
//	double read_and_evaluate(istream& ins);
//	void evaluate_stack_tops(/*stack<double>& numbers, stack<char>& operations*/);
//	void display();
//};
//
//double arithmetic::read_and_evaluate(istream& ins)
//{
//	// Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
//	while (ins && ins.peek() != '\n')
//	{
//		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL))
//		{
//			ins >> number;
//			numbers.push(number);
//		}
//		else if (strchr("+-*/", ins.peek()) != NULL)
//		{
//			ins >> symbol;
//			operations.push(symbol);
//		}
//		else if (ins.peek() == RIGHT_PARENTHESIS)
//		{
//			ins.ignore();
//			evaluate_stack_tops(/*numbers, operations*/);
//		}
//		else
//			ins.ignore();
//	}
//	return numbers.top();
//}
//
//// Library facilities used: stack
//void arithmetic::evaluate_stack_tops(/*stack<double>& numbers, stack<char>& operations*/)
//{
//	double operand1, operand2;
//
//	operand2 = numbers.top();
//	numbers.pop();
//	operand1 = numbers.top();
//	numbers.pop();
//
//	switch (operations.top())
//	{
//	case '+': numbers.push(operand1 + operand2); break;
//	case '-': numbers.push(operand1 - operand2); break;
//	case '*': numbers.push(operand1 * operand2); break;
//	case '/': numbers.push(operand1 / operand2); break;
//	}
//	operations.pop();
//}
//
////void arithmetic::display(istream& ins)
////{
////	while (ins && ins.peek() != '\n')
////	{
////		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL))
////		{
////			ins >> number;
////			numbers.push(number);
////		}
////		else if (strchr("+-*/", ins.peek()) != NULL)
////		{
////			ins >> symbol;
////			operations.push(symbol);
////		}
////		else if (ins.peek() == RIGHT_PARENTHESIS)
////		{
////			ins.ignore();
////			evaluate_stack_tops(/*numbers, operations*/);
////		}
////		else
////			ins.ignore();
////	}
////	return numbers.top();
////}

bool IsOperation(char c);
int precedence(char c);
string ConvertInfixToPostfix(string infix, stack<char> hold);

string ConvertInfixToPostfix(string infix, stack<char> hold)
{
	string postfix;

	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			hold.push(infix[i]);
		}
		else if ((infix[i] >= 'a' && infix[i] <= 'z')|| (infix[i] >= 'A' && infix[i] <= 'Z')|| (infix[i] >= '0' && infix[i] <= '9'))
		{
			postfix += infix[i];
		}
		else if (IsOperation(infix[i]))
		{
			if (hold.empty())
			{
				hold.push(infix[i]);
			}
			else
			{
				if (precedence(infix[i]) <= precedence(hold.top()))
				{
					hold.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(hold.top())) && (infix[i] == '^'))
				{
					hold.push(infix[i]);
				}

				{
					while ((!hold.empty()) && (precedence(hold.top() >= precedence(infix[i]))))
					{
						char temp = hold.top();
						postfix += temp;
						hold.pop();
					}
					hold.push(infix[i]);
				}
			}
		}
		else if (infix[i] == ')')
		{
			while ((hold.top() != '(') || (!hold.empty()));
			{
				char temp = hold.top();
				postfix += temp;
				hold.pop();
			}
		}
	}
	while (!hold.empty())
	{
		if (hold.top() == '(')
		{
			hold.pop();
		}
		postfix += hold.top();
		hold.pop();
	}
	return postfix;
}


bool IsOperation(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-' || c == '^')
		return true;
	else
		return false;
}


int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;

}
