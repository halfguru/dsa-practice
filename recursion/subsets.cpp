// Given an integer array nums of unique elements, return all possible subsets (the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <vector>

using namespace std;

// Backtracking
// time: O(2^n) where n is number of elements
// space: O(2^n) for space needed to store all subsets
class Solution
{
public:
	void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int start)
	{
		result.push_back(subset);

		for (int i = start; i < nums.size(); ++i)
		{
			subset.push_back(nums[i]);
			backtrack(nums, result, subset, i + 1);
			subset.pop_back(); // backtrack
		}
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> result;
		vector<int> subset;
		backtrack(nums, result, subset, 0);
		return result;
	}
};
