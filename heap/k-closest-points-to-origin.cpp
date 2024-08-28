// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the
// k closest points to the origin (0, 0).
//
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
//
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

#include <queue>
#include <vector>

using namespace std;

// Use Max Heap approach
// iterate each point in array
// - calculate square distance of point from origin
// - push point along negative square distance into max-heap
// - if heap size exceeds K, remove element with largest distance
// time complexity: O(N log K) for each point n, push point into heap taking O(logK)
// space complexity: O(k) k points in heap

class Solution
{
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
	{
		priority_queue<pair<int, pair<int, int>>> maxHeap;

		for (const auto& point: points)
		{
			const int x = point[0];
			const int y = point[1];
			const int dist = x * x + y * y; // squared distance from origin

			// push current point with its squared distance to max heap
			maxHeap.push({dist, {x, y}});

			// if heap size exceeds K, pop largest element (farthest point)
			if (maxHeap.size() > k)
			{
				maxHeap.pop();
			}
		}

		// extract K closest poins from heap
		vector<vector<int>> result;
		while (!maxHeap.empty())
		{
			const auto point = maxHeap.top().second;
			maxHeap.pop();
			result.push_back({point.first, point.second});
		}

		return result;
	}
};
