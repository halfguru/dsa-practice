// There is an integer array nums sorted in ascending order (with distinct values).
//
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
// or -1 if it is not in nums.
//
// You must write an algorithm with O(log n) runtime complexity.

#include <vector>

using namespace std;

class Solution_SearchInRotatedSortedArray
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0;
		int right = static_cast<int>(nums.size() - 1);

		while (left <= right)
		{
			const int mid = left + (right - left) / 2;

			if (nums[mid] == target)
			{
				return mid;
			}

			// left side is sorted
			if (nums[left] <= nums[mid])
			{
				// target is in left sorted side
				if (nums[left] <= target && target < nums[mid])
				{
					right = mid - 1;
				}
				// target is in right unsorted side
				else
				{
					left = left + 1;
				}
			}
			else
			{
				// taret is in right sorted side
				if (nums[mid] <= target && target <= nums[right])
				{
					left = mid + 1;
				}
				// target is in left unsorted side
				else
				{
					right = mid - 1;
				}
			}
		}

		return -1;
	}
};
