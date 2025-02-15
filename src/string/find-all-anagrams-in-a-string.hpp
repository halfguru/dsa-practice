// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer
// in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all
// the original letters exactly once.

#include <string>
#include <vector>

using namespace std;

// sliding window + frequency counter
// time complexity: O(n)
// space complexity: O(1)
class Solution_FindAllAnagramsInAString
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> result;

		if (s.length() < p.length())
		{
			return result;
		}

		vector<int> pCount(26, 0);
		vector<int> sCount(26, 0);
		int pLength = static_cast<int>(p.length());
		int sLength = static_cast<int>(s.length());

		// Step 1: count the frequency of each character in p and s
		for (int i = 0; i < pLength; ++i)
		{
			pCount[p[i] - 'a']++;
			sCount[s[i] - 'a']++;
		}

		// Step 2: slide window. Move window of size p across s
		for (int i = 0; i <= sLength - pLength; ++i)
		{
			// Step 3: Compare frequencies as the window slides over s.
			// if they match, current window is a an anagram of p
			if (pCount == sCount)
			{
				result.push_back(i);
			}

			// Step 4: update window by sliding it one character to the right
			if (i + pLength < sLength)
			{
				sCount[s[i] - 'a']--;
				sCount[s[i + pLength] - 'a']++;
			}
		}

		return result;
	}
};
