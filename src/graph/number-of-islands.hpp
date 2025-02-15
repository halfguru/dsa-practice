// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of
// islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may
// assume all four edges of the grid are all surrounded by water.

#include <queue>
#include <vector>


using namespace std;

// BFS
// Time complexity: O(m * n)
// Space complexity: O(min(m, n))
class Solution_NumberOfIslands
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if (grid.empty() || grid[0].empty())
		{
			return 0;
		}

		int numIslands = 0;
		const int m = static_cast<int>(grid.size());
		const int n = static_cast<int>(grid[0].size());
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		queue<pair<int, int>> q;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == '1')
				{
					numIslands++;
					q.push({i, j});

					while (!q.empty())
					{
						const auto [x, y] = q.front();
						q.pop();

						if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
						{
							continue;
						}

						// mark as visited
						grid[x][y] = '0';

						for (const auto& dir: directions)
						{
							const int nx = x + dir.first;
							const int ny = y + dir.second;
							if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1')
							{
								q.push({nx, ny});
							}
						}
					}
				}
			}
		}
		return numIslands;
	}
};
