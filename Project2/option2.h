#pragma once
#include <cctype> // Provides isdigit
#include <cstdlib> // Provides EXIT_SUCCESS
#include <cstring> // Provides strchr
#include <iostream> // Provides cout, cin, peek, ignore
#include <stack> // Provides the stack template class
#include <string>

using namespace std;

class arithmetic
{
private:
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';
	stack <double> numbers;
	stack <char> operations;
	char symbol;
	string postfix;
	double number;
public:
	arithmetic();
	string getPostFix() const;
	double getNumber() const;
	bool findPostFix();
	void evaluate(string expression);
};
arithmetic::arithmetic()
{
	postfix = "";
	number = 0.0;

}
int precedence(char operat);
bool isBalancedParenthesis(const string& expression);
string arithmetic::getPostFix() const
{
	return postfix;
}
double arithmetic::getNumber() const
{
	return number;
}
bool arithmetic::findPostFix()
{
	stack<char> operators;
	operators.push('|');
	string infix;
	char holder;
	cout << "\n Enter an infix expression: ";
	cin >> infix;
	bool valid = isBalancedParenthesis(infix);
	if (!valid)
	{
		return valid;
	}
	cout << "\nThe entered infix expression: " << infix << "\n";
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] >= '0' && infix[i] <= '9')
			postfix += infix[i];
		else if (infix[i] >= 'a' && infix[i] <= 'z')
			postfix += infix[i];
		else if (infix[i] >= 'A' && infix[i] <= 'Z')
			postfix += infix[i];
		else if (infix[i] == '(')
			operators.push('(');

		else if (infix[i] == ')')
		{
			while (operators.top() != '(' && operators.top() != '|')
			{
				holder = operators.top();
				operators.pop();
				postfix += holder;
			}
			if (operators.top() == '(')
			{
				holder = operators.top();
				operators.pop();
			}
		}
		else
		{
			while (operators.top() != '|' && precedence(infix[i]) <= precedence(operators.top()))
			{
				holder = operators.top();
				operators.pop();
				postfix += holder;
			}
			operators.push(infix[i]);
		}

	}
	while (operators.top() != '|')
	{
		holder = operators.top();
		operators.pop();
		postfix += holder;
	}
	return valid;
}

void arithmetic::evaluate(string expression)
{
	stack <double> operands;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
			operands.push(expression[i] - '0');
		else if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
		{
			double holder;
			cout << "\n please enter a number to replace the character '" << expression[i] << "' with";
			holder = inputDouble(":");
			operands.push(holder);
		}
		else
		{
			double a, b;
			a = operands.top();
			operands.pop();

			b = operands.top();
			operands.pop();

			if (expression[i] == '+')
			{
				operands.push(b + a);
			}
			else if (expression[i] == '-')
			{
				operands.push(b - a);
			}
			else if (expression[i] == '*')
			{
				operands.push(b * a);
			}
			else if (expression[i] == '/')
			{
				operands.push(b / a);
			}
			else if (expression[i] == '^')
			{
				operands.push(pow(b, a));
			}
		}

	}
	number = operands.top();
}
int precedence(char operat)
{
	switch (operat)
	{
	case '+':  return 1; break;
	case '-':  return 1; break;
	case '*':  return 2; break;
	case '/':  return 2; break;
	case '^':  return 3; break;
	default:  return-1; break;
	}
}
bool isBalancedParenthesis(const string& expression)
{
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	int parenthesisCounter = 0;
	stack<char> store;
	char next;

	bool failed = false;

	for (unsigned int i = 0; !failed && (i < expression.length()); i++)
	{
		next = expression[i];
		if (next == LEFT_PARENTHESIS)
		{
			parenthesisCounter++;
			store.push(next);
		}
		else if ((next == RIGHT_PARENTHESIS) && (!store.empty()))
		{
			parenthesisCounter++;
			store.pop();
		}
		else if ((next == RIGHT_PARENTHESIS) && (store.empty()))
		{
			parenthesisCounter++;
			failed = true;
		}
	}
	if (parenthesisCounter == 0)
		return true;
	else
		return (store.empty() && !failed);
}