// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the
// elements in both subsets is equal or false otherwise.

#include <numeric>
#include <vector>

using namespace std;

// calculate total sum of array
// if total is odd, its impossible to partition into two equal subset
// target is sum / 2
// check if subset == target
// dp[i] indicates if subset with sum "i" can be achieved
// initialize dp[0] to true
// time: O(n*target) for each number, we iterate over range from target to number value
// space: O(target) dp array of size target
class Solution_PartitionEqualSubsetSum
{
public:
	bool canPartition(vector<int>& nums)
	{
		const int totalSum = accumulate(nums.begin(), nums.end(), 0);

		// check if totalSum is odd
		if (totalSum % 2 != 0)
		{
			return false;
		}

		const int target = totalSum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;

		// e.g nums = [1, 2, 3]
		// target = 3
		// dp = [true, false, false, false, false]
		// process num = 1
		// update dp[4] down to 1
		// dp[4] = dp[4] || do[3] (false || false = false)
		// dp[1] = dp[1] || dp[0] (false || true = true)
		for (const int& num: nums)
		{
			for (int i = target; i >= num; --i)
			{
				dp[i] = dp[i] || dp[i - num];
			}
		}

		return dp[target];
	}
};
