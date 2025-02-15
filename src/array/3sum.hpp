// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j !=
// k, and nums[i] + nums[j] + nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.

#include <algorithm>
#include <vector>

using namespace std;

// time complexity: O(n^2) for traversal
// space complexity: O(logn) + O(k) sorting algo for stack and k unique triplets found
class Solution_3Sum
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;

		// 1. Sort the array
		sort(nums.begin(), nums.end());

		// 2. iterate through array
		for (size_t i = 0; i < nums.size(); ++i)
		{
			// skip duplicate
			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}

			// 3. two pointer approach
			size_t left = i + 1;
			size_t right = nums.size() - 1;

			while (left < right)
			{
				const int sum = nums[i] + nums[left] + nums[right];

				if (sum == 0)
				{
					result.push_back({nums[i], nums[left], nums[right]});

					// move left pointer and skip duplicate
					while (left < right && nums[left] == nums[left + 1])
					{
						left++;
					}
					left++;

					// move right pointer and skip duplicate
					while (left < right && nums[right] == nums[right - 1])
					{
						right--;
					}
					right--;
				}
				else if (sum < 0)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}

		return result;
	}
};
