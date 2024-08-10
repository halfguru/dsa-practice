// Given an m x n binary matrix mat, return the distance of the nearest 0 for
// each cell.
//
// The distance between two adjacent cells is 1.

#include <climits>
#include <queue>
#include <vector>

using namespace std;

// Time complexity: O(m * n) for bfs traversal
// Space compleixty: O(m * n) for queue and distance vector
// so quadratic complexity for both
class Solution
{
public:
	// use bfs because it explores neighbor level by level
	// dfs can lead to stack overflow and deep recursion due to size of matrix
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		// rows and columns
		const int m = mat.size();
		const int n = mat[0].size();
		// store coordinates to indicate the order of cells explored for BFS
		std::queue<std::pair<int, int>> q;
		// store the distance of each cell from nearest 0 in a binary matrix.
		// all distance are set to MAX at first to indicate they're not processed
		// yet
		std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));

		const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		// initialize distances and queue

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] == 0)
				{
					// distance of 0 for cell with 0
					dist[i][j] = 0;
					// push in queue for cell explored
					q.push({i, j});
				}
			}
		}

		// BFS
		while (!q.empty())
		{
			// explore queue until it's empty
			const auto [x, y] = q.front();
			q.pop();

			// for each dequeued cell, explore its four neighbors at 4 directions
			for (auto [dx, dy]: directions)
			{
				const int nx = x + dx;
				const int ny = y + dy;
				// check if new coordinates at nx and ny are within bounds of matrix
				if (nx >= 0 && nx < m && ny >= 0 && ny < n)
				{
					// if current distance is greater than distance of new cell, update neighbor distance
					// and enqueue the neighbor for further processing
					if (dist[nx][ny] > dist[x][y] + 1)
					{
						dist[nx][ny] = dist[x][y] + 1;
						q.push({nx, ny});
					}
				}
			}
		}
		return dist;
	}
};
