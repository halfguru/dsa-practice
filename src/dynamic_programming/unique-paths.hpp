// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The
// robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or
// right at any point in time.
//
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the
// bottom-right corner.
//
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <vector>

using namespace std;

// dp[i][j] represent the number of unique paths to reach the cell (i, j)
// to reach cell[i][j] you can either come from the cell directly above it i - 1
// or left of it j - 1. Therefore, the number of unique paths to reach (i, j) is
// sum of paths to reach the cell above and left of it
// dp[i][j] = dp[i - 1][j] + dp[i][j-1]
// time: O(m * n) grid
// space: O(m * n) dp table
class Solution_UniquePaths
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
