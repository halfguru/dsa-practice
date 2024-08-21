// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
// and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
// newInterval = [start, end] that represents the start and end of another interval.
//
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals
// still does not have any overlapping intervals (merge overlapping intervals if necessary).
//
// Return intervals after the insertion.
//
// Note that you don't need to modify intervals in-place. You can make a new array and return it.

#include <vector>

using namespace std;

// e.g. [[1,3], [6,9]] and newInterval = [2, 5]
// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		vector<vector<int>> result;

		int i = 0;
		int n = intervals.size();

		// case 1: add all intervals before new interval
		while (i < n && intervals[i][1] < newInterval[0])
		{
			result.push_back(intervals[i]);
			i++;
		}

		// case 2: merge overlapping intervals with new interval
		while (i < n && intervals[i][0] <= newInterval[1])
		{
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			i++;
		}

		// add merged newInterval to the result
		result.push_back(newInterval);

		// case 3: add all intervals after new interval
		while (i < n)
		{
			result.push_back(intervals[i]);
			i++;
		}

		return result;
	}
};
