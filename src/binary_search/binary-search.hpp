// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search
// target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

#include <vector>

using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
class Solution_BinarySearch
{
public:
	int search(vector<int>& nums, int target)
	{
		int start = 0;
		int end = static_cast<int>(nums.size() - 1);

		while (start <= end)
		{
			const int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return -1;
	}
};
