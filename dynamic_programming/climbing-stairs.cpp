// You are climbing a staircase. It takes n steps to reach the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// similar to fibonaci
// dp[i] number of ways to reach ith step
// dp[i] = dp[i - 1] + dp[i - 2]
// time: O(n)
// space: O(1)
class Solution
{
public:
	int climbStairs(int n)
	{
		if (n == 1)
		{
			return 1;
		}

		// base cases dp[0] dp[1]
		int first = 1;	// dp[0],
		int second = 1; // dp[1]
		int current;

		for (int i = 2; i <= n; ++i)
		{
			current = first + second;
			first = second;
			second = current;
		}

		return second; // dp[n]
	}
};
