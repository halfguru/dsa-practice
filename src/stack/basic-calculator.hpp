// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result
// of the evaluation.
//
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as
// eval().

#include <stack>
#include <string>

using namespace std;

// if number, construct number
// if (, push current result and sign on stack
// if ), compute current result and add result from stack
// 1 + (2 + 3), st.push(1)
// time complexity: O(n)
// space complexity: O(n)
class Solution_BasicCalculator
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
			else if (c == '+')
			{
				result += sign * number;
				number = 0;
				sign = 1;
			}
			else if (c == '-')
			{
				result += sign * number;
				number = 0;
				sign = -1;
			}
			else if (c == '(')
			{
				st.push(result);
				st.push(sign);
				result = 0;
				sign = 1;
			}
			else if (c == ')')
			{
				result += sign * number;
				number = 0;
				result *= st.top();
				st.pop();
				result += st.top();
				st.pop();
			}
		}

		result += sign * number;
		return result;
	}
};
