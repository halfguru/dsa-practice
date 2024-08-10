// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
// vertically neighboring. The same letter cell may not be used more than once.

#include <string>
#include <vector>


using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		const int m = board.size();
		const int n = board[0].size();

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dfs(board, word, i, j, 0))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool dfs(vector<vector<char>>& board, string word, int row, int col, int index)
	{
		// word completed
		if (index == word.size())
		{
			return true;
		}

		if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
		{
			return false;
		}

		const char temp = board[row][col];
		board[row][col] = '*'; // mark as visited

		// explore four neighboring directions
		vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for (const auto& direction: directions)
		{
			const int nx = row + direction.first;
			const int ny = col + direction.second;

			if (dfs(board, word, nx, ny, index + 1))
			{
				return true;
			}
		}

		board[row][col] = temp;
		return false;
	}
};
