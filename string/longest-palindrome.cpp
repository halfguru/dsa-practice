// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that
// can be built with those letters.
//
// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

#include <string>
#include <unordered_map>

using namespace std;

// property of palindrome: if character appears even number of times, it can be used in palindrome
// if character appears odd number of times, we can use the largest even number less than that frequency
// we can still include 1 single character of odd frequency in the center of the palindrome
// maximize length of palindrome, count how many characters have even frequencies and for odd frequencies,
// we add the largest even number and potentially 1 odd character
// time complexity: O(n)
// space complexity: O(128)
class Solution
{
public:
	int longestPalindrome(string s)
	{
		unordered_map<char, int> charCount;

		for (char c: s)
		{
			charCount[c]++;
		}

		int length = 0;
		bool hasOdd = false;

		for (const auto& entry: charCount)
		{
			// add length if frequency is even
			if (entry.second % 2 == 0)
			{
				length += entry.second;
			}
			// add largest event frequency - 1
			else
			{
				length += entry.second - 1;
				hasOdd = true;
			}
		}

		// we can add one more character in the palindrome
		if (hasOdd)
		{
			length += 1;
		}

		return length;
	}
};
