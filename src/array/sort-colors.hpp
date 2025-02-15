// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color
// are adjacent, with the colors in the order red, white, and blue.
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
// You must solve this problem without using the library's sort function.

#include <vector>

using namespace std;

// red, white blue
// 0, 1, 2
// time complexity: O(n)
// space complexity: O(1)
class Solution_SortColors
{
public:
	void sortColors(vector<int>& nums)
	{
		// red
		int low = 0;
		// traverse array
		size_t mid = 0;
		// start of blue
		size_t high = nums.size() - 1;

		while (mid <= high)
		{
			if (nums[mid] == 0)
			{
				swap(nums[low], nums[mid]);
				low++;
				mid++;
			}
			else if (nums[mid] == 1)
			{
				mid++;
			}
			else
			{
				swap(nums[mid], nums[high]);
				high--;
			}
		}
	}
};
