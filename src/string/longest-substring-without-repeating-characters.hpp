// Given a string s, find the length of the longest substring without repeating characters.

#include <string>
#include <unordered_map>

using namespace std;

// sliding window + hash map store last index of each character we encounter
// time complexity: O(n)
// space complexity: O(min(m, n)) where n is size of string and m is size of character set
class Solution_LongestSubstringWithoutRepeatingCharacters
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> charIndex;
		int maxLength = 0;
		int left = 0;
		const int strLen = static_cast<int>(s.length());

		for (int right = 0; right < strLen; ++right)
		{
			const char currentChar = s[right];

			// if character is found in map and index is within current window
			if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left)
			{
				left = charIndex[currentChar] + 1;
			}

			// update last seen index of current character
			charIndex[currentChar] = right;

			// length of current window
			maxLength = max(maxLength, right - left + 1);
		}

		return maxLength;
	}
};
