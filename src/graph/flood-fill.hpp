// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the
// pixel image[sr][sc].
//
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel
// of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the
// same color), and so on. Replace the color of all of the aforementioned pixels with color.
//
// Return the modified image after performing the flood fill.

#include <vector>

using namespace std;

// DFS
// Time complexity: O(mxn) number of rows times number of columns. Worst case scenario is we visit every pixel
// Space complexity: O(mxn) we could recurse to every pixel
class Solution_FloodFill
{
public:
	void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int color)
	{
		if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldColor
			|| image[sr][sc] == color)
		{
			return;
		}

		image[sr][sc] = color;
		dfs(image, sr - 1, sc, oldColor, color);
		dfs(image, sr + 1, sc, oldColor, color);
		dfs(image, sr, sc - 1, oldColor, color);
		dfs(image, sr, sc + 1, oldColor, color);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
	{
		const int oldColor = image[sr][sc];
		dfs(image, sr, sc, oldColor, color);
		return image;
	}
};
