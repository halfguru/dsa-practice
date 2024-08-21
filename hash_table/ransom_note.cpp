// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from
// magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.

#include <string>
#include <unordered_map>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		unordered_map<char, int> freq;

		for (const auto& c: magazine)
		{
			freq[c]++;
		}

		for (int i = 0; i < ransomNote.length(); ++i)
		{
			if (freq[ransomNote[i]] == 0)
			{
				return false;
			}
			freq[ransomNote[i]]--;
		}

		return true;
	}
};
