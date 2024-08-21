// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of
// the ith line are (i, 0) and (i, height[i]).
//
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
//
// Return the maximum amount of water a container can store.
//
// Notice that you may not slant the container.

#include <vector>

using namespace std;

// time complexity: O(n)
// space complexity: O(1)
class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		// area is height[i] * i
		int maxArea = 0;
		int start = 0;
		int end = height.size() - 1;

		while (start <= end)
		{
			int currentArea = min(height[start], height[end]) * (end - start);
			maxArea = max(maxArea, currentArea);

			if (height[start] < height[end])
			{
				start++;
			}
			else
			{
				end--;
			}
		}

		return maxArea;
	}
};
