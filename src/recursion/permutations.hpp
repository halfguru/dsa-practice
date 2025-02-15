// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any
// order.

#include <vector>

using namespace std;

// Backtracking
// 1. choose element to add to current permutation
// 2. explore recursively
// 3. unchoose after exploring
// time complexity: O(nxn!) n! permutations of n elements. for each permutation, we perform O(n) operations to add it to
// result list space complexity:
// space complexity: O(nxn!) n levels for n! permutations
class Solution_Permutations
{
public:
	void backtrack(vector<int>& nums, vector<vector<int>>& result, int start)
	{
		const int numSize = static_cast<int>(nums.size());

		if (start == numSize)
		{
			result.push_back(nums);
			return;
		}

		for (int i = start; i < numSize; ++i)
		{
			swap(nums[start], nums[i]);
			backtrack(nums, result, start + 1);
			swap(nums[start], nums[i]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> result;
		backtrack(nums, result, 0);
		return result;
	}
};
