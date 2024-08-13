/*
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target. You may assume that each input
 * would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

#include <unordered_map>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target) {}
};

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		std::unordered_map<int, int> mapping;
		const size_t numSize = nums.size();
		for (size_t i = 0; i < numSize; ++i)
		{
			mapping[nums[i]] = i;
		}

		for (int i = 0; i < numSize; i++)
		{
			const int complement = target - nums[i];
			if (mapping.count(complement) && mapping.at(complement) != i)
			{
				return {mapping.at(complement), i};
			}
		}
		return {};
	}
};
