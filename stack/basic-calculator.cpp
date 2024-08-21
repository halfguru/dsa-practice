// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result
// of the evaluation.
//
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as
// eval().

#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		stack<int> st;
		int result = 0;
		int sign = 1;
		int number = 0;

		for (char c: s)
		{
			if (isdigit(c))
			{
				number = number * 10 + (c - '0');
			}
		}
	};
