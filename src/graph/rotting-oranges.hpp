// You are given an m x n grid where each cell can have one of three values:
//
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return

#include <queue>
#include <vector>

using namespace std;

// Time complexity: O(m*n) quadratic
// Space complexity: O(m*n) quadratic
class Solution_RottingOranges
{
public:
	int orangesRotting(vector<vector<int>>& grid)
	{
		const int m = static_cast<int>(grid.size());
		const int n = static_cast<int>(grid[0].size());
		int minute = 0;
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
		queue<pair<int, int>> q;
		vector<vector<int>> graph(m, vector<int>(n, 0));
		int freshCount = 0;

		// initialize and find rotten oranges
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				// copy graph
				graph[i][j] = grid[i][j];
				// rotten orange
				if (grid[i][j] == 2)
				{
					q.push({i, j});
				}
				else if (graph[i][j] == 1)
				{
					freshCount++;
				}
			}
		}

		if (freshCount == 0)
		{
			return 0;
		}

		while (!q.empty())
		{
			const int size = static_cast<int>(q.size());
			bool rottenThisMinute = false;

			// iterate for each minute
			// so go through the whole queue for each minute
			for (int i = 0; i < size; ++i)
			{
				const auto [x, y] = q.front();
				q.pop();

				for (const auto& d: directions)
				{
					const int nx = x + d.first;
					const int ny = y + d.second;

					// find fresh orange adjacent
					if (nx >= 0 && ny >= 0 && nx < m && ny < n && graph[nx][ny] == 1)
					{
						// rotten orange becomes rotten
						graph[nx][ny] = 2;
						freshCount--;
						q.push({nx, ny});
						rottenThisMinute = true;
					}
				}
			}

			if (rottenThisMinute)
			{
				minute++;
			}
		}

		if (freshCount == 0)
		{
			return minute;
		}

		return -1;
	}
};
