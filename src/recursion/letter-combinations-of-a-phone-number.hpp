// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could
// represent. Return the answer in any order.
//
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any
// letters.

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// backtracking
// time: O(4^n) where n is length of input string digits. Because each digit maps up to 4 letters, possible combinations
// is 4^n
// space: O(4^n)
class Solution_LetterCombinationOfAPhoneNumber
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> result;
		if (digits.empty())
		{
			return result;
		}

		string current;
		backtrack(digits, result, current, 0);
		return result;
	}

	void backtrack(const string& digits, vector<string>& result, string& current, int index)
	{
		if (index == digits.size())
		{
			result.push_back(current);
			return;
		}

		const char digit = digits[index];
		const string& letters = phone.at(digit);

		for (const char& letter: letters)
		{
			current.push_back(letter);
			backtrack(digits, result, current, index + 1);
			current.pop_back(); // backtrack
		}
	}

private:
	const unordered_map<char, string> phone
		= {{'2', "abc"},
		   {'3', "def"},
		   {'4', "ghi"},
		   {'5', "jkl"},
		   {'6', "mno"},
		   {'7', "pqrs"},
		   {'8', "tuv"},
		   {'9', "wxyz"}};
};
