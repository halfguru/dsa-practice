// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all
// the original letters exactly once.

#include <string>
#include <unordered_map>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		std::unordered_map<char, int> count;

		for (const auto& char_s: s)
		{
			count[char_s]++;
		}
		for (const auto& char_x: t)
		{
			count[char_x]--;
		}

		for (const auto& x: count)
		{
			if (x.second != 0)
			{
				return false;
			}
		}
		return true;
	}
};
