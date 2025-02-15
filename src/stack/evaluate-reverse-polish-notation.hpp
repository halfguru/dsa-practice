// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//
// Evaluate the expression. Return an integer that represents the value of the expression.
//
// Note that:
//
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include <stack>
#include <string>
#include <vector>

using namespace std;

// traverse tokens.
// if token is number push in stack.
// if token is operator, pop 2 elements from stack then apply operator then push result on stack
// time complexity: O(n)
// space complexity: O(n)
class Solution_EvaluateReversePolishNotation
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		for (const auto& token: tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				const int b = st.top();
				st.pop();
				const int a = st.top();
				st.pop();
				if (token == "+")
				{
					st.push(a + b);
				}
				if (token == "-")
				{
					st.push(a - b);
				}
				if (token == "*")
				{
					st.push(a * b);
				}
				if (token == "/")
				{
					st.push(a / b);
				}
			}
			else
			{
				// convert string to integer and push to stack
				st.push(stoi(token));
			}
		}

		return st.top();
	}
};
