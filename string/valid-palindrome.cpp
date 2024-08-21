// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
// non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and
// numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.
#include <string>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution
{
public:
	bool isPalindrome(string s)
	{
		int start = 0;
		int end = s.size() - 1;

		while (start <= end)
		{
			if (!std::isalnum(s[start]))
			{
				start++;
				continue;
			}
			if (!std::isalnum(s[end]))
			{
				end--;
				continue;
			}
			if (std::tolower(s[start]) != std::tolower(s[end]))
			{
				return false;
			}
			else
			{
				start++;
				end--;
			}
		}
		return true;
	}
};
