// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations
// of candidates where the chosen numbers sum to target. You may return the combinations in any order.
//
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
//  of at least one of the chosen numbers is different.
//
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150
// combinations for the given input.

#include <algorithm>
#include <vector>

using namespace std;

// Backtracking
// Recursive function to explore all combinations
// each step, subtract current candidate from target and make recursive call with updated target
// if target = 0, combination is valid, add to result
// if target < 0, backtracka and try next candidate
class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> currentCombination;
		backtrack(candidates, target, currentCombination, result, 0);
		return result;
	}

	void backtrack(
		const vector<int>& candidates,
		int target,
		vector<int>& currentCombination,
		vector<vector<int>>& result,
		int start)
	{
		if (target == 0)
		{
			result.push_back(currentCombination);
		}

		for (int i = start; i < candidates.size(); ++i)
		{
			if (candidates[i] > target)
			{
				break;
			}
			currentCombination.push_back(candidates[i]);
			backtrack(candidates, target - candidates[i], currentCombination, result, i);
			// Backtrack the current combination once we're done checking all combinations
			currentCombination.pop_back();
		}
	}
};
