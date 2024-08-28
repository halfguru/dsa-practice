// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return
// the area of the largest rectangle in the histogram.

#include <stack>
#include <vector>

using namespace std;

// Stack to maintain indices of the bars
// Find smallest bar that limits the width of the rectangle for each bar, left and right
// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		stack<int> st;
		int maxArea = 0;
		int n = heights.size();

		for (int i = 0; i < n; ++i)
		{
			// stack store indices of the bars in increasing order of heights
			// current bar shorter than bar on top of stack, pop top of stack
			// and calculate area of rectangle with popped bar as the shortest bar
			while (!st.empty() && heights[i] < heights[st.top()])
			{
				const int h = heights[st.top()];
				st.pop();
				// width is is index of current bar minus index of rectangle in stack
				const int width = st.empty() ? i : i - st.top() - 1;
				maxArea = max(maxArea, h * width);
			}

			// current bar taller than bar on top of stack, push it
			st.push(i);
		}

		// handle remaining bars in stack
		while (!st.empty())
		{
			const int h = heights[st.top()];
			st.pop();
			const int width = st.empty() ? n : n - st.top() - 1;
			maxArea = max(maxArea, h * width);
		}

		return maxArea;
	}
};
