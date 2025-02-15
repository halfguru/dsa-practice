// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array
// of the non-overlapping intervals that cover all the intervals in the input.

#include <algorithm>
#include <vector>

using namespace std;

// time complexity: O(nlogn) for sorting and merge is O(n)
// space complexity: O(n) merged intervals
class Solution_MergeInterval
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		if (intervals.empty())
		{
			return {};
		}

		sort(intervals.begin(), intervals.end());

		vector<vector<int>> result;
		result.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); ++i)
		{
			vector<int>& lastInterval = result.back();

			// current interval overlaps last merged intervals
			// (1, 4), (2, 3)
			// if 1 <= 3
			// 3 = 4
			if (intervals[i][0] <= lastInterval[1])
			{
				lastInterval[1] = max(lastInterval[1], intervals[i][1]);
			}
			else
			{
				result.push_back(intervals[i]);
			}
		}

		return result;
	}
};
