// You are given an integer array coins representing coins of different denominations and an integer amount representing
// a total amount of money.
//
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by
// any combination of the coins, return -1.
//
// You may assume that you have an infinite number of each kind of coin.

#include <vector>

using namespace std;

// DP array where dp[i] is minimum number of coins to make up amount i
// update dp[j] at minimum value of itself or dp[j-coin] + 1
// time: O(nxm) amount * coins
// space: O(n) where n is amount for vector dp
class Solution_CoinChange
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0; // base case: 0 coins needed

		for (int i = 1; i <= amount; ++i)
		{
			for (const int& coin: coins)
			{
				// amount > coin amount precondition
				// eg. coin = 1, amount = 2
				// i = 1, coin = 1, dp[i - coin] = dp[0]. dp[1] = min(dp[1], dp[0] + 1) = min(MAX, 1) = 1
				// i = 2, coin = 1, dp[i - coin] = dp[1]. dp[2] = min(dp[2], dp[1] + 1)= min(MAX, 2) = 2
				if (i >= coin && dp[i - coin] != INT_MAX)
				{
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}

		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
};
