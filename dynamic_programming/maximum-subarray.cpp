// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <vector>

using namespace std;

// DP to store maximum subarray sum at each position in array
// 1. dp[i] is maximum sum of subarray ending at index i
// 2. initialize dp[0] at nums[0]
// 3. fill DP table where dp[i] is max of itself or itself + maximum sum ending at previous element dp[i - 1]
// 4. find maximum
// time: O(n)
// space: O(n)
class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		const int n = nums.size();
		if (n == 0)
		{
			return 0;
		}

		vector<int> dp(n);
		dp[0] = nums[0]; // initialize first element

		int maxGlobal = dp[0];

		for (int i = 1; i < n; ++i)
		{
			dp[i] = max(nums[i], dp[i - 1] + nums[i]); // max sum ending at index i
			maxGlobal = max(maxGlobal, dp[i]);		   // update global max
		}

		return maxGlobal;
	}
};
