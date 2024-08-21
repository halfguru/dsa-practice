// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
//
// The algorithm for myAtoi(string s) is as follows:
//
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither
// present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end
// of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain
// in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1
// should be rounded to 231 - 1.
//
// Return the integer as the final result.

#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string s)
	{
		int i = 0;
		int n = s.size();
		int sign = 1;
		int result = 0;


		// Step 1: skip whitespaces
		while (i < n && s[i] == ' ')
		{
			i++;
		}

		// Step 2: check for optional sign
		if (i < n && (s[i] == '+' || s[i] == '-'))
		{
			sign = (s[i] == '-') ? -1 : 1;
			i++;
		}

		// Step3: convert digits to integer
		while (i < n && isdigit(s[i]))
		{
			const int digit = s[i] - '0';

			// Step 4: check for overflow
			if (result > (INT_MAX - digit) / 10)
			{
				return (sign == 1) ? INT_MAX : INT_MIN;
			}

			result = result * 10 + digit;
			i++;
		}

		return result * sign;
	}
};
