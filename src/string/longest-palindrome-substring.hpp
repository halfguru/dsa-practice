// Given a string s, return the longest palindromic substring in s.

#include <string>

using namespace std;

// expand around center
// consider every character in the string as potential center of palindrome
// we then expan outwards from this center to check how far we can go while maintaining
// palindrome property
// time complexity: O(n^2)
// space complexity: O(1)
class Solution_LongestPalindromeInSubstring
{
public:
	string longestPalindrome(string s)
	{
		if (s.empty())
		{
			return "";
		}

		int start = 0;
		int maxLength = 1;

		for (int i = 0; i < s.length(); ++i)
		{
			// odd length palindromes
			expand(i, i, start, maxLength, s);
			// even length palindromes
			expand(i, i + 1, start, maxLength, s);
		}

		return s.substr(start, maxLength);
	}

	void expand(int left, int right, int& start, int& maxLength, const string& s)
	{
		while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}

		const int length = right - left - 1;
		if (length > maxLength)
		{
			start = left + 1;
			maxLength = length;
		}
	}
};
