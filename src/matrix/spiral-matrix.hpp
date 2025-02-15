// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <vector>

using namespace std;

// time complexity: O(mxn) m and n rows columns
// space complexity: O(1)
class Solution_SpiralMatrix
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> result;
		if (matrix.empty())
		{
			return result;
		}

		int top = 0;
		int bottom = static_cast<int>(matrix.size() - 1);
		int left = 0;
		int right = static_cast<int>(matrix[0].size() - 1);

		while (top <= bottom && left <= right)
		{
			// travers from left to right along top row
			for (int i = left; i <= right; ++i)
			{
				result.push_back(matrix[top][i]);
			}
			top++; // move down to next row

			// traverse from top to bottom along right column
			for (int i = top; i <= bottom; ++i)
			{
				result.push_back(matrix[i][right]);
			}
			right--; // move left to next column
			// traverse from right to left along the bottom row, if possible
			if (top <= bottom)
			{
				for (int i = right; i >= left; --i)
				{
					result.push_back(matrix[bottom][i]);
				}
				bottom--; // move up to previous row
			}
			// traverse from bottom to top along left column, if possible
			if (left <= right)
			{
				for (int i = bottom; i >= top; --i)
				{
					result.push_back(matrix[i][left]);
				}
				left++; // move right to next column
			}
		}
		return result;
	}
};
